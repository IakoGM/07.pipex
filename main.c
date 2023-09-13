/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:48:36 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/12 15:15:34 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
	int fd_infile;
	int fd_outfile;
	char *buffer;
	int fd[2];
	int pid;
	int status;
	char *const args[] = {"/bin/ls", "-l", NULL};
	char *const envp[] = {NULL};

	fd_infile = open("infile.txt", O_RDONLY);
	fd_outfile = open("outfile.txt", O_CREAT | O_WRONLY, 0644);
	pipe(fd);
	// Fork devuelve process id 0 para el proceso hijo
	pid = fork();

	if (pid == 0)
	{
		dup2(fd_infile, STDIN_FILENO);
		// close(fd_infile);
		printf("Child process\n");
		execve(args[0], args, envp);
	}
	read(fd_outfile, &buffer, sizeof(buffer));
	write(fd_outfile, &buffer, sizeof(buffer));

	waitpid(pid, &status, 0);
	printf("Parents process\n");
	close(fd_infile);
	close(fd_outfile);

	return 0;
}
