/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:21:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/15 09:09:50 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_cube	cube;

	(void)ac;
	if (ac != 2)
		return (printf("Usage: ./Cub3D maps/*.xpm\n"), 0);
	cube = (t_cube){0};
	if (!minilibx(&cube))
		return (0);
	if (!parsing(&cube, av))
		return (0);
	if (!raycasting(&cube))
		return (0);
	ft_end(&cube, "All cleaned");
	return (0);
}
/*
	- Ajouter la croix pour quitter
*/