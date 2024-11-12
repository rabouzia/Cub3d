/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_portable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:53:17 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/12 15:57:40 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*r;
	int		d;

	if (!src)
		return (NULL);
	r = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!r)
		return (NULL);
	i = 0;
	d = 1;
	while (src[i] && d > 0)
	{
		if (src[i] == '\n')
			break ;
		r[i] = src[i];
		i++;
	}
	r[i] = 0;
	return (r);
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (0);
		i++;
		j = 0;
	}
	return (1);
}

int	ft_strlcpy(char *dest, char *src, int len)
{
	int	i;
	int	x;

	x = ft_strlen(src);
	i = 0;
	if (len < 1)
		return (x);
	if (len != 0)
	{
		while (src[i] != '\0' && i < len - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (x);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		n1;
	int		n2;
	int		bytes;
	char	*joined;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	bytes = n1 + n2 + 1;
	joined = malloc(bytes);
	if (joined == NULL)
		return (NULL);
	ft_strlcpy(joined, s1, n1 + 1);
	ft_strlcpy(joined + n1, s2, n2 + 1);
	return (joined);
}

void	*ft_calloc(size_t n, size_t s)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s != 0)
	{
		if (n > INT_MAX / s)
			return (0);
	}
	str = (char *)malloc(n * s);
	if (str == 0)
		return (0);
	while (i < n * s)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
