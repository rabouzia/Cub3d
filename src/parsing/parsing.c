/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:29:06 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/06 02:18:26 by ramzerk          ###   ########.fr       */
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
	return (1);
}
