/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   simple_cmd.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 06:28:23 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 06:39:36 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_simple_cmd	*simple_command(void)
{
	t_simple_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_simple_cmd));
	if (!cmd)
		return (0);
	cmd->argc = 0;
	cmd->allocd = 1;
	cmd->argv = ft_calloc(cmd->allocd, sizeof(char *));
	if (!cmd->argv)
		return (free(cmd), (t_simple_cmd *)0);
	return (cmd);
}

void	insert_argument(t_simple_cmd *cmd, char *arg)
{
	if (!cmd || !arg)
		return ;
	if (cmd->allocd <= cmd->argc + 1)
	{
		ft_realloc(cmd->argv, cmd->allocd * sizeof(char *), (cmd->allocd + 1)
			* sizeof(char *));
		cmd->allocd++;
	}
	cmd->argv[cmd->argc] = arg;
	cmd->argc++;
}