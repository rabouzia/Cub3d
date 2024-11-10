/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:29:06 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/10 21:24:16 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	parsing(t_cube *cube, char **av)
{
	cube->av = av;
	// if (!init_argument(cube, av))
	// 	return (0);
	if (!read_cub(cube))
		return (0);
	// print_tab(cube->map.tab_map);
	if (!map_valid(cube))
		return (0);
	if (!letter_check(cube))
		return (0);
	// if (!init_cube(cube))
	// 	return (0);
	init_the_player(cube);
	return (1);
}

int map_valid(t_cube * cube)
{
	int 
}
int	game_loop(t_cube *cube)
{
	// printf("x %f y %f\n", cube->player.plyr_x, cube->player.plyr_y);
	cast(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->image.img, 0, 0);
	inputs(cube);
	return (0);
}

int	init_the_player(t_cube *cube)
{
	cube->player.plyr_x = cube->map.p_x * TILE_SIZE + TILE_SIZE / 2;
	cube->player.plyr_y = cube->map.p_y * TILE_SIZE + TILE_SIZE / 2;
	cube->player.fov_rd = (FOV * M_PI) / 180;
	cube->player.angle = M_PI;
	return (1);
}
