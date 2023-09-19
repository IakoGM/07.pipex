/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:53:17 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/19 12:11:23 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_params(char **argv, char **envp)
{
	int		fdin;
	int		i;
	int		j;
	char	**envs;
	char	*all_path;
	char	*path = "/sort";
	

	i = 0;
	j = 0;
	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
		perror("No se puede abrir el archivo");
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			envs = ft_split(envp[i], ':');
			envs[0] = ft_substr(envs[0], 5, ft_strlen(envs[0]));
			while (envs[j])
			{
				all_path = ft_strjoin(envs[j], path);
				if (access(all_path, X_OK) == 0)
				{
					puts(all_path);
					if (execve(all_path, argv, &envp[i]) == -1)
					 	perror("Fallo en execve");
				}
				else
					perror("Problemas en el archivo");
					puts(all_path);
				j++;
			}
		}
		i++;
	}
}
