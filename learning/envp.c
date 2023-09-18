/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:40:24 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/18 23:34:45 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "env.h"

int main(int argc, char const *argv[], char const **envp)
{
	int		i;
	int		j;
	char	**result;
	char	*path = "/sort";
	char	*all_path;
	char	**arguments = {"/bin/sort", NULL};

	i = 0;
	j = 0;
	if (!envp)
		perror("Las variables de entorno estan vacias.\n");
	while (envp[i])
	{
		if (strncmp("PATH=", envp[i], 5) == 0)
		{
			result = ft_split(envp[i], ':');
			result[0] = ft_substr(result[0], 5, strlen(result[0]));
			while (result[j])
			{				
				all_path = ft_strjoin(result[j], path);
				// if (access(result[j], X_OK) == 0)
				if (access(all_path, X_OK) == 0)
				{
					puts(all_path);
					if (execve(all_path, arguments, envp[i]) == -1)
					 	perror("Fallo en execve");
				}
				else
					perror("Problemas en el arhivo");
					puts(all_path);
				j++;
			}
		}
		i++;
	}
	return 0;
}
