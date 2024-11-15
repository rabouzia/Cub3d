/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:34:01 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/15 14:57:33 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	printarg(t_arg *arg)
{
	while (arg)
	{
		printf("content is %s  \n", arg->content);
		// printf("----->type is %d\n", arg->type);
		arg = arg->next;
	}
}