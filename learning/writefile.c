/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writefile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:48:33 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/14 10:00:48 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>		// write
#include <fcntl.h>		// open
#include <stdio.h>		// perror

int main(int argc, char const *argv[])
{
	int fd;

	fd = open("iakito.txt", O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		perror("Error al abrir el archivo!\n");
	if (write(fd, "Iakito morenito\n", 16) == 0)
		perror("No se puede escribir en el archivo!!\n");
	close(fd);
	return 0;
}
