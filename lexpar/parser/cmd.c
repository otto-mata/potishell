/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cmd.c                                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 06:40:18 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 20:31:17 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*command(void)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (0);
	cmd->allocd = 1;
	cmd->simple_cmds = ft_calloc(cmd->allocd, sizeof(t_simple_cmd *));
	if (!cmd->simple_cmds)
		return (free(cmd), (t_cmd *)0);
	return (cmd);
}

void	insert_simple_cmd(t_cmd *cmd, t_simple_cmd *simple_cmd)
{
	if (!cmd || !simple_cmd)
		return ;
	if (cmd->allocd <= cmd->cmdc + 1)
	{
		ft_realloc(cmd->simple_cmds, cmd->allocd * sizeof(t_simple_cmd *),
			(cmd->allocd + 1) * sizeof(t_simple_cmd *));
		cmd->allocd++;
	}
	cmd->simple_cmds[cmd->cmdc] = simple_cmd;
	cmd->cmdc++;
}
