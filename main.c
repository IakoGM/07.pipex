/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:41:00 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/27 13:07:23 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_data	ft_init_data(void)
{
	t_data	data;

	data.fdin = 0;
	data.fdout = 0;
	data.fd_pipe[0] = -1;
	data.fd_pipe[1] = -1;
	data.firstcommand = NULL;
	data.firstcommandpath = NULL;
	data.secondcommand = NULL;
	data.secondcommandpath = NULL;
	data.env_path = NULL;
	return (data);
}

void static	ft_first_son(t_data *data, char **envp)
{
	close(data->fd_pipe[0]);
	dup2(data->fdin, STDIN_FILENO);
	dup2(data->fd_pipe[1], STDOUT_FILENO);
	close(data->fd_pipe[1]);
	if (execve(data->firstcommandpath, data->firstcommand, envp) == -1)
	{
		ft_free_data(data);
		write(2, "Error execve cmd 1\n", 19);
		exit(1);
	}
}

void static	ft_second_son(t_data *data, char *outfile, char **envp)
{
	data->fdout = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fdout == -1)
	{
		ft_free_data(data);
		write(2, "No se puede abrir el archivo de salida!\n", 40);
		exit(1);
	}
	dup2(data->fdout, STDOUT_FILENO);
	close(data->fdout);
	if (execve(data->secondcommandpath, data->secondcommand, envp) == -1)
	{
		write(2, "Error execve cmd 2\n", 19);
		ft_free_data(data);
		exit(1);
	}
}

void	ft_father(pid_t pid, t_data *data, char *outfile, char **envp)
{
	pid_t	pid2;

	waitpid(pid, NULL, 0);
	close(data->fd_pipe[1]);
	dup2(data->fd_pipe[0], STDIN_FILENO);
	close(data->fd_pipe[0]);
	pid2 = fork();
	if (pid2 == 0)
		ft_second_son(data, outfile, envp);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char *argv[], char **envp)
{
	t_data	data;
	pid_t	pid;

	if (argc != 5)
		return (write(2, "Numero de argumentos menor a 4!!\n", 33), 1);
	else if (argv[2][0] == '\0' || argv[3][0] == '\0')
		return (write(2, "Introduce un comando.\n", 22), 1);
	else
	{
		data = ft_init_data();
		data.fdin = open(argv[1], O_RDONLY);
		if (data.fdin == -1)
			return (write(2, "Error al abrir el archivo!!\n", 28), 1);
		ft_get_data(argv, envp, &data);
		pipe(data.fd_pipe);
		pid = fork();
		if (pid == 0)
			ft_first_son(&data, envp);
		else
			ft_father(pid, &data, argv[4], envp);
		ft_free_data(&data);
	}
	return (0);
}
