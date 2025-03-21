/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   pop.c                                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/03/08 17:35:07 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/03/08 18:45:48 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include <vecarr.h>
#include "va_internals.h"

void	va_pop(t_vecarr *v)
{
	va_delete(v, v->len - 1);
}
