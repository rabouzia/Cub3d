/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:46:19 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/30 22:11:44 by ramzerk          ###   ########.fr       */
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
				return (printf("Error\nWrong Char\n"),0);
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
	else
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
