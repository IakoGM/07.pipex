/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:58:36 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/15 14:31:59 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * CREAMOS UN HIJO, REDIRECCIONAMOS EL STDIN A UN ARCHIVO
 * EJECUTAMOS UN COMANDO CON EXEC, LO ENVIAMOS A TRAVÉS
 * DEL PIPE, RECIBIMOS ESA DATA, EJECUTAMOS UN SEGUNDO COMANDO
 * Y ENVIAMOS EL RESULTADO A OTRO ARCHIVO.
 * 
 * archivo -> padre -> hijo1 -> hijo2 -> padre -> archivo 
*/

#include <unistd.h>		// write
#include <fcntl.h>		// open
#include <stdio.h>		// 
#include <sys/wait.h>	// waitpid

int main(int argc, char const *argv[])
{
	int		fdin;
	int		fdout;
	int		fd_pipe[2];
	int		*status;
	pid_t	child1;
	pid_t	child2;
	
	pipe(fd_pipe);

	child1 = fork();
	
	if (child1 == 0)		// Estamos en el primer hijo
	{
		close(fd_pipe[0]);
		fdin = open("infile.txt", O_RDONLY);
		dup2(fdin, STDIN_FILENO);				// Hemos redirigido el STDIN al archivo
		close(fdin);
		dup2(fd_pipe[1], STDOUT_FILENO);
		execlp("/bin/sort", "sort", NULL);
	}
	else				// Estamos en el padre
	{
		child2 = fork();
		
		if (child2 == 0)	// Estamos en el segundo hijo
		{
			close(fd_pipe[1]);
			dup2(fd_pipe[0], STDIN_FILENO);
			close(fd_pipe[0]);
			fdout = open("mockout.txt", O_CREAT | O_WRONLY, 0644);
			dup2(fdout, STDOUT_FILENO);
			execlp("/bin/wc", "wc", "-c", NULL);
		}
		else		// Estamos de nuevo en el padre
		{
			close(fd_pipe[0]);
			close(fd_pipe[1]);
		}
	}
	waitpid(-1, status, 0);

	return 0;
}
