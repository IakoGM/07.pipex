/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:41:00 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/19 15:36:23 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char const *argv[], char const *envp[])
{
	char	**args;
	char	**envs;

	args = (char **) argv;
	envs = (char **) envp;
	if (argc < 0)
		write(2, "Numero de argumentos menor a 4!!\n", 33);
	else
	{
		printargs(args);
		ft_check_params(args, envs);
	}
	return 0;
}
