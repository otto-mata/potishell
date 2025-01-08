/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 08:33:28 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 23:12:27 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "lexpar/lexer/lexer.h"
#include "lexpar/parser/parser.h"
#include "libft/libft.h"
#include <fcntl.h>

static int	is_redir(t_token_type toktype)
{
	return (toktype == LESS || toktype == LESSLESS || toktype == GREAT
		|| toktype == GREATGREAT);
}

static int	is_cmd_separator(t_token_type toktype)
{
	return (toktype == PIPE);
}

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
		if (is_redir(curr->type))
		{
			if (curr->type == GREAT || curr->type == GREATGREAT)
				insert_outfile(s_cmd,
					((t_token *)(*tokens)->next->content)->text,
					curr->type == GREATGREAT);
			else
				insert_infile(s_cmd,
					((t_token *)(*tokens)->next->content)->text,
					curr->type == LESSLESS);
			(*tokens) = (*tokens)->next;
		}
		else if (curr->type == WORD)
			insert_argument(s_cmd, curr->text);
		else if (is_cmd_separator(curr->type))
			break ;
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
		// ft_printf("%s %s\n", str_token_type(curr->type), curr->text);
		tok = tok->next;
	}
	tok = head;
	while (tok)
	{
		curr = (t_token *)tok->content;
		s_cmd = 0;
		if (!is_cmd_separator(curr->type))
			s_cmd = simple_command_from_tokens(&tok);
		if (!s_cmd)
			tok = tok->next;
		insert_simple_cmd(cmd, s_cmd);
	}
	for (i = 0; i < cmd->cmdc; i++)
	{
		s_cmd = cmd->simple_cmds[i];
		ft_printf("Command: ");
		for (j = 0; j < s_cmd->argc; j++)
		{
			ft_printf("%s ", s_cmd->argv[j]);
		}
		ft_printf("\n");
		if (s_cmd->ifc)
		{
			ft_printf("Aggregating input from: ");
			for (j = 0; j < s_cmd->ifc; j++)
			{
				if (s_cmd->infiles[j]->from)
					ft_printf("%s ", s_cmd->infiles[j]->from);
				else 
					ft_printf("heredoc(%s) ", s_cmd->infiles[j]->heredoc_lim);
			}
		ft_printf("\n");
		}
		if (s_cmd->ofc)
		{
			ft_printf("Outputing to: ");
			for (j = 0; j < s_cmd->ofc; j++)
			{
				ft_printf("%s (%s) ", s_cmd->outfiles[j]->to, s_cmd->outfiles[j]->mode ? "APPEND" : "WRITE");
			}
		ft_printf("\n");
		}
		ft_printf("\n");
	}
	ft_lstclear(&head, free_token_list);
	return (0);
}
