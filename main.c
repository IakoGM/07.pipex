/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:48:36 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/11 10:53:52 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
	int	fd_infile;
	int fd[2];
	int pid;
	int *status;
	char *const args[] = {"/bin/ls", "-l", NULL};
	
	fd_infile = open("infile.txt", O_RDONLY);
	pipe(fd);
	// Fork devuelve proccess id 0 para el proceso hijo
	pid = fork();

	if (pid == 0)
	{
		dup2(fd_infile, STDIN_FILENO);
		close(fd_infile);
		execv("/bin/ls", args);
	}
	
	waitpid(-1, &status, NULL);
	
	return 0;
}
