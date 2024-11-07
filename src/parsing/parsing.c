/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:29:06 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/07 17:05:10 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	parsing(t_cube *cube, char **av)
{
	if (!init_argument(cube, av))
		return (0);
	if (!read_cub(cube))
		return (0);
	// if (!map_valid(cube))
	// 	return (0);
	// if (!letter_check(cube))
	// 	return (0);
	// if (!is_validmap(cube))
	// 	return (0);
	// if (!init_cube(cube))
	// 	return (0);
	return (1);
}

int	is_validmap(t_cube *map)
{
	(void)map;
	return (1);
}

int	game_loop(t_cube *cube)
{
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

int	init_argument(t_cube *cube, char **av)
{
	cube->av = av;
	cube->map.map2d = calloc(10, sizeof(char *));
	cube->map.map2d[0] = strdup("1111111111111111111111111");
	cube->map.map2d[1] = strdup("1000000000000000000100001");
	cube->map.map2d[2] = strdup("1001000000000P00000000001");
	cube->map.map2d[3] = strdup("1001000000000000001000001");
	cube->map.map2d[4] = strdup("100100000000P000001000001");
	cube->map.map2d[5] = strdup("1001000000100000001000001");
	cube->map.map2d[6] = strdup("1001000000000000001000001");
	cube->map.map2d[7] = strdup("1001000000001000001000001");
	cube->map.map2d[8] = strdup("1111111111111111111111111");
	cube->map.map2d[9] = NULL;
	cube->map.p_y = 3;
	cube->map.p_x = 14;
	cube->map.w_map = 25;
	cube->map.h_map = 9;
	return (1);
}
