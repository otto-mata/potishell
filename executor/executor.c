/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   executor.c                                           ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/09 04:07:23 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:05:46 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

t_executor	*executor(void)
{
	t_executor	*executor;

	executor = ft_calloc(1, sizeof(t_executor));
	if (!executor)
		return (0);
	return (executor);
}

int set_envp(t_executor *exc, char **envp)
{
	if (!exc || !envp)
		return (-1);
	exc->envp = envp;
	return (0);
}

int	register_cmd(t_executor *exc, t_cmd *cmd)
{
	if (!exc || !cmd)
		return (-1);
	exc->cmd = cmd;
	return (0);
}

int	execute(t_executor *exc)
{
	t_cmd			*cmd;
	t_simple_cmd	*s_cmd;
	int				i;
	if (!exc)
		return (-1);
	if (!exc->cmd)
		return (-1);
	cmd = exc->cmd;
	i = -1;
	while (++i < cmd->cmdc)
	{
		s_cmd = cmd->simple_cmds[i];
		exec(s_cmd->argv, exc->envp)
	}	
}
