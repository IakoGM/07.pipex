/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valgrind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:55:13 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/22 13:33:29 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int		i;
	char	*str;
	char	*str2;

	i = 0;
	while (i < 1)
	{
		str = (char *) malloc (5 * sizeof(char));
		str2 = (char *) malloc (5 * sizeof(char));
		i++;
	}
	return (free(str), free(str2), 0);
}
