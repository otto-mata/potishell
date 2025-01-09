/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   utils.c                                              ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 07:16:43 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 04:15:52 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
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

char	*replace(char *in, char *sub, char *by)
{
	size_t	sub_sz;
	size_t	final_sz;
	char	*ret;
	char	*substart;

	if (!in || !sub)
		return (0);
	substart = ft_strstr(in, sub);
	if (!substart)
		return (ft_strdup(in));
	sub_sz = ft_strlen(sub);
	if (!by)
		by = "";
	final_sz = ft_strlen(in) - sub_sz + ft_strlen(by);
	ret = ft_calloc(final_sz + 1, sizeof(char));
	if (!ret)
		return (0);
	ft_strncpy(ret, in, (size_t)(substart - in));
	ft_strcat(ret, by);
	ft_strcat(ret, (char *)(substart + sub_sz));
	return (ret);
}

void	error(char const *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	free_2d(void **ptr)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (ptr[len++])
		;
	i = 0;
	while (i < len)
		free(ptr[i++]);
	free(ptr);
}
