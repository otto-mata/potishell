/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   literal_accumulator.c                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/17 10:17:41 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/18 09:54:05 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	acc_check(t_token_type type)
{
	return (type == SSTRING || type == DSTRING || type == LITERAL);
}

void	literal_accumulator(void)
{
	t_token_list	*it;
	t_token_list	*nx;
	char			*tmp;

	it = scanner()->tokens;
	while (it)
	{
		nx = it->next;
		while (nx && acc_check(it->tok->type))
		{
			if (acc_check(nx->tok->type))
			{
				tmp = ftgc_strjoin(it->tok->lexeme, nx->tok->lexeme);
				gc_free(nx->tok->lexeme);
				nx->tok->lexeme = 0;
				gc_free(it->tok->lexeme);
				it->tok->lexeme = tmp;
			}
			else
				break ;
			nx = nx->next;
		}
		it = nx;
	}
}
