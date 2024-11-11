/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:45:21 by ramzerk           #+#    #+#             */
/*   Updated: 2024/11/11 12:19:00 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

char	*ft_strjoin_4(char *s1, char *s2, char *s3, char *s4)
{
	int		i;
	char	*join;

	if (!s1 || !s2 || !s3 || !s4)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3)
				+ ft_strlen(s4) + 1));
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	i--;
	while (s2[++i - ft_strlen(s1)])
		join[i] = s2[i - ft_strlen(s1)];
	i--;
	while (s3[++i - ft_strlen(s1) - ft_strlen(s2)])
		join[i] = s3[i - ft_strlen(s1) - ft_strlen(s2)];
	i--;
	while (s4[++i - ft_strlen(s1) - ft_strlen(s2) - ft_strlen(s3)])
		join[i] = s4[i - ft_strlen(s1) - ft_strlen(s2) - ft_strlen(s3)];
	join[i] = 0;
	return (join);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
