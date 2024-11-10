/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:33:54 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/10 18:56:02 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_floor_ceiling(t_cube *cube, int ray, int top_pix, int bottom_pix)
{
	int	i;

	i = bottom_pix;
	while (i < SCREEN_HEIGHT)
		ft_mlx_pixel_put(cube, ray, i++, cube->texture_way[5].f_or_c); // floor
	i = 0;
	while (i < top_pix)
		ft_mlx_pixel_put(cube, ray, i++, cube->texture_way[4].f_or_c); // sky
}

// void	ft_init_textures(t_cube *cube)
// {
// 	cube->texture.texture_way[0] = *ft_get_texture_pxl(cube->texture.north);
// 	cube->texture.texture_way[1] = *ft_get_texture_pxl(cube->texture.south);
// 	cube->texture.texture_way[2] = *ft_get_texture_pxl(cube->texture.west);
// 	cube->texture.texture_way[3] = *ft_get_texture_pxl(cube->texture.east);
// }

int	get_color(t_cube *cube, int flag)
{
	cube->ray.ray_ngl = nor_angle(cube->ray.ray_ngl);
	if (flag == 0)
	{
		if (cube->ray.ray_ngl > M_PI / 2 && cube->ray.ray_ngl < 3 * (M_PI / 2))
			return (KAKI_PIXEL);
		// printf("here bro\n"),cube->texture.texture_way[2]); west
		else
			return (KAKI_PIXEL); // cube->texture.texture_way[3]); east
	}
	else
	{
		if (cube->ray.ray_ngl > 0 && cube->ray.ray_ngl < M_PI)
			return (RED_PIXEL); // cube->texture.texture_way[1]); south
		else
			return (GREY_PIXEL); // cube->texture.texture_way[0]); north
	}
}

// void	draw_wall(t_cube *cube, int ray, int t_pix, int b_pix)
// {
// 	const int	color = get_color(cube, cube->ray.flag);

// 	while (t_pix < b_pix)
// 		ft_mlx_pixel_put(cube, ray, t_pix++, color);
// }

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
		// printf("here bro\n"),cube->texture.texture_way[2]); west
		else
			return (cube->texture_way[2]);
		// cube->texture.texture_way[3]); east
	}
	else
	{
		if (cube->ray.ray_ngl > 0 && cube->ray.ray_ngl < M_PI)
			return (cube->texture_way[1]);
		// cube->texture.texture_way[1]); south
		else
			return (cube->texture_way[0]);
		// cube->texture.texture_way[0]); north
	}
}

int	reverse_bytes(int c)
{
	unsigned int	b;

	b = c;
	// b = 0;
	// b |= (c & 0x000000FF) << 24;
	// b |= (c & 0x0000FF00) << 8;
	// b |= (c & 0x00FF0000) >> 8;
	// b |= (c & 0xFF000000) >> 24;
	return (b);
}

void	draw_wall(t_cube *cube, int t_pix, int b_pix, double wall_h)
{
	double			x_o;
	double			y_o;
	t_pixel			texture;
	unsigned int	*arr;
	double			factor;

	texture = get_right_texture(cube);
	// mlx_put_image_to_window(cube->mlx, cube->win, texture.img, 0, 0);
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
				- cube->player.angle)); // fix the fisheye
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
