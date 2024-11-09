/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_log.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:55:52 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/07 13:43:10 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	key_press(int key, t_cube *cube)
{
	if (key == XK_Escape || key == XK_q)
		ft_exit(cube);
	if (key >= 32 && key < 126)
		cube->inputs[key] = 1;
	if (key == XK_Right)
		cube->inputs[126] = 1;
	if (key == XK_Left)
		cube->inputs[127] = 1;
	return (0);
}

int	key_release(int key, t_cube *cube)
{
	if (key >= 32 && key < 126)
		cube->inputs[key] = 0;
	if (key == XK_Right)
		cube->inputs[126] = 0;
	if (key == XK_Left)
		cube->inputs[127] = 0;
	return (0);
}

int	inputs(t_cube *cube)
{
	rotate_player(cube, cube->inputs[126] - cube->inputs[127]);
	if (cube->inputs[XK_w])
		move_player(cube, wrap_angle(cube->player.angle));
	if (cube->inputs[XK_s])
		move_player(cube, wrap_angle(cube->player.angle + M_PI));
	if (cube->inputs[XK_a])
		move_player(cube, wrap_angle(cube->player.angle - (M_PI / 2.0)));
	if (cube->inputs[XK_d])
		move_player(cube, wrap_angle(cube->player.angle + (M_PI / 2.0)));
	return (0);
}