/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   group_expressions.c                                  ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/18 09:59:07 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 16:32:02 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	has_paren(t_token_list *lst)
{
	while (lst)
	{
		if (lst->tok->type == LEFT_PAREN)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	insert_parens(t_token_list *tlst)
{
	const int		general_group = !has_paren(tlst);
	t_token_list	*iter;

	iter = tlst;
	if (!general_group)
		return (0);
	while (iter)
	{
		
		iter = iter->next;
	}
}
