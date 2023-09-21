/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:41:35 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/21 17:33:53 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Includes
# include "libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

// ------- STRUCT ------- //
typedef	struct s_data
{
	int		fdin;
	int		fdout;
	int		fd_pipe[2];
	char	**firstcommand;
	char	*firstcommandpath;
	char	**secondcommand;
	char	*secondcommandpath;
}			t_data;

// ------- FUNCIONES ------- //
void	ft_get_data(char const **argv, char **envp, t_data *data);
void	ft_get_cmd_path(char **envp, t_data *data);
void	ft_get_cmd2_path(char **envp, t_data *data);


// ------- FUNCIONES ERROR - FREE ------- //
void	ft_free_double_pointer(char **c);
void	ft_free_data(t_data *data);

// ------- ELIMINAR - DEBUGGING ------- //
void	printargs(char **args);

#endif