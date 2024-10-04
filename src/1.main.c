/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:21:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/04 10:57:06 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void fill_struct(t_game *game, char**av)
{
	game->av = av;
}

int	main(int ac, char **av)
{
	t_game	game;
	game = (t_game){0};

	fill_struct(&game);
	if (!parsing(&game))
		return (0);
	if (!minilib(&game))
		return (0);
	if (raycasting(&game))
		return (0);
	mlx_key_hook(game.win, input, &game);
	mlx_hook(game.win, 17, 0, quit_click, &game);
	mlx_loop(game.mlx);	
	clean();
}
