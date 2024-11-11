/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:12:12 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/11 12:21:37 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_display_pixel(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_len + x * (pixel->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= SCREEN_WIDTH)
		return ;
	if (y < 0)
		return ;
	else if (y >= SCREEN_HEIGHT)
		return ;
	ft_display_pixel(&cube->image, x, y, color);
}
