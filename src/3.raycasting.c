/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.raycasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:34:44 by ramzerk           #+#    #+#             */
/*   Updated: 2024/10/07 21:05:44 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	DDA(int X0, int Y0, int X1, int Y1)
{
	int		dx;
	int		dy;
	int		steps;
	float	Xinc;
	float	Yinc;
	float	X;
	float	Y;

	dx = X1 - X0;
	dy = Y1 - Y0;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	Xinc = dx / (float)steps;
	Yinc = dy / (float)steps;
	X = X0;
	Y = Y0;
	for (int i = 0; i <= steps; i++)
	{
		ft_put_pixel(round(X), round(Y));
		X += Xinc;
		Y += Yinc;
	}
}

bool	raycasting(t_game *game)
{
	return (1);
}
