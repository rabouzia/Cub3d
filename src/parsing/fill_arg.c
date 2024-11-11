/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:37:54 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/11 13:20:38 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	count_columns(t_cube *cube)
{
	int		column;
	t_arg	*lst;

	lst = cube->arg;
	column = 0;
	while (lst)
	{
		column = ft_strlen(lst->content);
		if (cube->map.columns < column && lst->type == MAP)
			cube->map.columns = column;
		lst = lst->next;
	}
}

void	count_row(t_cube *cube)
{
	int		i;
	t_arg	*lst;

	lst = cube->arg;
	i = 0;
	while (lst)
	{
		if (lst->type == MAP)
			i++;
		lst = lst->next;
	}
	cube->map.rows = cube->map.columns;
}

int	get_lst(t_cube *cube, char *file)
{
	int		fd;
	char	*line;
	t_arg	*lst;
	int		flag;

	lst = cube->arg;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		flag = flag_line(line);
		ft_argaddback(&lst, ft_argnew(line, flag));
		free(line);
	}
	cube->arg = lst;
	close(fd);
	return (1);
}

void	fill_map(t_cube *cube)
{
	t_arg	*lst;
	int		i;

	cube->map.tab_map = ft_calloc(cube->map.columns + 1, sizeof(char *));
	lst = cube->arg;
	i = -1;
	while (lst)
	{
		if (lst->type == MAP)
			cube->map.tab_map[++i] = lst->content;
		lst = lst->next;
	}
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
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1' && (str[i + 1] == '1' || str[i + 1] == '0'))
			return (MAP);
		if (str[i] == '1' && (str[i + 1] == ' ' || str[i + 1] == 'N'))
			return (MAP);
		if (str[i] == '1' && (str[i + 1] == ' ' || str[i + 1] == 'W'))
			return (MAP);
		if (str[i] == '1' && (str[i + 1] == ' ' || str[i + 1] == 'E'))
			return (MAP);
		if (str[i] == '1' && (str[i + 1] == ' ' || str[i + 1] == 'S'))
			return (MAP);
		if (str[i] == 'N' && str[i + 1] == 'O')
			return (INFO);
		if (str[i] == 'S' && str[i + 1] == 'O')
			return (INFO);
		if (str[i] == 'E' && str[i + 1] == 'A')
			return (INFO);
		if (str[i] == 'W' && str[i + 1] == 'E')
			return (INFO);
		if (str[i] == 'F' && str[i + 1] == ' ')
			return (INFO);
		if (str[i] == 'C' && str[i + 1] == ' ')
			return (INFO);
		i++;
	}
	return (TRASH);
}
