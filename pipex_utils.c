/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:53:17 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/27 13:06:59 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_access_first(t_data *data)
{
	int		i;
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
		data->firstcommandpath = NULL;
		i++;
	}
	write(2, "El comando introducido, NO es un comando valido!\n", 49);
	ft_free_data(data);
	exit(1);
}

void	ft_access_second(t_data *data)
{
	int		i;
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
		data->secondcommandpath = NULL;
		i++;
	}
	write(2, "El comando introducido, NO es un comando valido!\n", 49);
	ft_free_data(data);
	exit(1);
}

void	ft_get_cmd_path(char **envp, t_data *data)
{
	char	*temp;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			data->env_path = ft_split(envp[i], ':');
			temp = ft_strdup(data->env_path[0]);
			free(data->env_path[0]);
			data->env_path[0] = ft_substr(temp, 5, ft_strlen(temp));
			free(temp);
			return ;
		}
		i++;
	}
}

void	ft_get_data(char **argv, char **envp, t_data *data)
{
	data->firstcommand = ft_split(argv[2], ' ');
	data->secondcommand = ft_split(argv[3], ' ');
	ft_get_cmd_path(envp, data);
	ft_access_first(data);
	ft_access_second(data);
}
