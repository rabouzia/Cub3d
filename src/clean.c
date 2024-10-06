/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.clean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:57:29 by ramzerk           #+#    #+#             */
/*   Updated: 2024/10/06 02:13:09 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void clean(t_game *game)
{
	(void) game;
	return;	
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

int	quit_click(t_game *d)
{
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
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display((*d).mlx);
		free((*d).mlx);
	}
	exit(1);
}
