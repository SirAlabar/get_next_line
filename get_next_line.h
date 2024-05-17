/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:53:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/05/17 21:00:23 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*
**                              HEADERS
*/
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
/*
**                              BUFFER
*/
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
/*
**                              STRUCT DECLARATIONS
*/
/*typedef struct s_flags
{

}	t_flags;
*/

/*
**                              FUNCTION PROTOTYPES
*/
char *get_next_line(int fd);
static char *read_line(int fd, char *backup);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
static char	*clean_stash(char *stash);
char *get_line(char *backup);


#endif