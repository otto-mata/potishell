/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parser.h                                             ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 06:24:25 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 08:35:28 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../../libft/libft.h"
# include "../lexer/lexer.h"
# include "parser_utils.h"

typedef struct s_simple_cmd	t_simple_cmd;
typedef struct s_cmd		t_cmd;

struct						s_simple_cmd
{
	int						allocd;
	int						argc;
	char					**argv;
};

struct						s_cmd
{
	int						allocd;
	int						cmdc;
	char					*outfile;
	char					*infile;
	t_simple_cmd			**simple_cmds;
	t_simple_cmd			*current_cmd;
};

t_simple_cmd				*simple_command(void);
void						insert_argument(t_simple_cmd *cmd, char *arg);

t_cmd						*command(void);
void						insert_simple_cmd(t_cmd *cmd,
								t_simple_cmd *simple_cmd);
void						expand_tokens(t_list *tokens);
#endif