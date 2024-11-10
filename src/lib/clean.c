/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:57:29 by ramzerk           #+#    #+#             */
/*   Updated: 2024/11/10 20:40:06 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_end(t_cube *cube, char *str)
{
	(void)cube;
	// int	i = 0;
	// while (cube->map.tab_map[i])
	// 	free(cube->map.tab_map[i++]);
	// free(cube->map.tab_map);
	// free(cube.map);
	// free(cube->ply);
	// free(cube->ray);
	// mlx_destroy_image(mlx->mlx_p, mlx->img);
	// mlx_close_window(mlx->win);
	// mlx_terminate(mlx->mlx_p);
	printf("lst arg cleared\n");
	ft_argclear(cube->arg);
	printf("%s\n", str);
	exit(0);
}

void clean(t_cube *cube)
{
	(void) cube;
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

int	quit_click(t_cube *d)
{
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display((*d).mlx);
		free((*d).mlx);
	}
	// free_map(d->map);
	exit(1);
	return (0);
}

void	quit_esc(t_cube *d)
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
