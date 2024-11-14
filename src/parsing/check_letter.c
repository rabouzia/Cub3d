/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:46:19 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/14 18:02:31 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	letter_check(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map.tab_map[i])
	{
		j = 0;
		while (cube->map.tab_map[i][j])
		{
			if (!is_good(cube->map.tab_map[i][j]))
				return (ft_end(cube, "Wrong Char"), 0);
			if (ft_strchr("NSEW", cube->map.tab_map[i][j]))
			{
				if (cube->map.p_x != 0 || cube->map.p_y != 0)
					return (ft_end(cube, "Too Many Players"), 0);
				find_direction(cube->map.tab_map[i][j], i, j, cube);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_good(char c)
{
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
	cube->map.p_x = j;
	cube->map.p_y = i;
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
