/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:41:00 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/21 19:17:20 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	ft_init_data()
{
	t_data data;
	
	data.fdin = 0;
	data.fdout = 0;
	data.fd_pipe[0] = -1;
	data.fd_pipe[1] = -1;
	data.firstcommand = NULL;
	data.firstcommandpath = NULL;
	data.secondcommand = NULL;
	data.secondcommandpath = NULL;
	return (data);
}

int main(int argc, char const *argv[], char **envp)
{
	t_data	data;
	pid_t	pid;
	
	if (argc == 0)
		return(write(2, "Numero de argumentos menor a 4!!\n", 33), 1);
	else
	{
		data = ft_init_data();
		data.fdin = open(argv[1], O_RDONLY);
		if (data.fdin == -1)
			write(2, "Error al abrir el archivo!!\n", 28);
		ft_get_data(argv, envp, &data);
		
		pipe(data.fd_pipe);
		
		pid = fork();
		
		if (pid == 0)	// Hijo
		{
			puts("Soy el hijo");
			printf("{%s}\n", data.firstcommandpath);
			printargs(data.firstcommand);
			printf("{%s}\n", data.secondcommandpath);
			printargs(data.secondcommand);

			close(data.fd_pipe[0]);
			dup2(data.fdin, STDIN_FILENO);
			dup2(data.fd_pipe[1], STDOUT_FILENO);
			close(data.fd_pipe[1]);
			execve(data.firstcommandpath, data.firstcommand, envp);
			exit(1);
		}
		else			// Padre
		{
			waitpid(pid, NULL, 0);

			puts("Soy el Padre");
			close(data.fd_pipe[1]);
			dup2(data.fd_pipe[0], STDIN_FILENO);
			close(data.fd_pipe[0]);

			pid = fork();

			if (pid == 0)
			{
				data.fdout = open(argv[4], O_CREAT | O_WRONLY, 0644);
				dup2(data.fdout, STDOUT_FILENO);
				close(data.fdout);
				execve(data.secondcommandpath, data.secondcommand, envp);
				puts("Error execve cmd 2");
				exit(1);
			}
			waitpid(pid, NULL, 0);
		}
		ft_free_data(&data);
	}
	return 0;
}
