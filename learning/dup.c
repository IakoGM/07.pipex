/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:57:41 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/21 13:29:37 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>		// open
#include <sys/wait.h>	// wait
#include <string.h>		

int main(int argc, char const *argv[])
{
	int		fd_pipe[2];
	int		fdin;
	int 	fdout;
	int		pid;
	int		status;
	char	*buffer;
	int		bits_read;

	pipe(fd_pipe);

	pid = fork();
	
	if (pid == 0)	/* Estamos en el hijo */
	{
		close(fd_pipe[0]);						/* Cerramos en READ_END */
		fdin = open("infile.txt", O_RDONLY);
		dup2(fdin, STDIN_FILENO);				/* Cambiamos la entrada stdin por el fichero */
		close(fdin);
		dup2(fd_pipe[1], STDOUT_FILENO);
		execlp("/bin/sort", "sort", NULL);
	}
	else if (pid > 0) /* Estamos en el padre */
	{
		waitpid(-1, &status, 0);				/* Esperamos a que finalice el hijo */
		close(fd_pipe[1]);						/* Cerramos el extremo de escritura - WRITE_END que no necesitamos, porque vamos a escribir directamente en el archivo */
		fdout = open("outfile.txt", O_CREAT | O_WRONLY, 0644);
		while (bits_read == read(fd_pipe[0], &buffer, 1) > 0)	/* Mientras haya datos en el READ_END del pipe() lee e imprime */
			write(fdout, &buffer, 1);
		close(fd_pipe[0]);
	}
	return 0;
}
