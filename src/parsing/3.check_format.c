/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.check_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:50:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/10/06 02:18:58 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_extension(char *cub)
{
	if (ft_strstr(cub, ".cub"))
		return (0);
	return (1);
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

int	read_cub(t_game *data)
{
	int		i;
	int		j;
	char	*line;

	if (!check_extension(data->av[2]))
		return (ft_putstr_fd("Error\nWrong file extension\n", 1), 0);
	i = 0;
	j = nb_ligne(data->av[2]);
	data->fd = open(data->av[2], O_RDONLY, 0664);
	data->map = ft_calloc(j + 1, sizeof(char *));
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			break ;
		free(line);
		i++;
	}
	if (!init_init(data))
		return (0);
	return (1);
}
int	is_map_valid(t_game *m)
{
	if (!m->map || !(*m->map))
		return (return_map_error("Error\n Empty map\n", m), 0);
	if ((m->count.lines / 64 < 5) && m->count.columns / 64 < 5)
		return (return_map_error("Error\n Too small\n", m), 0);
	if ((m->count.lines / 64 > 21) && m->count.columns / 64 > 40)
		return (return_map_error("Error\n Too BIG\n", m), 0);
	if (!size_checking(m))
		return (return_map_error("Error\nWrong size\n", m), 0);
	if (!character_checker(m))
		return (return_map_error("Error\nWrong char\n", m), 0);
	if (!wall_check_up_down(m))
		return (return_map_error("Error\nWrong char up and down\n", m), 0);
	if (!wall_check_side(m))
		return (return_map_error("Error\nWrong side char\n", m), 0);
	if (!check_path(m))
		return (return_map_error("Error\nNo way bro o_o\n", m));
	return (1);
}