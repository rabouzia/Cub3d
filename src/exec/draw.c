/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:33:54 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/15 15:46:20 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_floor_ceiling(t_cube *cube, int ray, int top_pix, int bottom_pix)
{
	int	i;

	i = bottom_pix;
	while (i < SCREEN_HEIGHT)
		ft_mlx_pixel_put(cube, ray, i++, cube->texture_way[5].f_or_c);
	i = 0;
	while (i < top_pix)
		ft_mlx_pixel_put(cube, ray, i++, cube->texture_way[4].f_or_c);
}

double	get_x_o(t_pixel *texture, t_cube *cube)
{
	double	x_o;

	if (cube->ray.flag == 1)
		x_o = (int)fmodf((cube->ray.horiz_x * (texture->pix_w / TILE_SIZE)),
				texture->pix_w);
	else
		x_o = (int)fmodf((cube->ray.vert_y * (texture->pix_w / TILE_SIZE)),
				texture->pix_w);
	return (x_o);
}

t_pixel	get_right_texture(t_cube *cube)
{
	cube->ray.ray_ngl = nor_angle(cube->ray.ray_ngl);
	if (cube->ray.flag == 0)
	{
		if (cube->ray.ray_ngl > M_PI / 2 && cube->ray.ray_ngl < 3 * (M_PI / 2))
			return (cube->texture_way[3]);
		else
			return (cube->texture_way[2]);
	}
	else
	{
		if (cube->ray.ray_ngl > 0 && cube->ray.ray_ngl < M_PI)
			return (cube->texture_way[1]);
		else
			return (cube->texture_way[0]);
	}
}

void	draw_wall(t_cube *cube, int t_pix, int b_pix, double wall_h)
{
	double			x_o;
	double			y_o;
	t_pixel			texture;
	unsigned int	*arr;
	double			factor;

	texture = get_right_texture(cube);
	arr = (unsigned int *)texture.addr;
	factor = (double)texture.pix_h / wall_h;
	x_o = get_x_o(&texture, cube);
	y_o = (t_pix - (SCREEN_HEIGHT / 2) + (wall_h / 2)) * factor;
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		ft_mlx_pixel_put(cube, cube->ray.index, t_pix,
			reverse_bytes(arr[(int)y_o * texture.pix_w + (int)x_o]));
		y_o += factor;
		t_pix++;
	}
}

void	render_wall(t_cube *cube, int ray)
{
	double	wall_height;
	double	bottom_pix;
	double	top_pix;

	cube->ray.distance *= cos(nor_angle(cube->ray.ray_ngl
				- cube->player.angle));
	wall_height = (TILE_SIZE / cube->ray.distance) * ((SCREEN_WIDTH / 2)
			/ tan(cube->player.fov_rd / 2));
	bottom_pix = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	top_pix = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	if (bottom_pix > SCREEN_HEIGHT)
		bottom_pix = SCREEN_HEIGHT;
	if (top_pix < 0)
		top_pix = 0;
	cube->ray.index = ray;
	draw_wall(cube, top_pix, bottom_pix, wall_height);
	draw_floor_ceiling(cube, ray, top_pix, bottom_pix);
}
