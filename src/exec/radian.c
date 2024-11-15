/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:14:34 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/15 10:47:04 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*
	To handle large angles
	We check if the angle is greater than 2 * PI
	If it's greater than 2 * PI, we subtract 2 * PI from it
	We check if the angle is less than 0
	If it's less than 0, we add 2 * PI to it
*/

double	wrap_angle(double angle)
{
	if (angle >= M_PI * 2.0)
		angle -= M_PI * 2.0;
	if (angle < 0)
		angle += M_PI * 2.0;
	return (angle);
}

void	rotate_player(t_cube *cube, int i)
{
	cube->player.angle += ROTATION_SPEED * i;
	cube->player.angle = wrap_angle(cube->player.angle);
}

/*
	We calculate the new position of the player
	We check if the new position is not a wall
	If it's not a wall, we update the position of the player
*/

void	move_player(t_cube *cube, double angle)
{
	int		map_grid_y;
	int		map_grid_x;
	double	new_x;
	double	new_y;

	new_x = (cube->player.plyr_x + cos(angle));
	new_y = (cube->player.plyr_y + sin(angle));
	map_grid_x = ((int)new_x / TILE_SIZE);
	map_grid_y = ((int)new_y / TILE_SIZE);
	if ((cube->map.tab_map[map_grid_y][map_grid_x] != '1'
			&& (cube->map.tab_map[map_grid_y][(int)cube->player.plyr_x
				/ TILE_SIZE] != '1'
				&& cube->map.tab_map[(int)cube->player.plyr_y
				/ TILE_SIZE][map_grid_x] != '1'))
		|| (cube->map.tab_map[map_grid_y][map_grid_x] != '1'
			&& (cube->map.tab_map[map_grid_y][(int)cube->player.plyr_x
				/ TILE_SIZE] != '1'
				&& cube->map.tab_map[(int)cube->player.plyr_y
				/ TILE_SIZE][map_grid_x] != '1')))
	{
		cube->player.plyr_x = new_x;
		cube->player.plyr_y = new_y;
	}
}

/*
	To handle negative angles
	Normalize the angle between 0 and 2 * PI
	If the angle is negative, we add 2 * PI to it
	If the angle is greater than 2 * PI, we subtract 2 * PI from it
	So we get the angle between 0 and 2 * PI
*/

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

/*
	We check if x or y is in the unit circle
*/

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}
