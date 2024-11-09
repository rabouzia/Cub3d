/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:21:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/09 01:37:41 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_cube	cube;

	(void)ac;
	// if (ac != 2)
	// 	return (printf("Use a map in map/\n"), 0);
	cube = (t_cube){0};
	if (!minilibx(&cube))
		return (0);
	if (!parsing(&cube, av))
		return (0);
	if (!raycasting(&cube))
		return (0);
	
	ft_exit(&cube);
	return (0);
}
/*
	TODO freeing
		- look for leaks	sa
	TODO parsing:
		- parse everything
	TODO map:
	- must be 1 0 W D S E W
	- must be close (0 not surround by anything but P or 1)
	- lettre valid
	- check la map avec ce qu'il ya autour des 0 (X: ' ' et 'P')
	*/