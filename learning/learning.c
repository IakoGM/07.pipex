/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakgonza <jakgonza@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:13:29 by jakgonza          #+#    #+#             */
/*   Updated: 2023/09/13 18:49:22 by jakgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * CREAMOS UN HIJO, ENVIAMOS UN MENSAJE
 * DESDE EL PADRE AL HIJO POR EL PIPE
 * Y LO IMPRIMIMOS POR EL STDOUT
 * 
 * Padre -> Hijo -> STDOUT
*/

#include <unistd.h> 	// write
#include <fcntl.h>		// open
#include <stdio.h> 		// perror
#include <stdlib.h> 	// exit
#include <sys/wait.h>	// wait

#include <string.h>		// funciones string

int main(int argc, char *argv[])
{
	int		fd[2];
	pid_t	pid;
	char	msg_padre[100];
	char	msg_hijo[100] = "(HIJO) -> Mi padre dice... ";
	
	// Creamos un pipe para poder comunicar dos procesos entre sí, en este caso padre e hijo
	if (pipe(fd) == -1)
		perror("Pipe creation has failed!\n");
	// Con el pid podemos controlar si estamos en el proceso hijo o en el padre
	pid = fork();
	if (pid == 0)
	{
		// Estamos en el proceso hijo
		write(1, "(HIJO) -> Iniciando...\n", 24);
		close(fd[1]); // Podemos cerrar el extremo de escritura del hijo porque lo escribe en el STDOUT
		read(fd[0], &msg_padre, 100);
		close(fd[0]); // Cerramos el extremo de lectura después de almacenarlo
		strcat(msg_hijo, msg_padre);
		write(1, &msg_hijo, strlen(msg_hijo) + 1);
		write(1, "(HIJO) -> Finalizando...\n", 26);
	}
	else
	{
		// Estamos en el proceso padre
		write(1, "(PADRE) -> Iniciando...\n", 25);
		close(fd[0]); // Cerramos el extremo de lectura del proceso padre porque no necesita leer nada
		// Enviamos un mensaje al proceso hijo a través del fd de escritura
		write(fd[1], "(PADRE) -> Hola YO soy TU padre\n", 33);
		close(fd[1]); // Cerramos el extremo de escritura una vez utilizado
		wait(NULL); // Esperamos a que los procesos hijos finalicen
		write(1, "(PADRE) -> Finalizando...\n", 27);
		
	}
	

	return 0;
}
