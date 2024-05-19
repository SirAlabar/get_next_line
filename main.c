/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:22:00 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/05/19 18:14:36 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int fd1, fd2, fd3, fd4, fd5;
	char *line;

	// Abrindo múltiplos arquivos
	fd1 = open("test.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("Error opening file1");
		return (1);
	}

	fd2 = open("test2.txt", O_RDONLY);
	if (fd2 < 0)
	{
		perror("Error opening file2");
		close(fd1);
		return (1);
	}

	fd3 = open("test3.txt", O_RDONLY);
	if (fd3 < 0)
	{
		perror("Error opening file3");
		close(fd1);
		close(fd2);
		return (1);
	}

	fd4 = open("test4.txt", O_RDONLY);
	if (fd4 < 0)
	{
		perror("Error opening file4");
		close(fd1);
		close(fd2);
		close(fd3);
		return (1);
	}
	/*
	fd5 = open("J. K. Rowling - Harry Potter 3 - Prisoner of Azkaban.txt",
			O_RDONLY);
	if (fd5 < 0) {
		perror("Error opening file5");
		close(fd1);
		close(fd2);
		close(fd3);
		close(fd4);
		return (1);
	}*/

	// Leitura alternada entre os arquivos
	while ((line = get_next_line(fd1)) != NULL)
	{
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	while ((line = get_next_line(fd2)) != NULL)
	{
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	while ((line = get_next_line(fd3)) != NULL)
	{
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	while ((line = get_next_line(fd4)) != NULL)
	{
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	/*
  while ((line = get_next_line(fd5)) != NULL)
	{
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
*/
	// Fechando os arquivos
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);

	return (0);
}