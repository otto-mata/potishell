/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   otto_min.c                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/22 09:14:40 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:51:56 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

size_t	otto_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
