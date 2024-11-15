/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:34:01 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/15 15:40:28 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	printarg(t_arg *arg)
{
	while (arg)
	{
		printf("content is %s  \n", arg->content);
		arg = arg->next;
	}
}

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_strlen(tab[i]);
		i++;
	}
	return (i);
}

int	collumlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	count_columns(t_cube *cube)
{
	int		column;
	t_arg	*lst;

	lst = cube->arg;
	column = 0;
	while (lst)
	{
		column = ft_strlen(lst->content);
		if (cube->map.columns < column && lst->type == MAP)
			cube->map.columns = column;
		lst = lst->next;
	}
	cube->map.rows = cube->map.columns;
}

void	epur_space(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
			{
				str[j++] = ' ';
				while (str[i] == ' ' || str[i] == '\t')
					i++;
			}
			else
				str[j++] = str[i++];
		}
		if (j > 0 && str[j - 1] == ' ')
			j--;
	}
	str[j] = '\0';
}
