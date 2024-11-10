/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:19:47 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/10 17:44:47 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_argaddback(t_arg **head, t_arg *new)
{
	if (!head)
		return ;
	if (*head)
		ft_arglast(*head)->next = new;
	else
		*head = new;
}

t_arg	*ft_argnew(char *str, t_arg_type type)
{
	t_arg	*arg;

	if (!str)
		return (NULL);
	arg = malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->type = type;
	arg->content = ft_strdup(str);
	arg->next = NULL;
	return (arg);
}

t_arg	*ft_arglast(t_arg *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

int	ft_argmap(t_arg *arg)
{
	int	i;

	i = 0;
	while (arg)
	{
		arg = arg->next;
		i++;
	}
	return (i);
}

void	ft_argclear(t_arg *arg)
{
	t_arg *tmp;

	while (arg)
	{
		tmp = arg->next;
		free(arg->content);
		free(arg);
		arg = tmp;
	}
}