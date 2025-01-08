/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 08:33:28 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 10:44:35 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "lexpar/lexer/lexer.h"
#include "lexpar/parser/parser.h"
#include "libft/libft.h"
#include <fcntl.h>

t_simple_cmd	*simple_command_from_tokens(t_list **tokens)
{
	t_token			*curr;
	t_simple_cmd	*s_cmd;

	if (!tokens || !*tokens)
		return (0);
	s_cmd = simple_command();
	if (!s_cmd)
		return (0);
	while (*tokens)
	{
		curr = (t_token *)(*tokens)->content;
		if (curr->type != WORD)
			break ;
		insert_argument(s_cmd, curr->text);
		(*tokens) = (*tokens)->next;
	}
	return (s_cmd);
}
/*
Faire une fonction pour retirer les noeuds de redirections apres avoir
correctement set les parametres dans le t_cmd.
SI plusieurs redirections inward
ALORS
	Agreger ensemble les contenus, dans l'ordre des redirections
	i.e. <file0 <<EOF cat <file1 <file2 donnera
	<contenu file0><contenu heredoc><contenu file1><contenu file2>
SI plusieurs redirections outward
ALORS
	Les fichiers vises seront tous utilises en sorti
	i.e. cat hello.txt >out0 >out1 >>out2 ecrira
	WRITE out0 <contenu hello.txt>
	WRITE out1 <contenu hello.txt>
	APPEND out2 <contenu hello.txt>
Les mix des deux doivent se comporter comme attendu
i.e. <file0 <file1 cat >out0 >out1 ecrira
	WRITE out0 <contenu file0><contenu file1>
	WRITE out1 <contenu file0><contenu file1>

*/


int	main(int argc, char **argv)
{
	t_list			*tok;
	t_list			*head;
	t_token			*curr;
	t_cmd			*cmd;
	t_simple_cmd	*s_cmd;
	char			*raw;
	int				i;
	int				wmode;
	int				j;

	if (argc < 2)
		raw = "ls -al a* | grep me >> outfile";
	else
		raw = argv[1];
	ft_printf("Parsing command: %s\n", raw);
	tok = tokenize(raw);
	expand_tokens(tok);
	head = tok;
	cmd = command();
	while (tok)
	{
		curr = (t_token *)tok->content;
		s_cmd = 0;
		if (curr->type == WORD)
			s_cmd = simple_command_from_tokens(&tok);
		else if (curr->type == GREAT || curr->type == GREATGREAT)
		{
			wmode = O_WRONLY;
			if (curr->type == GREATGREAT)
				wmode = O_WRONLY | O_APPEND;
			insert_outfile(cmd, ((t_token *)(tok->next->content))->text, wmode);
			tok = tok->next;
		}
		else if (curr->type == LESS || curr->type == LESSLESS)
			insert_infile(cmd, ((t_token *)(tok->next->content))->text,
				curr->type == LESSLESS);
		if (!s_cmd)
			tok = tok->next;
		insert_simple_cmd(cmd, s_cmd);
	}
	for (i = 0; i < cmd->cmdc; i++)
	{
		s_cmd = cmd->simple_cmds[i];
		ft_printf("SIMPLE COMMAND ");
		for (j = 0; j < s_cmd->argc; j++)
		{
			ft_printf("%s ", s_cmd->argv[j]);
		}
		if (i < cmd->cmdc - 1)
			ft_printf("PIPING INTO");
		ft_printf("\n");
	}
	ft_printf("REDIRECTIONS: ");
	for (i = 0; i < cmd->ofc; i++)
	{
		ft_printf("%s: %d, ", cmd->outfiles[i]->to, cmd->outfiles[i]->mode);
	}
	ft_printf("\n");
	ft_lstclear(&head, free_token_list);
	return (0);
}
