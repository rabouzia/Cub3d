/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:29:06 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/30 01:34:01 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	parsing(t_game *game)
{
	// if (!map_valid(game))
	// 	return (0);
	if (!letter_check(game))
		return (0);
	if (!read_cub(game))
		return (0);
	if (!is_validmap(game))
		return (0);
	return (1);
}


int is_validmap(t_game *map)
{	
	
}


/*
	- lettre valid

	- check la map avec ce qu'il ya autour des 0 (X: ' ' et 'P')
*/