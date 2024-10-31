/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:29:06 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/30 22:10:20 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_validmap(t_game *map)
{
	(void) map;
	return (1);
}
bool	parsing(t_game *game)
{
	// if (!map_valid(game))
	// 	return (0);
	if (!letter_check(game))
		return (0);
	printf("here\n");
	if (!read_cub(game))
		return (0);
	if (!is_validmap(game))
		return (0);
	return (1);
}


/*
	- lettre valid

	- check la map avec ce qu'il ya autour des 0 (X: ' ' et 'P')
*/