/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:36:40 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/10 21:18:11 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_extension(char *line, char *extension)
{
	int	i;
	int	ex_len;

	ex_len = ft_strlen(extension);
	i = 0;
	while (line[i])
		i++;
	if (i < ex_len + 1)
		return (0);
	i -= ex_len;
	return (!strncmp(&line[i], extension, ex_len));
}

int	get_info(t_cube *cube, char *line)
{
	static char	*prefixes[6] = {"NO ", "SO ", "EA ", "WE ", "C ", "F "};
	int			i;

	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(line, prefixes[i], 3 - (i >= 4)))
		{
			if (i >= 4)
			{
				if (!get_rgb(cube, line, &cube->texture_way[i]))
					ft_end(cube, "rgb error");
			}
			else
			{
				if (!get_path(cube, line, &cube->texture_way[i]))
					ft_end(cube, "texture error");
			}
			return (1);
		}
		i++;
	}
	return (0);
}