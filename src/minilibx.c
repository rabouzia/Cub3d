/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.minilibx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:33:43 by ramzerk           #+#    #+#             */
/*   Updated: 2024/10/05 16:08:35 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool minilibx(t_game *game)
{
	if (!win_create(game))
		return 0;
	return 1;
}

bool	win_create(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (MLX_ERROR);
	game->win = mlx_new_window(game->mlx,1920,
			1080, "Cube 3D");
	if (!game->win)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (MLX_ERROR);
	}
	return (1);
}