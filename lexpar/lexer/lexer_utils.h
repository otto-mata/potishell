/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   lexer_utils.h                                        ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 04:45:24 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 07:16:39 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_UTILS_H
# define LEXER_UTILS_H
# include "../../libft/libft.h"
# include "../../utils.h"
void	set_quote_state(char c, int *state);
char	*str_token_type(int type);
#endif