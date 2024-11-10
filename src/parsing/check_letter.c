/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:46:19 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/10 20:40:06 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	letter_check(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	// print_tab(cube->map.tab_map);
	// printf("%p\n", cube->map.tab_map);e
	while (cube->map.tab_map[i])
	{
		// printf("%d\n", i);
		j = 0;
		while (cube->map.tab_map[i][j])
		{
			if (!is_good(cube->map.tab_map[i][j]))
				return (printf("Error\nWrong Char\n"), 0);
			if (ft_strchr("NSEW", cube->map.tab_map[i][j]))
			{
				if (cube->map.p_x != 0 || cube->map.p_y != 0)
					return (printf("Error\nToo many players\n"), 0);
				find_direction(cube->map.tab_map[i][j], i, j, cube);
			}
			j++;
		}
		i++;
	}
	// printf("hello ni\n");
	return (1);
}

int	is_good(char c)
{
	// printf("char is %c\n", c);
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == 'D')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'W')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

bool	find_direction(char c, int i, int j, t_cube *cube)
{
	cube->map.p_x = i;
	cube->map.p_y = j;
	if (c == 'N')
	{
		cube->player.angle = -M_PI / 2.0;
		return (1);
	}
	else if (c == 'S')
	{
		cube->player.angle = M_PI / 2.0;
		return (1);
	}
	else if (c == 'E')
	{
		cube->player.angle = 0;
		return (1);
	}
	else if (c == 'W')
	{
		cube->player.angle = M_PI;
		return (1);
	}
	return (0);
}
