/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:33:43 by ramzerk           #+#    #+#             */
/*   Updated: 2024/11/02 23:38:09 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// bool	minilibx(t_game *game)
// {
// 	if (!win_create(game))
// 		return (0);
// 	return (1);
// }

// bool	win_create(t_game *game)
// {
// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 		return (MLX_ERROR);
// 	if (!game->win)
// 	{
// 		mlx_destroy_display(game->mlx);
// 		free(game->mlx);
// 		return (MLX_ERROR);
// 	}
// 	return (1);
// }