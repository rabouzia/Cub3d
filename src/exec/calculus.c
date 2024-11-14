/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:37:09 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/15 00:46:48 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	wall_hit(float x, float y, t_cube *cube)
{
	int	x_m;
	int	y_m;

	x_m = floor(x / TILE_SIZE);
	y_m = floor(y / TILE_SIZE);
	if (x_m < 0 || y_m < 0)
		return (0);
	if (y_m >= cube->map.columns || x_m >= cube->map.rows)
		return (0);
	if (cube->map.tab_map[y_m] && x_m <= (int)ft_strlen(cube->map.tab_map[y_m]))
		if (cube->map.tab_map[y_m][x_m] == '1'
			|| cube->map.tab_map[y_m][x_m] == ' ')
			return (0);
	return (1);
}

float	get_horizontal_intersection(t_cube *cube, float angl)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(cube->player.plyr_y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = cube->player.plyr_x + (h_y - cube->player.plyr_y) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y')
			&& x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, cube))
	{
		h_x += x_step;
		h_y += y_step;
	}
	cube->ray.horiz_x = h_x;
	cube->ray.horiz_y = h_y;
	return (sqrt(pow(h_x - cube->player.plyr_x, 2) + pow(h_y
				- cube->player.plyr_y, 2)));
}

float	get_vertical_intersection(t_cube *cube, float angl)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(cube->player.plyr_x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0);
	v_y = cube->player.plyr_y + (v_x - cube->player.plyr_x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x')
			&& y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, cube))
	{
		v_x += x_step;
		v_y += y_step;
	}
	cube->ray.vert_x = v_x;
	cube->ray.vert_y = v_y;
	return (sqrt(pow(v_x - cube->player.plyr_x, 2) + pow(v_y
				- cube->player.plyr_y, 2)));
}


int	inter_check(float angle, float *inter, float *step, int is_inter)
{
	if (is_inter)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}
