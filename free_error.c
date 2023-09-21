/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:02:54 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/21 17:58:58 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_double_pointer(char **c)
{
	int	i;

	i = 0;
	while (c[i])
			free(c[i]);
		free(c);
}

void	ft_free_data(t_data *data)
{
	if (data->firstcommand)
		ft_free_double_pointer(data->firstcommand);
	if (data->secondcommand)
		ft_free_double_pointer(data->secondcommand);
	if (data->firstcommandpath)
		free(data->firstcommandpath);
	if (data->secondcommandpath)
		free(data->secondcommandpath);
}