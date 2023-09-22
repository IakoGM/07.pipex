/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:53:17 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/22 14:23:07 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_access_first(t_data *data)
{
	int	i;
	char	*temp;

	i = 0;
	temp = ft_strjoin("/", data->firstcommand[0]);
	free(data->firstcommand[0]);
	data->firstcommand[0] = temp;
	while (data->env_path[i])
	{
		data->firstcommandpath = ft_strjoin(data->env_path[i], temp);
		if (access(data->firstcommandpath, F_OK) == 0)
			return ;
		free(data->firstcommandpath);
		i++;
	}
}

void	ft_access_second(t_data *data)
{
	int	i;
	char	*temp;

	i = 0;
	temp = ft_strjoin("/", data->secondcommand[0]);
	free(data->secondcommand[0]);
	data->secondcommand[0] = temp;
	while (data->env_path[i])
	{
		data->secondcommandpath = ft_strjoin(data->env_path[i], temp);
		if (access(data->secondcommandpath, F_OK) == 0)
			return ;
		free(data->secondcommandpath);
		i++;
	}
}

void	ft_get_cmd_path(char **envp, t_data *data)
{
	char	*temp;
	int		i;

	i = 0;
	puts("Estoy en get_cmd_path"); // ELIMINAR
	
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{		/* LIBERAR - env_path y temp */
			data->env_path = ft_split(envp[i], ':');
			puts("Variables de entorno");
			printargs(data->env_path);
			temp = ft_strdup(data->env_path[0]);
			free(data->env_path[0]);
			data->env_path[0] = ft_substr(temp, 5, ft_strlen(temp));
			free(temp);
			return ;
		}
		i++;
	}
	ft_access_first(data);
	ft_access_second(data);
}

// void	ft_get_cmd2_path(char **envp, t_data *data)
// {
// 	char	**env_path;
// 	char	*temp;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	puts("Estoy en get_cmd2_path"); // ELIMINAR
// 	temp = ft_strjoin("/", data->secondcommand[0]);
// 	while (envp[i])
// 	{
// 		if (ft_strncmp("PATH=", envp[i], 5) == 0)
// 		{
// 			env_path = ft_split(envp[i], ':');
// 			env_path[0] = ft_substr(env_path[0], 5, ft_strlen(env_path[0]));
// 			while (env_path[j])
// 			{
// 				data->secondcommandpath = ft_strjoin(env_path[j], temp);
// 				if (access(data->secondcommandpath, F_OK) == 0)
// 					return (free(temp), free(env_path));	// Esta linea si que sirve
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// }

void	ft_get_data(char const **argv, char **envp, t_data *data)
{
	data->firstcommand = ft_split(argv[2], ' ');
	data->secondcommand = ft_split(argv[3], ' ');
	ft_get_cmd_path(envp, data);
	// ft_get_cmd2_path(envp, data);
}