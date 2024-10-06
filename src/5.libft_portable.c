/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.libft_portable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:53:17 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/06 02:21:25 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*ft_strdup(char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i])
		i++;
	res = malloc(sizeof(char) * (1 + i));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i++])
		res[i] = str[i];
	res[i] = 0;
	return (res);
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


