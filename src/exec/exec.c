/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:34:44 by ramzerk           #+#    #+#             */
/*   Updated: 2024/11/09 14:24:26 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

int	raycasting(t_cube *cube)
{
	if (!init_the_player(cube))
		return (0);
	mlx_hook(cube->win, 2, 1l << 0, &key_press, cube);
	mlx_hook(cube->win, 3, 1l << 1, &key_release, cube);
	mlx_loop_hook(cube->mlx, &game_loop, cube);
	mlx_loop(cube->mlx);
	return (1);
}

void	cast(t_cube *cube)
{
	double	horiz_inter;
	double	vertic_inter;
	int		ray;

	ray = 0;
	cube->ray.ray_ngl = cube->player.angle - (cube->player.fov_rd / 2);
	while (ray < SCREEN_WIDTH)
	{
		cube->ray.flag = 0;
		horiz_inter = get_horizontal_intersection(cube,
				nor_angle(cube->ray.ray_ngl));
		// write(1, "HERE2\n", 6);
		vertic_inter = get_vertical_intersection(cube,
				nor_angle(cube->ray.ray_ngl));
		if (vertic_inter <= horiz_inter)
			cube->ray.distance = vertic_inter;
		else
		{
			cube->ray.distance = horiz_inter;
			cube->ray.flag = 1;
		}
		render_wall(cube, ray);
		ray++;
		cube->ray.ray_ngl += (cube->player.fov_rd / SCREEN_WIDTH);
	}
}
