/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:29:06 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/15 14:45:49 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	parsing(t_cube *cube, char **av)
{
	cube->av = av;
	if (!read_cub(cube))
		return (0);
	if (!flood_fill(cube->map.tab_map))
		return (ft_end(cube, "nice try, map not closed"), 0);
	if (!letter_check(cube))
		return (0);
	printarg(cube->arg);
	if (!init_the_player(cube))
		return (0);
	return (1);
}

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_strlen(tab[i]);
		i++;
	}
	return (i);
}

int	collumlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

bool	is_in_charset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (true);
		i++;
	}
	return (false);
}

bool	check_around_tile(char **map, int x, int y)
{
	if (x == 0 || y == 0 || x >= ft_strlen(map[y]) - 1 || y >= collumlen(map)
		- 1)
		return (false);
	if (ft_strlen(map[y + 1]) <= x)
		return (false);
	if (is_in_charset(map[y + 1][x], "01NSWE") == false)
		return (false);
	if (ft_strlen(map[y - 1]) <= x)
		return (false);
	if (is_in_charset(map[y - 1][x], "01NSWE") == false)
		return (false);
	if (is_in_charset(map[y][x + 1], "01NSWE") == false)
		return (false);
	if (is_in_charset(map[y][x - 1], "01NSWE") == false)
		return (false);
	return (true);
}

bool	flood_fill(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_in_charset(map[y][x], "0NSWE"))
			{
				if (check_around_tile(map, x, y) == false)
					return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}
int	game_loop(t_cube *cube)
{
	cast(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->image.img, 0, 0);
	inputs(cube);
	return (0);
}

int	init_the_player(t_cube *cube)
{
	cube->player.plyr_x = cube->map.p_x * TILE_SIZE + TILE_SIZE / 2;
	cube->player.plyr_y = cube->map.p_y * TILE_SIZE + TILE_SIZE / 2;
	cube->player.fov_rd = (FOV * M_PI) / 180;
	return (1);
}
