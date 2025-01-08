/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cmd.c                                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 06:40:18 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 10:10:37 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
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
	cmd->of_allocd = 1;
	cmd->outfiles = ft_calloc(cmd->of_allocd, sizeof(t_wredir *));
	cmd->if_allocd = 1;
	cmd->infiles = ft_calloc(cmd->of_allocd, sizeof(t_rredir *));
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

void	insert_outfile(t_cmd *cmd, char *file, int wmode)
{
	t_wredir	*redir;
	
	if (!cmd || !file)
		return ;
	redir = ft_calloc(1, sizeof(t_wredir));
	if (!redir)
		return ;
	if (cmd->of_allocd <= cmd->ofc + 1)
	{
		ft_realloc(cmd->outfiles, cmd->of_allocd * sizeof(t_wredir *),
			(cmd->of_allocd + 1) * sizeof(t_wredir *));
		cmd->of_allocd++;
	}
	redir->mode = wmode;
	redir->to = file;
	cmd->outfiles[cmd->ofc] = redir;
	cmd->ofc++;
}

void	insert_infile(t_cmd *cmd, char *file, int is_heredoc)
{
	t_rredir	*redir;
	
	if (!cmd || !file)
		return ;
	redir = ft_calloc(1, sizeof(t_rredir));
	if (!redir)
		return ;
	if (cmd->if_allocd <= cmd->ifc + 1)
	{
		ft_realloc(cmd->infiles, cmd->if_allocd * sizeof(t_rredir *),
			(cmd->if_allocd + 1) * sizeof(t_rredir *));
		cmd->if_allocd++;
	}
	if (is_heredoc)
		redir->heredoc_lim = file;
	else
		redir->from = file;
	redir->mode = is_heredoc;
	cmd->infiles[cmd->ifc] = redir;
	cmd->ifc++;
}
