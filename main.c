/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 08:33:28 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 08:36:35 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "lexpar/lexer/lexer.h"
#include "lexpar/parser/parser.h"

int	main(int argc, char **argv)
{
	t_list	*tok;
	t_list	*head;
	t_token	*curr;
	char	*raw;

	if (argc < 2)
		raw = "ls -al a* | grep me >> outfile";
	else
		raw = argv[1];
	tok = tokenize(raw);
	expand_tokens(tok);
	head = tok;
	while (tok)
	{
		curr = (t_token *)tok->content;
		ft_printf("%s %s\n", str_token_type(curr->type), curr->text ? curr->text : "");
		tok = tok->next;
	}
	ft_lstclear(&head, free_token_list);
	return (0);
}