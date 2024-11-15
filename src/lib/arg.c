/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:19:47 by rabouzia          #+#    #+#             */
/*   Updated: 2024/11/15 15:01:46 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_argaddback(t_arg **head, t_arg *new)
{
	if (!head)
		return;
	if (*head)
		ft_arglast(*head)->next = new;
	else
		*head = new;
}

void epur_space(char *str)
{
	int	i; 
	int j;

	i = 0; 
	j = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
			{
				str[j++] = ' ';
				while (str[i] == ' ' || str[i] == '\t')
					i++;
			}
			else
				str[j++] = str[i++];
		}
		if (j > 0 && str[j - 1] == ' ')
			j--;
	}
	str[j] = '\0';
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
	if(arg->type != MAP)
		epur_space(str);
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
	t_arg	*tmp;

	while (arg)
	{
		tmp = arg->next;
		if (arg->content)
			free(arg->content);
		free(arg);
		arg = tmp;
	}
}
