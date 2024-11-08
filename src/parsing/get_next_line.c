/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:38:19 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/08 20:47:35 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rm_back(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	i++;
	j = 0;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
}

char	*get_next_line(int fd)
{
	char		*res;
	int			lu;
	static char	buff[BUFFER_SIZE + 1] = {};

	if (BUFFER_SIZE < 1 || fd > 1024 || fd < 0)
		return (NULL);
	lu = 1;
	res = NULL; 		
	if (ft_memchr(buff, '\n') != 0)
	{
		if (ft_strlen(ft_memchr(buff, '\n') + 1) > 0)
			res = ft_strdup(ft_memchr(buff, '\n') + 1);
		rm_back(buff);
	}
	while (lu > 0 && (ft_strchr(res, '\n') == 0))
	{
		lu = read(fd, buff, BUFFER_SIZE);
		if (lu <= 0)
			break ;
		buff[lu] = '\0';
		res = for_strjoin(res, buff);
	}
	if (lu <= 0 && !res)
		return (NULL);
	return (res);
}

// char	*get_next_line(int fd)
// {
// 	static char buffer[BUFFER_SIZE];
// 	char line[70000];
// 	static int buffer_read;
// 	static int buffer_pos;
// 	int i;

// 	i = 0;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (1)
// 	{
// 		if (buffer_pos >= buffer_read)
// 		{
// 			buffer_read = read(fd, buffer, BUFFER_SIZE);
// 			buffer_pos = 0;
// 			if (buffer_read <= 0)
// 				break ;
// 		}
// 		if (line[i] == '\n')
// 			break ;
// 		line[i] = buffer[buffer_pos++];
// 		i++;
// 	}
// 	line[i] = '\0';
// 	if (i == 0)
// 		return (NULL);
// 	return (ft_strdup(line));
// }