/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:34:44 by ramzerk           #+#    #+#             */
/*   Updated: 2024/11/03 20:30:42 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
# include <math.h>

void	ft_display_pixel(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_len + x * (pixel->bpp / 8));
	*(unsigned int *)dst = color;
}


int display_loop(t_pixel *p, t_cube *g ,double facteur, int color)
{
	(void) facteur;
	(void) g;
	
	int i, j;
	i = 0;

	while (i++ < (1920 * facteur))
	{
		j = 0;
		while (j++ < (1080 * facteur))
		{
			ft_display_pixel(p, i, j, color);
		}
	}
	return 1;
}

bool	raycasting(t_cube *g, double facteur, int color)
{
	(void)g;
	(void)facteur;
	(void)color;
	// t_pixel	p;

	// p = g->pixel;
	// p.img = mlx_new_image(g->mlx, 1920, 1080);

		// display_loop(&p ,g, facteur, color);
			
	return (1);
}

void	ft_reles(mlx_key_data_t keydata, t_cube *mlx)	// release the key
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		mlx->player->l_r = 0;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		mlx->player->l_r = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		mlx->player->u_d = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		mlx->player->u_d = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		mlx->player->rot = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		mlx->player->rot = 0;
}

int mlx_key(mlx_key_data_t keydata, void *ml)	// key press
{
	t_cube	*mlx;

	mlx = ml;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)) // exit the game
		ft_exit(mlx);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS)) // move left
		mlx->player->l_r = -1;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS)) // move right
		mlx->player->l_r = 1;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS)) // move down
		mlx->player->u_d = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS) // move up
		mlx->player->u_d = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS) // rotate left
		mlx->player->rot = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS) // rotate right
		mlx->player->rot = 1;
	ft_reles(keydata, mlx); // release the key
	return 0;
}

void	rotate_player(t_cube *mlx, int i)	// rotate the player
{
	if (i == 1)
	{
		mlx->player->angle += ROTATION_SPEED; // rotate right
		if (mlx->player->angle > 2 * M_PI)
			mlx->player->angle -= 2 * M_PI;
	}
	else
	{
		mlx->player->angle -= ROTATION_SPEED; // rotate left
		if (mlx->player->angle < 0)
			mlx->player->angle += 2 * M_PI;
	}
}

void	move_player(t_cube *mlx, double move_x, double move_y)	// move the player
{
	int		map_grid_y;
	int		map_grid_x;
	int		new_x;
	int		new_y;

	new_x = roundf(mlx->player->plyr_x + move_x); // get the new x position
	new_y = roundf(mlx->player->plyr_y + move_y); // get the new y position
	map_grid_x = (new_x / TILE_SIZE); // get the x position in the map
	map_grid_y = (new_y / TILE_SIZE); // get the y position in the map
	if (mlx->map.map2d[map_grid_y][map_grid_x] != '1' && \
	(mlx->map.map2d[map_grid_y][mlx->player->plyr_x / TILE_SIZE] != '1' && \
	mlx->map.map2d[mlx->player->plyr_y / TILE_SIZE][map_grid_x] != '1')) // check the wall hit and the diagonal wall hit
	{
		mlx->player->plyr_x = new_x; // move the player
		mlx->player->plyr_y = new_y; // move the player
	}
}

void	hook(t_cube *mlx, double move_x, double move_y)	// hook the player
{
	if (mlx->player->rot == 1) //rotate right
		rotate_player(mlx, 1);
	if (mlx->player->rot == -1) //rotate left
		rotate_player(mlx, 0);
	if (mlx->player->l_r == 1) //move right
	{
		move_x = -sin(mlx->player->angle) * PLAYER_SPEED;
		move_y = cos(mlx->player->angle) * PLAYER_SPEED;
	}
	if (mlx->player->l_r == -1) //move left
	{
		move_x = sin(mlx->player->angle) * PLAYER_SPEED;
		move_y = -cos(mlx->player->angle) * PLAYER_SPEED;
	}
	if (mlx->player->u_d == 1) //move up
	{
		move_x = cos(mlx->player->angle) * PLAYER_SPEED;
		move_y = sin(mlx->player->angle) * PLAYER_SPEED;
	}
	if (mlx->player->u_d == -1) //move down
	{
		move_x = -cos(mlx->player->angle) * PLAYER_SPEED;
		move_y = -sin(mlx->player->angle) * PLAYER_SPEED;
	}
	move_player(mlx, move_x, move_y); // move the player
}

void	my_mlx_pixel_put(t_cube *mlx, int x, int y, int color)	// put the pixel
{
	if (x < 0) // check the x position
		return ;
	else if (x >= S_W)
		return ;
	if (y < 0) // check the y position
		return ;
	else if (y >= S_H)
		return ;
	mlx_pixel_put(mlx->mlx, mlx->win, x, y, color); // put the pixel
}

float	nor_angle(float angle)	// normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	draw_floor_ceiling(t_cube *mlx, int ray, int t_pix, int b_pix)	// draw the floor and the ceiling
{
	int		i;

	i = b_pix;
	while (i < S_H)
		my_mlx_pixel_put(mlx, ray, i++, 0xB99470FF); // floor
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(mlx, ray, i++, 0x89CFF3FF); // ceiling
}

int	get_color(t_cube *mlx, int flag)	// get the color of the wall
{
	mlx->ray->ray_ngl = nor_angle(mlx->ray->ray_ngl); // normalize the angle
	if (flag == 0)
	{
		if (mlx->ray->ray_ngl > M_PI / 2 && mlx->ray->ray_ngl < 3 * (M_PI / 2))
			return (0xB5B5B5FF); // west wall
		else
			return (0xB5B5B5FF); // east wall
	}
	else
	{
		if (mlx->ray->ray_ngl > 0 && mlx->ray->ray_ngl < M_PI)
			return (0xF5F5F5FF); // south wall
		else
			return (0xF5F5F5FF); // north wall
	}
}

void	draw_wall(t_cube *mlx, int ray, int t_pix, int b_pix)	// draw the wall
{
	int color;

	color = get_color(mlx, mlx->ray->flag);
	while (t_pix < b_pix)
		my_mlx_pixel_put(mlx, ray, t_pix++, color);
}

void	render_wall(t_cube *mlx, int ray)	// render the wall
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	mlx->ray->distance *= cos(nor_angle(mlx->ray->ray_ngl - mlx->player->angle)); // fix the fisheye
	wall_h = (TILE_SIZE / mlx->ray->distance) * ((S_W / 2) / tan(mlx->player->fov_rd / 2)); // get the wall height
	b_pix = (S_H / 2) + (wall_h / 2); // get the bottom pixel
	t_pix = (S_H / 2) - (wall_h / 2); // get the top pixel
	if (b_pix > S_H) // check the bottom pixel
		b_pix = S_H;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
	draw_wall(mlx, ray, t_pix, b_pix); // draw the wall
	draw_floor_ceiling(mlx, ray, t_pix, b_pix); // draw the floor and the ceiling
}

int	unit_circle(float angle, char c)	// check the unit circle
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

int	inter_check(float angle, float *inter, float *step, int is_horizon)	// check the intersection
{
	if (is_horizon)
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

int	wall_hit(float x, float y, t_cube *cube)	// check the wall hit
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE); // get the x position in the map
	y_m = floor (y / TILE_SIZE); // get the y position in the map
	if ((y_m >= cube->map.h_map || x_m >= cube->map.w_map))
		return (0);
	if (cube->map.map2d[y_m] && x_m <= (int)strlen(cube->map.map2d[y_m]))
		if (cube->map.map2d[y_m][x_m] == '1')
			return (0);
	return (1);
}

float	get_h_inter(t_cube *mlx, float angl)	// get the horizontal intersection
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(mlx->player->plyr_y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = mlx->player->plyr_x + (h_y - mlx->player->plyr_y) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y') && x_step < 0)) // check x_step value
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, mlx)) // check the wall hit whit the pixel value
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - mlx->player->plyr_x, 2) + pow(h_y - mlx->player->plyr_y, 2))); // get the distance
}

float	get_v_inter(t_cube *mlx, float angl)	// get the vertical intersection
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE; 
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(mlx->player->plyr_x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0); // check the intersection and get the pixel value
	v_y = mlx->player->plyr_y + (v_x - mlx->player->plyr_x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x') && y_step > 0)) // check y_step value
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, mlx)) // check the wall hit whit the pixel value
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - mlx->player->plyr_x, 2) + pow(v_y - mlx->player->plyr_y, 2))); // get the distance
}

void	cast_rays(t_cube *mlx)	// cast the rays
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	mlx->ray->ray_ngl = mlx->player->angle - (mlx->player->fov_rd / 2); // the start angle
	while (ray < S_W) // loop for the rays
	{
		mlx->ray->flag = 0; // flag for the wall
		h_inter = get_h_inter(mlx, nor_angle(mlx->ray->ray_ngl)); // get the horizontal intersection
		v_inter = get_v_inter(mlx, nor_angle(mlx->ray->ray_ngl)); // get the vertical intersection
		if (v_inter <= h_inter) // check the distance
			mlx->ray->distance = v_inter; // get the distance
		else
		{
			mlx->ray->distance = h_inter; // get the distance
			mlx->ray->flag = 1; // flag for the wall
		}
		render_wall(mlx, ray); // render the wall
		ray++; // next ray
		mlx->ray->ray_ngl += (mlx->player->fov_rd / S_W); // next angle
	}
}