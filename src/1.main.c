/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:21:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/06 02:10:28 by ramzerk          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game	game;
	if (ac != 2)
		return 0;
	game = (t_game){0};
	fill_struct(&game, av);
	if (!parsing(&game))
		return (0);
	if (!minilibx(&game))
		return (0);
	if (raycasting(&game))
		return (0);
	mlx_key_hook(game.win, input, &game);
	mlx_hook(game.win, 17, 0, quit_click, &game);
	mlx_loop(game.mlx);
}
