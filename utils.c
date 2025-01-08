/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   utils.c                                              ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 07:16:43 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 07:16:52 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	index_of(char *s, char c)
{
	char	*match;

	match = ft_strchr(s, c);
	if (!match)
		return (-1);
	return ((int)(match - s));
}