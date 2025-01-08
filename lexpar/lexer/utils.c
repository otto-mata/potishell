/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   utils.c                                              ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 04:43:45 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 08:34:23 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_utils.h"

void	set_quote_state(char c, int *state)
{
	if (c == '"')
	{
		if (*state == 0)
			*state = 1;
		else if (*state == 1)
			*state = 0;
	}
	else if (c == '\'')
	{
		if (*state == 0)
			*state = 2;
		else if (*state == 2)
			*state = 0;
	}
}

char	*str_token_type(int type)
{
	if (type == -1)
		return ("WORD");
	if (type == -2)
		return ("GREAT");
	if (type == -3)
		return ("LESS");
	if (type == -4)
		return ("GREATGREAT");
	if (type == -5)
		return ("LESSLESS");
	if (type == -6)
		return ("PIPE");
	if (type == -7)
		return ("OR");
	if (type == -8)
		return ("AND");
	if (type == -9)
		return ("WILDCARD");
	if (type == -10)
		return ("VARIABLE");
	return ("INVALID");
}
