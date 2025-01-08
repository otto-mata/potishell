/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   simple_cmd.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/08 06:28:23 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/08 23:05:59 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
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
	cmd->of_allocd = 1;
	cmd->outfiles = ft_calloc(cmd->of_allocd, sizeof(t_wredir *));
	if (!cmd->outfiles)
		return (free(cmd->argv), free(cmd), (t_simple_cmd *)0);
	cmd->if_allocd = 1;
	cmd->infiles = ft_calloc(cmd->of_allocd, sizeof(t_rredir *));
	if (!cmd->infiles)
		return (free(cmd->outfiles), free(cmd->argv), free(cmd),
			(t_simple_cmd *)0);
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

void	insert_outfile(t_simple_cmd *cmd, char *file, int wmode)
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

void	insert_infile(t_simple_cmd *cmd, char *file, int is_heredoc)
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
