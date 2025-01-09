/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   potishell.c                                          ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/09 02:30:49 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/09 03:02:08 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

void	pgrep_cmd(char **dest)
{
	dest[0] = "pgrep";
	dest[1] = "-f";
	dest[2] = "potishell";
	dest[3] = 0;
}

void    close_pipe(int *pfd)
{
        close(pfd[0]);
        close(pfd[1]);
}

void    dup_close(int *pfd, int target, int origin)
{
        if (dup2(origin, target) < 0)
			return ;
        close_pipe(pfd);
}

int	retrieve_selfpid(char **envp)
{
	int		link[2];
	pid_t	pid;
	char	buff[16];
	char	*pgrep[4];
	int		potishell_pid;

	if (pipe(link) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		dup_close(link, STDOUT_FILENO, link[1]);
		pgrep_cmd(pgrep);
		execve("/usr/bin/pgrep", (char *const *)pgrep, envp);
	}
	else
	{
		close(link[1]);
		read(link[0], buff, sizeof(buff));
		potishell_pid = atoi(buff);
		wait(NULL);
	}
	return (potishell_pid);
}

int main(int ac, char **av, char** envp)
{
	printf("PID: %d\n",retrieve_selfpid(envp));
}