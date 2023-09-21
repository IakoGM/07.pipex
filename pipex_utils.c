/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:53:17 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/21 18:51:21 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_cmd_path(char **envp, t_data *data)
{
	char	**env_path;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	puts("Estoy en get_cmd_path"); // ELIMINAR
	temp = ft_strjoin("/", data->firstcommand[0]);
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			env_path = ft_split(envp[i], ':');
			env_path[0] = ft_substr(env_path[0], 5, ft_strlen(env_path[0]));
			while (env_path[j])
			{
				data->firstcommandpath = ft_strjoin(env_path[j], temp);
				if (access(data->firstcommandpath, F_OK) == 0)
					return (free(temp), free(env_path));
				j++;
			}
		}
		i++;
	}
}

void	ft_get_cmd2_path(char **envp, t_data *data)
{
	char	**env_path;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	puts("Estoy en get_cmd2_path"); // ELIMINAR
	temp = ft_strjoin("/", data->secondcommand[0]);
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			env_path = ft_split(envp[i], ':');
			env_path[0] = ft_substr(env_path[0], 5, ft_strlen(env_path[0]));
			while (env_path[j])
			{
				data->secondcommandpath = ft_strjoin(env_path[j], temp);
				if (access(data->secondcommandpath, F_OK) == 0)
					return (free(temp), free(env_path));
				j++;
			}
		}
		i++;
	}
}

void	ft_get_data(char const **argv, char **envp, t_data *data)
{
	data->firstcommand = ft_split(argv[2], ' ');
	data->secondcommand = ft_split(argv[3], ' ');
	ft_get_cmd_path(envp, data);
	ft_get_cmd2_path(envp, data);
}