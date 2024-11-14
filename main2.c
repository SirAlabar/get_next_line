/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:22:00 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/05/19 18:28:12 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int fd1, fd2, fd3, fd4, fd5;
	char *line;

	fd1 = open("test2.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("Error opening file1");
		return (1);
	}


	while ((line = get_next_line(fd1)) != NULL)
	{
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}

	close(fd1);


	return (0);
}
