/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:21:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/30 17:58:02 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	fill_struct(t_game *game, char **av)
{
	game->av = av;
}

int	input(int key, t_game *data)
{
	if (key == XK_Escape)
		quit_esc(data);
	if (key == RIGHT)
		return (1);
	if (key == LEFT)
		return (1);
	if (key == UP)
		return (1);
	if (key == DOWN)
		return (1);
	return (1);
}

void print_tab(char **tab)
{
	int i =0 ;
	while(tab[i])
	{
		printf("%s\n",tab[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;
	if (ac != 2)
		return 0;
	game = (t_game){0};
	fill_struct(&game, av);
	// printf("here\n");
	if (!parsing(&game))
		return (0);
	if (!minilibx(&game))
		return (0);
	if (!raycasting(&game))
		return (0);
	mlx_key_hook(game.win, input, &game);
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

	TODO
	-	refaire mlx put pixel
		
	*/
