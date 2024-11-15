/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:37:54 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/15 15:39:44 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_lst(t_cube *cube, char *file)
{
	int		fd;
	char	*line;
	int		flag;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		flag = flag_line(line);
		if (flag == TRASH)
			return (free(line), 0);
		ft_argaddback(&(cube->arg), ft_argnew(line, flag));
		free(line);
	}
	close(fd);
	return (1);
}

void	replace(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == ' ')
				tab[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	fill_map(t_cube *cube)
{
	t_arg	*lst;
	int		i;

	cube->map.tab_map = ft_calloc(cube->map.columns + 1, sizeof(char *));
	lst = cube->arg;
	i = -1;
	while (lst)
	{
		if (lst->type == MAP)
		{
			cube->map.tab_map[++i] = lst->content;
			if (lst->next != NULL && lst->next->type != MAP)
				return (0);
		}
		lst = lst->next;
	}
	replace(cube->map.tab_map);
	return (1);
}

void	fill_info(t_cube *cube)
{
	t_arg	*lst;

	lst = cube->arg;
	while (lst)
	{
		if (lst->type == INFO)
			get_info(cube, lst->content);
		lst = lst->next;
	}
}

int	flag_line(char *str)
{
	char	c;

	c = str[1];
	if (str[0] == '\0' || str[0] == '\t')
		return (SPACE);
	if (str[0] == '1' && (c == '1' || c == '0' || c == ' ' || c == 'N'))
		return (MAP);
	if (str[0] == '1' && (c == 'E' || c == 'W' || c == 'S'))
		return (MAP);
	if ((str[0] == 'N' || str[0] == 'S') && c == 'O')
		return (INFO);
	if (str[0] == 'E' && c == 'A')
		return (INFO);
	if (str[0] == 'W' && c == 'E')
		return (INFO);
	if ((str[0] == 'F' || str[0] == 'C') && (c == ' '))
		return (INFO);
	return (TRASH);
}
