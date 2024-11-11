/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:29:06 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/11 13:24:46 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	parsing(t_cube *cube, char **av)
{
	cube->av = av;
	// if (!init_argument(cube, av))
	// 	return (0);
	if (!read_cub(cube))
		return (0);
	// print_tab(cube->map.tab_map);
	// if (!is_map_valid(cube))
	// 	return (0);
	if (!letter_check(cube))
		return (0);
	// if (!init_cube(cube))
	// 	return (0);
	init_the_player(cube);
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

char	**ft_copy(char **map)
{
	char	**copied;
	int		i;
	int		len;

	i = 0;
	copied = ft_calloc(sizeof(char *), tab_size(map) + 1);
	if (!copied)
	{
	}
	len = tab_size(map);
	while (i < len)
	{
		copied[i] = ft_strdup(map[i]);
		i++;
	}
	copied[i] = NULL;
	return (copied);
}

bool	flood_fill(char **map, int x, int y)
{
	if (!map[x] || !map[x][y])
		return (false);
	if (map[x][y] == '1')
		return (true);
	map[x][y] = 'X';
	return (flood_fill(map, x + 1, y) && flood_fill(map, x, y + 1)
		&& flood_fill(map, x - 1, y) && flood_fill(map, x, y - 1));
}

bool	is_map_valid(t_cube *cube)
{
	char	**map_copy;
	int		map_p_x;
	int		map_p_y;

	// create map copy
	map_p_x = cube->map.p_x;
	map_p_y = cube->map.p_y;
	map_copy = ft_copy(cube->map.tab_map);
	return (flood_fill(map_copy, map_p_x, map_p_y));
}


// int	flood_fill(t_cube *m)
// {
// 	char	**map;
// 	int		x;
// 	int		y;

// 	x = -1;
// 	map = m->map.tab_map;
// 	while (map[++x])
// 	{
// 		y = -1;
// 		while (map[x][++y])
// 		{
// 			if (map[x][y] == '0')
// 			{
// 				if (!check_surroundings(map, x, y))
// 					return (0);
// 			}
// 		}
// 	}
// 	return (1);
// }
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
	cube->player.angle = M_PI;
	return (1);
}
