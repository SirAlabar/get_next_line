/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:39:57 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/05/17 21:26:12 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if(s == NULL)
		return (NULL);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
char	*ft_strdup(const char *s1)
{
	char	*s2;
	unsigned int i;

	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while(i < ft_strlen(s1))
	{
		s2[i] = s1[i];
		i++;
	}	
	s2[i] = 0;;
	return (s2);
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	unsigned int i;

	str = malloc(size * count);
	if (str)
	{
		i = 0;	
		while (i < (count * size))
		{
			str[i] = 0;
			i++;
		}
	}
	return (str);
}

