/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:33:43 by ramzerk           #+#    #+#             */
/*   Updated: 2024/11/08 22:18:14 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	minilibx(t_cube *cube)
{
	if (!win_create(cube))
		return (0);
	if (!setup_win(cube))
		return (0);
	return (1);
}

int	setup_win(t_cube *cube)
{
	int	a; //a check ;
	a = 500;
	cube->pixel.img = mlx_xpm_file_to_image(cube->mlx,
			"/home/rabouzia/Cub3d/src/wall.xpm", &a, &a);
	cube->pixel.addr = mlx_get_data_addr(cube->pixel.img, &cube->pixel.bpp,
			&cube->pixel.line_len, &cube->pixel.endian);
	cube->image.img = mlx_new_image(cube->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cube->image.addr = mlx_get_data_addr(cube->image.img, &cube->image.bpp,
			&cube->image.line_len, &cube->image.endian);
	return (1);
}

bool	win_create(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
		ft_exit(cube);
	cube->win = mlx_new_window(cube->mlx, 1920, 1080, "Cube 3D");
	if (!cube->win)
	{
		mlx_destroy_display(cube->mlx);
		free(cube->mlx);
		return (MLX_ERROR);
	}
	return (1);
}