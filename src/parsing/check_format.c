/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:50:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/11 13:19:35 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_path(t_cube *cube, char *line, t_pixel *p)
{
	if (!check_extension(line, ".xpm"))
	{
		free(line);
		ft_end(cube, "extention error <.xpm> ");
	}
	if (p->img)
		ft_end(cube, "same .xpm");
	p->img = mlx_xpm_file_to_image(cube->mlx, line + 5, &p->pix_w, &p->pix_h);
	if (!p->img)
		ft_end(cube, "xpm to img error");
	p->addr = mlx_get_data_addr(p->img, &p->bpp, &p->line_len, &p->endian);
	if (!p->img)
		ft_end(cube, "get data error");
	cube->text_count++;
	return (1);
}

void	color_err(t_cube *cube, char *str, char **color)
{
	free_tab(color);
	ft_end(cube, str);
}

int	get_rgb(t_cube *cube, char *line, t_pixel *way)
{
	char			**color;
	unsigned int	res;
	int				rgb;

	(void)cube;
	color = ft_split(line + 2, ',');
	if (way->f_or_c)
		color_err(cube, "same color", color);
	res = 0;
	rgb = ft_atoi(color[0]);
	if (rgb == -1)
		color_err(cube, "wrong color", color);
	res |= rgb << 16;
	rgb = ft_atoi(color[1]);
	if (rgb == -1)
		color_err(cube, "wrong color", color);
	res |= rgb << 8;
	rgb = ft_atoi(color[2]);
	if (rgb == -1)
		color_err(cube, "wrong color", color);
	res |= rgb;
	free_tab(color);
	way->f_or_c = res;
	cube->color_count++;
	return (1);
}

int	read_cub(t_cube *cube)
{
	int	i;
	int	c;

	c = 0;
	if (!check_extension(cube->av[1], ".cub"))
		ft_end(cube, "Error\nWrong file extension\n");
	i = 0;
	if (!get_lst(cube, cube->av[1]))
		return (0);
	count_columns(cube);
	count_row(cube);
	fill_info(cube);
	if (cube->color_count != 2 || cube->text_count != 4)
		return (ft_end(cube, "wrong nb info"), 0);
	fill_map(cube);
	return (1);
}
