/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:34:01 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/10 20:34:10 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	printarg(t_arg *arg)
{
	while (arg)
	{
		printf("content is %s  ", arg->content);
		if (arg->type != TRASH)
			printf("----->type is %d\n", arg->type);
		arg = arg->next;
	}
}