/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:34:44 by ramzerk           #+#    #+#             */
/*   Updated: 2024/11/15 15:46:28 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

int	quit_click(t_cube *cube)
{
	ft_end(cube, "Red cross clicked");
	return (0);
}

int	raycasting(t_cube *cube)
{
	mlx_hook(cube->win, 17, 0, &quit_click, cube);
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

int	game_loop(t_cube *cube)
{
	cast(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->image.img, 0, 0);
	inputs(cube);
	return (0);
}

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = c;
	return (b);
}
