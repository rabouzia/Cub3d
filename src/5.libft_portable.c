/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.libft_portable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:53:17 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/05 15:55:28 by rabouzia         ###   ########.fr       */
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


