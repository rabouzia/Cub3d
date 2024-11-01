/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:21:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/01 00:00:21 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	fill_struct(t_game *game, char **av)
{
	game->av = av;
}

	// if (key == RIGHT)
		
	// if (key == LEFT)
	// 	return (1);



	// fill_struct(&game, av);
	// // printf("here\n");
	// // if (!parsing(&game))
	// // 	return (0);



int	input(int key, t_game *data)
{
	(void) data;
	// printf("key %d\n", key);
	// if (key == XK_Escape)
	// 	quit_esc(data);
	static double facteur = 1.0; 
	 if (key == UP) 
	{
		// printf("up %d\n", key);

		facteur /= 1 - 0.003; 
		raycasting(data, facteur, BLUE_PIXEL);
	}
	// else if (key == DOWN) 
	// {

	// 	// printf("down %d\n", key);
	// 	facteur *= 1 - 0.003; 
	// 	raycasting(data, facteur, RED_PIXEL);
	// }

	return (1);
}
	
int	main(int ac, char **av)
{
	t_game	game;

	(void)ac;
	(void)av;
	game = (t_game){0};
	if (!minilibx(&game))
		return (0);
	// if (!raycasting(&game))
	// 	return (0);
	mlx_loop_hook(game.mlx , &input, &game);
	mlx_hook(game.win, 17, 0, quit_click, &game);
	mlx_loop(game.mlx);
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
