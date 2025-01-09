/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   exec_utils.c                                         ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/09 04:14:22 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 05:02:57 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	*value_of(char *dict[], char *key)
{
	char	**d2;
	size_t	key_len;

	if (!key || !dict)
		return (0);
	d2 = dict;
	key_len = ft_strlen(key);
	while (*d2)
	{
		if (ft_strncmp(key, *d2, key_len) == 0 && (*d2)[key_len] == '=')
			return (*d2 + key_len + 1);
		d2++;
	}
	return (0);
}

char	*command_full_path(char const *cmd, char **paths)
{
	char	*try_path;
	char	**p;
	char	*tmp;

	if (!paths)
		return (0);
	p = paths;
	while (*p)
	{
		tmp = ft_strjoin((char const *)*p, "/");
		if (!tmp)
			break ;
		try_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!try_path)
			break ;
		if (access(try_path, X_OK))
			free(try_path);
		else
			return (try_path);
		p++;
	}
	return (free_2d((void **)paths), (void *)0);
}

void	exec(char *argv, char **envp, int *in_pipe, int *out_pipe)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = command_full_path(cmd[0], ft_split(value_of(envp, "PATH"), ':'));
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error("cmd");
	}
	if (execve(path, cmd, envp) == -1)
		error("exec");
}
