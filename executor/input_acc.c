/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   input_acc.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/09 05:05:59 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:14:25 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	accumulate(t_simple_cmd *s_cmd, int *inpipe)
{
	int			i;
	int			fd;
	t_rredir	*in;
	int			*hdpipe;
	char		buffer[700000];

	i = -1;
	while (++i < s_cmd->ifc)
	{
		in = s_cmd->infiles[i];
		if (in->heredoc)
		{
			get_heredoc(in->heredoc_lim, hdpipe);
			fd = hdpipe[0];
		}
		else
			fd = open(in->from, O_RDONLY);
		while (read(fd, buffer, sizeof(buffer)))
			write(inpipe[1], buffer, sizeof(buffer));
	}
}
