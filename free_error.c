/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:02:54 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/25 11:58:54 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_double_pointer(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
}

void	ft_free_data(t_data *data)
{
	if (data->firstcommand != NULL)
		ft_free_double_pointer(data->firstcommand);
	if (data->secondcommand != NULL)
		ft_free_double_pointer(data->secondcommand);
	if (data->firstcommandpath != NULL)
		free(data->firstcommandpath);
	if (data->secondcommandpath != NULL)
		free(data->secondcommandpath);
	if (data->env_path != NULL)
		ft_free_double_pointer(data->env_path);
}