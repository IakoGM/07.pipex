/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:18:09 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/21 19:45:15 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	int		fd[2];
	pid_t	pid;
	char *const args[] = {"/bin/ls", "-l", NULL};

	data.firstcommandpath = strdup("HolaComando");
	argc = 0;
	argv = NULL;

	pipe(fd);

	pid = fork();

	if (pid == 0)
	{
		puts("Soy el hijo");
		puts(data.firstcommandpath);
		close(fd[0]);
		// dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(args[0], args, envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[0]);
		close(fd[1]);
		puts("Soy el padre");
		puts(data.firstcommandpath);
		free(data.firstcommandpath);
		// free(data.firstcommandpath);
	}
	return 0;
}
