/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:50:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/07 19:17:26 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

int	nb_ligne(char *file)
{
	int		fd;
	int		i;
	char	*ligne;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		free(ligne);
		i++;
	}
	close(fd);
	return (i);
}

int	check_extension(char *line, char *extension)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i < 5)
		return (0);
	i -= 4;
	while (line[i])
	{
		if (line[i] != extension[i])
			return (0);
		i++;
	}
	return (1);
}

int	get_path(t_cube *cube, char *line, void **way)
{
	int	x;
	int	y;

	if (!check_extension(line, ".xpm"))
		return (0);
	*way = mlx_xpm_file_to_image(cube->mlx, line, &x, &y);
	if (!*way)
		return (0);
	return (1);
}

int	get_rdb(t_cube *cube, char *line, int *way)
{
	char	**color;
	char hexa;
	color = ft_split(line + 3, ',');
	char *res = ft_strdup("0x");
	char_to_hexa(color[0]);
	char_to_hexa(color[1]);
	char_to_hexa(color[2]);
	ft_strjoin4(res, color[0], color[1], color[2]);
	atoi_base(res);
	way = res;
	free(res);
	free(color);
	free(hexa);
	return (1);
}

int	get_info(t_cube *cube, char *line)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (!get_path(cube, line, &cube->texture.north))
			return (printf("Map error\n"), 0);
		return (1);
	}
	if (!ft_strncmp(line, "SO ", 3))
	{
		if (!get_path(cube, line, &cube->texture.south))
			return (printf("Map error\n"), 0);
		return (1);
	}
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (!get_path(cube, line, &cube->texture.east))
			return (printf("Map error\n"), 0);
		return (1);
	}
	if (!ft_strncmp(line, "WE ", 3))
	{
		if (!get_path(cube, line, &cube->texture.west))
			return (printf("Map error\n"), 0);
		return (1);
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		if (!get_rgb(cube, line, &cube->texture.ceiling))
			return (printf("Map error\n"), 0);
		return (1);
	}
	if (!ft_strncmp(line, "F ", 2))
	{
		if (!get_rgb(cube, line, &cube->texture.floor))
			return (printf("Map error\n"), 0);
		return (1);
	}
	return (0);
}

int	read_cub(t_cube *cube)
{
	char	*line;
	int		c;
	int		i;
	int		j;

	c = 0;
	if (!check_extension(cube->av[1]))
		return (ft_putstr_fd("Error\nWrong file extension\n", 1), 0);
	i = 0;
	j = nb_ligne(cube->av[2]);
	cube->fd = open(cube->av[2], O_RDONLY, 0664);
	cube->tab_map = ft_calloc(j + 1, sizeof(char *));
	while (1)
	{
		line = get_next_line(cube->fd);
		c++;
		if (!line)
			break ;
		if (get_info(cube, line) && c < 8)
			continue ;
		if (c < 9)
		{
			free(line);
			continue ;
		}
		cube->tab_map[++i] = ft_strdup(line);
		free(line);
		c++;
	}
	return (1);
}
int	is_map_valid(t_cube *m)
{
	(void)m;
	// if (!m->map || !(*m->map))
	return (ft_putstr_fd("Error\n Empty map\n", 1), 0);
	// 	if ((m->count.lines / 64 < 5) && m->count.columns / 64 < 5)
	// 		return (return_map_error("Error\n Too small\n", m), 0);
	// 	if ((m->count.lines / 64 > 21) && m->count.columns / 64 > 40)
	// 		return (return_map_error("Error\n Too BIG\n", m), 0);
	// 	if (!size_checking(m))
	// 		return (return_map_error("Error\nWrong size\n", m), 0);
	// 	if (!character_checker(m))
	// 		return (return_map_error("Error\nWrong char\n", m), 0);
	// 	if (!wall_check_up_down(m))
	// 		return (return_map_error("Error\nWrong char up and down\n", m), 0);
	// 	if (!wall_check_side(m))
	// 		return (return_map_error("Error\nWrong side char\n", m), 0);
	// 	if (!check_path(m))
	// 		return (return_map_error("Error\nNo way bro o_o\n", m));
	return (1);
}