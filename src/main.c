/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:21:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/06 15:28:48 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_exit(t_cube *cube)
{
	(void)cube;
	// int	i = 0;
	// while (cube->map.map2d[i])
	// // 	free(cube->map.map2d[i++]); // free the map line by line
	// free(cube->map.map2d); // free the map
	// free(cube.map); // free the data structure
	// free(cube->ply); // free the player structure
	// free(cube->ray); // free the ray structure
	// mlx_destroy_image(mlx->mlx_p, mlx->img);
	// mlx_close_window(mlx->win); // close the window
	// mlx_terminate(mlx->mlx_p); // terminate the mlx pointer
	printf("Game closed\n"); // print the message
	exit(0);                 // exit the game
}

int	game_loop(t_cube *cube)
{
	cast_rays(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->image.img, 0, 0);
	inputs(cube);
	return (0);
}

void	init_the_player(t_cube *cube)
{
	cube->player.plyr_x = cube->map.p_x * TILE_SIZE + TILE_SIZE / 2;
	cube->player.plyr_y = cube->map.p_y * TILE_SIZE + TILE_SIZE / 2;
	cube->player.fov_rd = (FOV * M_PI) / 180;
	cube->player.angle = M_PI;
}

int	start_the_game(t_cube *cube)
{
	int	a;

	a = 500;
	cube->mlx = mlx_init();
	if (!cube->mlx)
		exit(1); // todo add ft_escape function
	cube->win = mlx_new_window(cube->mlx, 1920, 1080, "Cube 3D");
	cube->pixel.img = mlx_xpm_file_to_image(cube->mlx,
			"/home/rabouzia/Cub3d/src/wall.xpm", &a, &a);
	cube->pixel.addr = mlx_get_data_addr(cube->pixel.img, &cube->pixel.bpp,
			&cube->pixel.line_len, &cube->pixel.endian);
	cube->image.img = mlx_new_image(cube->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cube->image.addr = mlx_get_data_addr(cube->image.img, &cube->image.bpp,
			&cube->image.line_len, &cube->image.endian);
	init_the_player(cube);
	mlx_hook(cube->win, 2, 1l << 0, &key_press, cube);
	mlx_hook(cube->win, 3, 1l << 1, &key_release, cube);
	mlx_loop_hook(cube->mlx, &game_loop, cube);
	mlx_loop(cube->mlx);
	return (1);
}

void	init_argumet(t_map_info *map)
{
	map->map2d = calloc(10, sizeof(char *));
	map->map2d[0] = strdup("1111111111111111111111111");
	map->map2d[1] = strdup("1000000000000000000100001");
	map->map2d[2] = strdup("1001000000000P00000000001");
	map->map2d[3] = strdup("1001000000000000001000001");
	map->map2d[4] = strdup("100100000000P000001000001");
	map->map2d[5] = strdup("1001000000100000001000001");
	map->map2d[6] = strdup("1001000000000000001000001");
	map->map2d[7] = strdup("1001000000001000001000001");
	map->map2d[8] = strdup("1111111111111111111111111");
	map->map2d[9] = NULL;
	map->p_y = 3;
	map->p_x = 14;
	map->w_map = 25;
	map->h_map = 9;
}

void	init_all(t_cube *cube)
{
	cube->map.p_x = 0;
	cube->map.p_y = 0;
	cube->map.w_map = 0;
	cube->map.h_map = 0;
	cube->map.map2d = NULL;
	cube->pixel.addr = 0;
	cube->pixel.bpp = 0;
	cube->pixel.endian = 0;
	cube->pixel.img = 0;
	cube->pixel.line_len = 0;
	cube->player.angle = 0;
	cube->player.fov_rd = 0;
	cube->player.l_r = 0;
	cube->player.plyr_x = 0;
	cube->player.plyr_y = 0;
	cube->player.rot = 0;
	cube->player.u_d = 0;
	cube->ray.distance = 0;
	cube->ray.flag = 0;
	cube->ray.ray_ngl = 0;
	cube->fd = 0;
	cube->mlx = NULL;
	cube->win = NULL;
	cube->tab_map = NULL;
}

int	main(void)
{
	t_cube	cube;

	memset(&cube, 0, sizeof(t_cube));
	init_all(&cube);
	init_argumet(&cube.map);
	start_the_game(&cube);
	return (0);
	// int	main(int ac, char **av)
	// {
	// 	t_game	game;
	// 	(void)ac;
	// 	(void)av;
	// 	game = (t_game){0};
	// 	if (!minilibx(&game))
	// 		return (0);
	// if (!raycasting(&game))
	// 	return (0);
	//
}
/*

	TODO texture:
	- find texture for the wall, ceiling and floor
	- be able to change the texture
	TODO controls:
	- left and right arrow for the camera
	- WASD to move
	TODO map:
	- must be 1 0 W D S E W
	- must be close (0 not surround by anything but P or 1)
	-

	TODO pixel:
	-	refaire mlx put pixel

	*/