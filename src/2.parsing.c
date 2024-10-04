/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:29:06 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/04 11:22:44 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool parsing(t_game *game)
{
	if(!map_valid(game))
		return 0;
	if(!letter_check(game))
		return 0;
}

int	letter_check(t_game *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (!is_good(m->map[i][j], i, j, m))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int	is_good(char c, int i, int j, t_game *game)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == 'P')
	{
		game->pos.x = i;
		game->pos.y = j;
		return (1);
	}
	if (c == 'C')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'M')
		return (1);
	return (0);
}