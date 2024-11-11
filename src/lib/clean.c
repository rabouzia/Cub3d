/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:57:29 by ramzerk           #+#    #+#             */
/*   Updated: 2024/11/11 12:18:45 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_end(t_cube *cube, char *str)
{
	ft_argclear(cube->arg);
	free(cube->map.tab_map);
	if (cube->texture_way[0].img)
		mlx_destroy_image(cube->mlx, cube->texture_way[0].img);
	if (cube->texture_way[1].img)
		mlx_destroy_image(cube->mlx, cube->texture_way[1].img);
	if (cube->texture_way[2].img)
		mlx_destroy_image(cube->mlx, cube->texture_way[2].img);
	if (cube->texture_way[3].img)
		mlx_destroy_image(cube->mlx, cube->texture_way[3].img);
	mlx_destroy_image(cube->mlx, cube->image.img);
	mlx_destroy_window(cube->mlx, cube->win);
	mlx_destroy_display(cube->mlx);
	free(cube->mlx);
	printf("%s\n", str);
	exit(0);
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
