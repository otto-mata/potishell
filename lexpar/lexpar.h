/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   lexpar.h                                             ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 03:03:29 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 05:45:26 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXPAR_H
# define LEXPAR_H
# include "../libft/libft.h"
# include "lexer_utils.h"

typedef enum e_toktype	t_token_type;
typedef struct s_token	t_token;

enum					e_toktype
{
	WORD = -1,
	GREAT = -2,
	LESS = -3,
	GREATGREAT = -4,
	LESSLESS = -5,
	PIPE = -6,
	OR = -7,
	AND = -8,
	WILDCARD = -9,
	VARIABLE = -10,
	INVALID = -11,
};

struct					s_token
{
	t_token_type		type;
	char*				text;
};

/**
 * @brief Split a null terminated string at each withespace, excepted between
 * quotes.
 * @param s Input string
 * @return Linked list representing the parts of the string,
 * NULL in case of error.
 */
t_list					*smart_split(char *s);

#endif