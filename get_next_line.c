/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:43:57 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/05/17 21:36:11 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char *get_next_line(int fd)
{
    static char *backup;
    char *line;    
    
    if(fd < 0 || BUFFER_SIZE < 1)
        return(NULL);
//ssize_t read(int fildes, void *buf, size_t nbyte)
    backup = read(fd, backup, 0);
    if (!backup)
        return(NULL);    
    if
   
}*/
static char *read_line(int fd, char *backup)
{
  int  bytes_read;
  char *buffer;
    
  buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char *));
  if (!buffer)
    return (NULL);
  bytes_read = 1;  
  while(!(ft_strchr(backup, '\n')) && bytes_read != 0)
  {  
//ssize_t read(int fildes, void *buf, size_t nbyte)     
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if(bytes_read == -1)
    {
      free(buffer);
      free(backup);
      return (NULL);
    }
    buffer[bytes_read] = 0;
    if(!buffer)
      return (NULL);
    backup = ft_strjoin(backup, buffer);
  } 
    free(buffer);
  return (backup);  
}
char *get_line(char *backup)
{
  unsigned int i;
  char *line;
  
  i = 0;
  if(!backup[i])    
    return(NULL);
  while(backup[i] && backup[i] != '\n')
    i++;
  if(backup[i] == '\0')    
    line = ft_calloc(sizeof(char), (i + 1));
  else  
    line = ft_calloc(sizeof(char), (i + 2));  
  if(!line)
      return (NULL);
  i = 0;            
  while(backup[i] && (backup[i] != '\n'))
  {
      line[i] = backup[i];
      i++;
  }
  if(backup[i] == '\n')
      line[i++] = '\n';
  line[i] = '\0';
  return(line);  
}

static char	*clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	i++;
	while (stash[i] != '\0')
	{
		new_stash[j] = stash[i];
		j++;
		i++;
	}
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char  *get_next_line(int fd)
{
    static char *backup;
    char *line;    
    
    if(fd < 0 || BUFFER_SIZE < 1)
        return(NULL);
    backup = read_line(fd, backup);
    if (!backup)
        return(NULL);    
    line = get_line(backup);
    backup = clean_stash(backup);    
    return(line);
}
/*
#include <stdio.h>
int main()
{
       int fd;
       char *next_line;
       int count;

       count = 0;
       fd = open("test.txt", O_RDONLY);
       if (fd == -1)
       {
            printf("Error opening file");
            return(1);
       }
       while(1)
       {
            next_line = get_next_line(fd);
            if(next_line == NULL)
                break;    
            count++;
            printf("[%d]:%s\n", count, next_line);
            free(next_line);
            next_line = NULL;
       }
       close(fd);
       return (0);    
}*/
#include <stdio.h>
int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}
