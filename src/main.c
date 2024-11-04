/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:21:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/04 17:07:39 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h" // include the mlx library
// void	fill_struct(t_game *game, char **av)
// {
// 	game->av = av;
// }

// if (key == RIGHT)

// if (key == LEFT)
// 	return (1);

// fill_struct(&game, av);
// printf("here\n");
// if (!parsing(&game))
// 	return (0);

// int	input(int key, t_game *data)
// {
// 	(void) data;
// printf("key %d\n", key);
// if (key == XK_Escape)
// 	quit_esc(data);
// 	static double facteur = 1.0;
// 		if (key == UP)
// 	{
// printf("up %d\n", key);

// 		facteur /= 1 - 0.003;
// 		raycasting(data, facteur, BLUE_PIXEL);
// 	}
// else if (key == DOWN)
// {

// printf("down %d\n", key);
// 	facteur *= 1 - 0.003;
// 	raycasting(data, facteur, RED_PIXEL);
// }

// 	return (1);
// }

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
// before you start,
// you need to incude the mlx library in your file
// for compiling the code you need to include the required frameworks and the libmlx.a amd link the glfw library
// the flag (-O3 -ffast-math) is for optimization
// the flag (-framework) is for the required frameworks
// the flag (-lglfw) is for linking the glfw library
// the flag (-L) is for the path to the glfw library
// the flag (-o) is for the name of the executable file
// to run the program (./cub)

// example:
// cc -O3 -ffast-math -framework Cocoa -framework OpenGL -framework IOKit

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MLX42.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:29:06 by W2Wizard          #+#    #+#             */
/*   Updated: 2023/11/29 19:47:58 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void	ft_exit(t_cube *cube) // exit the game
{
	(void)cube;
	// int	i = 0;
	// while (cube->map.map2d[i])
	// // 	free(cube->map.map2d[i++]); // free the map line by line
	// free(cube->map.map2d); // free the map
	// free(cube.map); // free the data structure
	// free(cube->ply); // free the player structure
	// free(cube->ray); // free the ray structure
	// // mlx_destroy_image(mlx->mlx_p, mlx->img); // delete the image
	// mlx_close_window(mlx->mlx_p); // close the window
	// mlx_terminate(mlx->mlx_p); // terminate the mlx pointer
	printf("Game closed\n"); // print the message
	exit(0);                 // exit the game
}

int	game_loop(t_cube *cube) // game loop
{
	// cube->pixel.img = mlx_new_image(cube->mlx, S_W, S_H);
	// printf("hey listen %d\n", S_W);
	hook(cube, 0, 0);
	cast_rays(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->image.img, 0, 0);
	// mlx_clear_window(cube->mlx, cube->win);
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
	cube->win = mlx_new_window(cube->mlx, 1920, 1080, "Cube 3D");
	cube->pixel.img = mlx_xpm_file_to_image(cube->mlx,
			"/home/rabouzia/Cub3d/src/wall.xpm", &a, &a);
	cube->pixel.addr = mlx_get_data_addr(cube->pixel.img, &cube->pixel.bpp,
			&cube->pixel.line_len, &cube->pixel.endian);
	cube->image.img = mlx_new_image(cube->mlx, S_W, S_H);
	cube->image.addr = mlx_get_data_addr(cube->image.img, &cube->image.bpp,
			&cube->image.line_len, &cube->image.endian);
	init_the_player(cube);
	mlx_hook(cube->mlx, 0, 1, &mlx_key, cube);
	// mlx_key_hook(cube->mlx, &mlx_key, &cube);
	mlx_hook(cube->win, 17, 0, &mlx_key, &cube);
	mlx_loop_hook(cube->mlx, &game_loop, cube);
	mlx_loop(cube->mlx);
	/*
		mlx_hook(ori->mlxwin, 3, 2L, han_inp_release, ori);
		mlx_hook(ori->mlxwin, 2, 1L, han_inp_press, ori);
		mlx_hook(ori->mlxwin, 17, 0, brexit_key, ori);
		mlx_hook(ori->mlxwin, MotionNotify, PointerMotionMask, han_mouse_move,
			ori);
		mlx_loop_hook(ori->mlxptr, raycasting, ori);
		mlx_loop(ori->mlxptr);
	*/
	return (1);
}
// mlx_loop_hook(game.mlx , &input, &game);
// 	mlx_hook(game.win, 17, 0, quit_click, &game);
// 	mlx_loop(game.mlx);
// }

void	init_argumet(t_map_info *map) // init the data structure
{
	map->map2d = calloc(10, sizeof(char *));
	map->map2d[0] = strdup("1111111111111111111111111");
	map->map2d[1] = strdup("1000000000000000000100001");
	map->map2d[2] = strdup("1001000000000P00000000001");
	map->map2d[3] = strdup("1001000000000000001000001");
	map->map2d[4] = strdup("1001000000000000001000001");
	map->map2d[5] = strdup("1001000000100000001000001");
	map->map2d[6] = strdup("1001000000000000001000001");
	map->map2d[7] = strdup("1001000000001000001000001");
	map->map2d[8] = strdup("1111111111111111111111111");
	map->map2d[9] = NULL;
	map->p_y = 3;    // player y position in the map
	map->p_x = 14;   // player x position in the map
	map->w_map = 25; // map wimaph
	map->h_map = 9;  // map height
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
	t_cube cube;

	memset(&cube, 0, sizeof(t_cube));
	init_all(&cube);
	init_argumet(&cube.map);
	start_the_game(&cube);
	return (0);
}