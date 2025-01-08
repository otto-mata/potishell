/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parser.h                                             ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 06:24:25 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 10:07:08 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../../libft/libft.h"
# include "../lexer/lexer.h"
# include "parser_utils.h"

typedef struct s_simple_cmd	t_simple_cmd;
typedef struct s_cmd		t_cmd;
typedef struct s_wredir		t_wredir;
typedef struct s_rredir		t_rredir;
typedef enum e_infile_mode	t_infile_mode;

enum						e_infile_mode
{
	FILE = 0,
	HEREDOC,
};

struct						s_simple_cmd
{
	int						allocd;
	int						argc;
	char					**argv;
};

struct						s_wredir
{
	char					*to;
	int						mode;
};

struct						s_rredir
{
	char					*from;
	t_infile_mode			mode;
	int						heredoc;
	char					*heredoc_lim;
};

struct						s_cmd
{
	int						allocd;
	int						cmdc;
	int						of_allocd;
	int						ofc;
	int						if_allocd;
	int						ifc;
	t_wredir				**outfiles;
	t_rredir				**infiles;
	t_simple_cmd			**simple_cmds;
	t_simple_cmd			*current_cmd;
};

t_simple_cmd				*simple_command(void);
void						insert_argument(t_simple_cmd *cmd, char *arg);

t_cmd						*command(void);
void						insert_simple_cmd(t_cmd *cmd,
								t_simple_cmd *simple_cmd);
void						expand_tokens(t_list *tokens);

void						insert_infile(t_cmd *cmd, char *file,
								int is_heredoc);
void						insert_outfile(t_cmd *cmd, char *file, int wmode);
#endif