/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.0.parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:29:06 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/05 15:50:42 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	parsing(t_game *game)
{
	if (!map_valid(game))
		return (0);
	if (!letter_check(game))
		return (0);
	if (!fill_map(game))
		return (0);
	return (1);
}
