/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:46:19 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/30 14:58:06 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	letter_check(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->av[i])
	{
		j = 0;
		while (map->av[i][j])
		{
			if (!is_good(map->av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_good(char c, t_game *game)
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
	// if (find_direction(c, i, j, game))
	// 	return (1);
	return (0);
}

bool	find_direction(char c, int i, int j, t_game *game)
{
	if (c == 'N')
	{
		game->pos.x = i;
		game->pos.y = j;
		return (1);
	}
	else if (c == 'S')
	{
		game->pos.x = i;
		game->pos.y = j;
		return (1);
	}
	else if (c == 'E')
	{
		game->pos.x = i;
		game->pos.y = j;
		return (1);
	}
	{
		game->pos.x = i;
		game->pos.y = j;
		return (1);
	}
	return (0);
}
