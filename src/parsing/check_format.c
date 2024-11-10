/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:50:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/10 21:23:00 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_path(t_cube *cube, char *line, t_pixel *p)
{
	if (!check_extension(line, ".xpm"))
		ft_end(cube, "extention error <.xpm> ");
	p->img = mlx_xpm_file_to_image(cube->mlx, line + 5, &p->pix_w, &p->pix_h);
	mlx_put_image_to_window(cube->mlx, cube->win, p->img, 0, 0);
	p->addr = mlx_get_data_addr(p->img, &p->bpp, &p->line_len, &p->endian);
	if (!p->img)
		ft_end(cube, "xpm error");
	return (1);
}

int	get_rgb(t_cube *cube, char *line, t_pixel *way) //, int i)
{
	char			**color;
	unsigned int	res;
	int				rgb;

	(void)cube;
	color = ft_split(line + 2, ',');
	res = 0;
	rgb = ft_atoi(color[0]);
	if (rgb == -1)
		return (0);
	res |= rgb << 16;
	rgb = ft_atoi(color[1]);
	if (rgb == -1)
		return (0);
	res |= rgb << 8;
	rgb = ft_atoi(color[2]);
	if (rgb == -1)
		return (0);
	res |= rgb;
	way->f_or_c = res;
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
	count_row(cube);
	count_columns(cube);
	fill_info(cube);
	fill_map(cube);
	return (1);
}
