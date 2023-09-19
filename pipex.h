/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:41:35 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/19 16:51:32 by jakgonza         ###   ########.fr       */
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
	char	**args;
	char	**firstcommand;
	char	**secondcommand;
		
}			t_data;


// ------- FUNCIONES ------- //
void	ft_check_params(char **argv, char **envp);
void	printargs(char **args);

#endif