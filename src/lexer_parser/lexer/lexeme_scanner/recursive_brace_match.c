/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   recursive_brace_match.c                              ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/18 07:35:06 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 10:20:43 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <vecarr.h>

int	check_match(t_token_list *lst)
{
	if (!lst)
		return (1);
	while (lst)
	{
		if (lst->tok->type == LEFT_PAREN || lst->tok->type == RIGHT_PAREN)
		{
			if (!lst->match)
			{
				lex_error("Unmatched parenthese", lst->tok->line,
					lst->tok->pos);
				return (0);
			}
		}
		lst = lst->next;
	}
	return (1);
}

t_token_list	*rec(t_token_list *lst)
{
	t_token_list	*iter;

	if (!lst)
		return (0);
	iter = lst->next;
	while (iter)
	{
		if (iter->tok->type == LEFT_PAREN)
		{
			iter = rec(iter);
		}
		else if (iter->tok->type == RIGHT_PAREN)
		{
			lst->match = iter;
			iter->match = lst;
			return (iter);
		}
		if (iter)
			iter = iter->next;
	}
	return (0);
}

int	group_braces(t_token_list *lst)
{
	t_token_list	*iter;

	iter = lst;
	while (iter && iter->tok->type != LEFT_PAREN)
		iter = iter->next;
	rec(iter);
	return (check_match(lst));
}
