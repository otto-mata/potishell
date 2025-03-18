/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   join.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 16:16:16 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/17 15:49:42 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "va_internals.h"
#include <vecarr.h>

static void	*map_strlen(void *elem)
{
	return ((void *)ft_strlen((char *)elem));
}

static size_t	len_sum(t_vecarr *v)
{
	t_vecarr	*lenghts;
	size_t		sum;

	lenghts = va_map(v, map_strlen);
	if (!lenghts)
		return (0);
	sum = va_sum(lenghts);
	va_destroy(&lenghts);
	return (sum);
}

char	*va_join(t_vecarr *v, const char *sep)
{
	char	*joint;
	size_t	sz;
	long	i;

	sz = len_sum(v) + (v->len - 1) * om_strlen(sep) + 1;
	if (!sep)
		sep = "";
	joint = gc_calloc(1, sz * sizeof(char));
	if (!joint)
		return (0);
	joint[0] = 0;
	i = 0;
	while (i < v->len)
	{
		om_strcat(joint, (const char *)v->data[i]);
		if (i < v->len - 1)
			om_strcat(joint, sep);
		i++;
	}
	return (joint);
}
