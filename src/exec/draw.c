/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:33:54 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/09 02:27:11 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_floor_ceiling(t_cube *cube, int ray, int top_pix, int bottom_pix)
{
	int	i;

	i = bottom_pix;
	while (i < SCREEN_HEIGHT)
		ft_mlx_pixel_put(cube, ray, i++, cube->texture.floor); // floor
	i = 0;
	while (i < top_pix)
		ft_mlx_pixel_put(cube, ray, i++, cube->texture.ceiling); // sky
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
			return (KAKI_PIXEL);//printf("here bro\n"),cube->texture.texture_way[2]);
		else
			return (KAKI_PIXEL);//cube->texture.texture_way[3]);
	}
	else
	{
		if (cube->ray.ray_ngl > 0 && cube->ray.ray_ngl < M_PI)
			return (KAKI_PIXEL);//cube->texture.texture_way[1]);
		else
			return (KAKI_PIXEL);//cube->texture.texture_way[0]);
	}
}
typedef struct s_tex
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
}	t_tex;
void	draw_wall(t_cube *cube, int ray, int t_pix, int b_pix)
{
	

	
	const int	color = get_color(cube, cube->ray.flag);

	while (t_pix < b_pix)
		ft_mlx_pixel_put(cube, ray, t_pix++, color);
}

// void	draw_wall(t_mlx *mlx, int t_pix, int b_pix, double wall_h)
// {
// 	double			x_o;
// 	double			y_o;
// 	mlx_texture_t	*texture;
// 	uint32_t		*arr;
// 	double			factor;

// 	texture = get_texture(mlx, mlx->ray->flag);
// 	arr = (uint32_t *)texture->pixels;
// 	factor = (double)texture->height / wall_h;
// 	x_o = get_x_o(texture, mlx);
// 	y_o = (t_pix - (S_H / 2) + (wall_h / 2)) * factor;
// 	if (y_o < 0)
// 		y_o = 0;
// 	while (t_pix < b_pix)
// 	{
// 		my_mlx_pixel_put(mlx, mlx->ray->index, t_pix, reverse_bytes \
// 		(arr[(int)y_o * texture->width + (int)x_o]));
// 		y_o += factor;
// 		t_pix++;
// 	}
// }

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
	draw_wall(cube, ray, top_pix, bottom_pix);
	draw_floor_ceiling(cube, ray, top_pix, bottom_pix);
}
