/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:34:44 by ramzerk           #+#    #+#             */
/*   Updated: 2024/11/06 15:18:04 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>
#define WALL_MARGIN  100.0
void	ft_display_pixel(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_len + x * (pixel->bpp / 8));
	*(unsigned int *)dst = color;
}

// int display_loop(t_pixel *p, t_cube *g ,double facteur, int color)
// {
// 	(void) facteur;
// 	(void) g;

// 	int i, j;
// 	i = 0;

// 	while (i++ < (1920 * facteur))
// 	{
// 		j = 0;
// 		while (j++ < (1080 * facteur))mlx_hook(ori->mlxwin, 3, 2L,
// han_inp_release, ori);
// 		{
// 			ft_display_pixel(p, i, j, color);
// 		}
// 	}
// 	return (1);
// }

// bool	raycasting(t_cube *g, double facteur, int color)
// {
// 	(void)g;
// 	(void)facteur;
// 	(void)color;
// 	// t_pixel	p;

// 	// p = g->pixel;
// 	// p.img = mlx_new_image(g->mlx, 1920, 1080);

// 		// display_loop(&p ,g, facteur, color);

// 	return (1);
// }

// void	ft_reles(mlx_key_data_t keydata, t_cube *cube)
// release the key
// {
// 	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
// 		cube->player.l_r = 0;
// 	else if (keydata.key == MLX_KEY_A
// && (keydata.action == MLX_RELEASE))
// 		cube->player.l_r = 0;
// 	else if (keydata.key == MLX_KEY_S
// && (keydata.action == MLX_RELEASE))
// 		cube->player.u_d = 0;
// 	else if (keydata.key == MLX_KEY_W
// && (keydata.action == MLX_RELEASE))
// 		cube->player.u_d = 0;
// 	else if (keydata.key == MLX_KEY_LEFT
// && keydata.action == MLX_RELEASE)
// 		cube->player.rot = 0;
// 	else if (keydata.key == MLX_KEY_RIGHT
// && keydata.action == MLX_RELEASE)
// 		cube->player.rot = 0;
// }

int	key_press(int key, t_cube *cube)
{
	if (key == XK_Escape || key == XK_q)
		ft_exit(cube);
	if (key >= 32 && key < 126)
		cube->inputs[key] = 1;
	if (key == XK_Right)
		cube->inputs[126] = 1;
	if (key == XK_Left)
		cube->inputs[127] = 1;
	return (0);
}

int	key_release(int key, t_cube *cube)
{
	if (key >= 32 && key < 126)
		cube->inputs[key] = 0;
	if (key == XK_Right)
		cube->inputs[126] = 0;
	if (key == XK_Left)
		cube->inputs[127] = 0;
	return (0);
}

double	wrap_angle(double angle)
{
	if (angle >= M_PI * 2.0)
		angle -= M_PI * 2.0;
	if (angle < 0)
		angle += M_PI * 2.0;
	return (angle);
}

int	inputs(t_cube *cube)
{
	printf("angle %f\n", cube->player.angle);
	rotate_player(cube, cube->inputs[126] - cube->inputs[127]);
	if (cube->inputs[XK_w])
		move_player(cube, wrap_angle(cube->player.angle));
	if (cube->inputs[XK_s])
		move_player(cube, wrap_angle(cube->player.angle + M_PI));
	if (cube->inputs[XK_a])
		move_player(cube, wrap_angle(cube->player.angle - (M_PI / 2.0)));
	if (cube->inputs[XK_d])
		move_player(cube, wrap_angle(cube->player.angle + (M_PI / 2.0)));
	return (0);
}

void	rotate_player(t_cube *cube, int i)
{
	cube->player.angle += ROTATION_SPEED * i;
	cube->player.angle = wrap_angle(cube->player.angle);
}

void	move_player(t_cube *cube, double angle)
{
	int		map_grid_y;
	int		map_grid_x;
	double	new_x;
	double	new_y;

	new_x = (cube->player.plyr_x + cos(angle));
	new_y = (cube->player.plyr_y + sin(angle));
	map_grid_x = ((int)new_x / TILE_SIZE);
	map_grid_y = ((int)new_y / TILE_SIZE);
	if (cube->map.map2d[map_grid_y][map_grid_x] != '1'
		&& (cube->map.map2d[map_grid_y][(int)cube->player.plyr_x
			/ TILE_SIZE] != '1' && cube->map.map2d[(int)cube->player.plyr_y
			/ TILE_SIZE][map_grid_x] != '1'))
	{
		cube->player.plyr_x = new_x;
		cube->player.plyr_y = new_y;
	}
}

void	ft_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= SCREEN_WIDTH)
		return ;
	if (y < 0)
		return ;
	else if (y >= SCREEN_HEIGHT)
		return ;
	ft_display_pixel(&cube->image, x, y, color);
}

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	draw_floor_ceiling(t_cube *cube, int ray, int t_pix, int b_pix)
{
	int	i;

	i = b_pix;
	while (i < SCREEN_HEIGHT)
		ft_mlx_pixel_put(cube, ray, i++, BLUE_PIXEL);
	i = 0;
	while (i < t_pix)
		ft_mlx_pixel_put(cube, ray, i++, 0x799623);
}

int	get_color(t_cube *cube, int flag)
{
	cube->ray.ray_ngl = nor_angle(cube->ray.ray_ngl);
	// normalize the angle
	if (flag == 0)
	{
		if (cube->ray.ray_ngl > M_PI / 2 && cube->ray.ray_ngl < 3 * (M_PI / 2))
			return (WEST_WALL);
		else
			return (EAST_WALL);
	}
	else
	{
		if (cube->ray.ray_ngl > 0 && cube->ray.ray_ngl < M_PI)
			return (SOUTH_WALL);
		else
			return (NORTH_WALL);
	}
}

void	draw_wall(t_cube *cube, int ray, int t_pix, int b_pix)
{
	int	color;

	color = get_color(cube, cube->ray.flag);
	while (t_pix < b_pix)
		ft_mlx_pixel_put(cube, ray, t_pix++, color);
}

void	render_wall(t_cube *cube, int ray) // render the wall
{
	double wall_h;
	double b_pix;
	double t_pix;

	cube->ray.distance *= cos(nor_angle(cube->ray.ray_ngl- cube->player.angle));                    // fix the fisheye
	wall_h = (TILE_SIZE / cube->ray.distance) * ((SCREEN_WIDTH / 2)
			/ tan(cube->player.fov_rd / 2)); // get the wall height
	b_pix = (SCREEN_HEIGHT / 2) + (wall_h / 2);
	// get the bottom pixel
	t_pix = (SCREEN_HEIGHT / 2) - (wall_h / 2);
	// get the top pixel
	if (b_pix > SCREEN_HEIGHT)
		// check the bottom pixel
		b_pix = SCREEN_HEIGHT;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
	draw_wall(cube, ray, t_pix, b_pix); // draw the wall
	draw_floor_ceiling(cube, ray, t_pix, b_pix);
	// draw the floor and the ceiling
}

int	unit_circle(float angle, char c) // check the unit circle
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int	inter_check(float angle, float *inter, float *step,
		int iSCREEN_HEIGHTorizon)
{
	if (iSCREEN_HEIGHTorizon)
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

int	wall_hit(float x, float y, t_cube *cube)
{
	int	x_m;
	int	y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor(x / TILE_SIZE); // get the x position in the map
	y_m = floor(y / TILE_SIZE); // get the y position in the map
	if ((y_m >= cube->map.h_map || x_m >= cube->map.w_map))
		return (0);
	if (cube->map.map2d[y_m] && x_m <= (int)strlen(cube->map.map2d[y_m]))
		if (cube->map.map2d[y_m][x_m] == '1')
			return (0);
	return (1);
}

float	get_horizontal_intersection(t_cube *cube, float angl)
// get the horizontal intersection
{
	float h_x;
	float h_y;
	float x_step;
	float y_step;
	int pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(cube->player.plyr_y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = cube->player.plyr_x + (h_y - cube->player.plyr_y) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y')
			&& x_step < 0))
		// check x_step value
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, cube))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - cube->player.plyr_x, 2) + pow(h_y
				- cube->player.plyr_y, 2))); // get the distance
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
	// check the intersection and get the pixel value
	v_y = cube->player.plyr_y + (v_x - cube->player.plyr_x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x')
			&& y_step > 0))
		// check y_step value
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, cube))
	// check the wall hit whit the pixel value
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - cube->player.plyr_x, 2) + pow(v_y
				- cube->player.plyr_y, 2))); // get the distance
}

void	cast_rays(t_cube *cube)
{
	double h_inter;
	double v_inter;
	int ray;

	ray = 0;
	cube->ray.ray_ngl = cube->player.angle - (cube->player.fov_rd / 2);
	// the start angle
	while (ray < SCREEN_WIDTH)
	// loop for the rays
	{
		cube->ray.flag = 0;
		// flag for the wall
		h_inter = get_horizontal_intersection(cube,
				nor_angle(cube->ray.ray_ngl));
		// get the horizontal intersection
		v_inter = get_vertical_intersection(cube, nor_angle(cube->ray.ray_ngl));
		// get the vertical intersection
		if (v_inter <= h_inter)
			// check the distance
			cube->ray.distance = v_inter;
		// get the distance
		else
		{
			cube->ray.distance = h_inter; // get the distance
			cube->ray.flag = 1;           // flag for the wall
		}
		render_wall(cube, ray);
		// render the wall
		ray++;
		// next ray
		cube->ray.ray_ngl += (cube->player.fov_rd / SCREEN_WIDTH);
		// next angle
	}
}