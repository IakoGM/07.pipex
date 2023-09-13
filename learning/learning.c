/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:13:29 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/13 12:14:55 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 	// write
#include <fcntl.h>		// open
#include <stdio.h> 		// perror
#include <stdlib.h> 	// exit

int main(int argc, char *argv[])
{
	int fdin;
	int fdout;
	char *buf;

	if (argc < 2)
	{
		perror("Min of two arg needed\n");
		return (1);
	}
	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
		perror("Can't open infile\n");
	fdout = open("outfile.txt", O_CREAT | O_WRONLY, 0644);
	if (fdout == -1)
		perror("Can't open outfile\n");
	while (read(fdin, &buf, 1))
	{
		write(fdout, &buf, 1);
	}
	return 0;
}