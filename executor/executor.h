/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   executor.h                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/09 04:08:07 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:08:02 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "../lexpar/parser/parser.h"
# include "../utils.h"
# include <unistd.h>

typedef struct s_executor	t_executor;

struct						s_executor
{
	int						last_exit;
	t_cmd					*cmd;
	char					**envp;
};

void						exec(char *argv, char **envp, int *in_pipe,
								int *out_pipe);

#endif