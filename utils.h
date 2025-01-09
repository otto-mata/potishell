/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   utils.h                                              ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 07:16:06 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 04:15:57 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "libft/libft.h"
int		index_of(char *s, char c);
char	*replace(char *in, char *sub, char *by);
void	free_2d(void **ptr);
void	error(char const *s);
#endif
