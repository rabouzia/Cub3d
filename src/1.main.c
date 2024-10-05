/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:21:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/05 18:39:53 by rabouzia         ###   ########.fr       */
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

int	quit_click(t_game *d)
{
	free_img(d);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display((*d).mlx);
		free((*d).mlx);
	}
	free_map(d->map);
	exit(1);
	return (0);
}

void	quit_esc(t_game *d)
{
	if (d)
		loop_imgcheck(d);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display((*d).mlx);
		free((*d).mlx);
	}
	if (d->map)
		free_map(d->map);
	exit(1);
}

int	main(int ac, char **av)
{
	t_game	game;

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
	clean();
}
