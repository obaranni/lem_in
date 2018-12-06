/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:57:01 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 14:57:07 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int				get_way_id(t_room **ways)
{
	int			i;

	i = 0;
	while (ways && ways[i])
		i++;
	return (i);
}

t_room			*get_last_room(t_room *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

int				is_crossed_room(t_neigh *neigh, t_room *way)
{
	char		*name;

	name = neigh->origin->name;
	while (way)
	{
		if (!ft_strcmp(name, way->name))
			return (1);
		way = way->next;
	}
	return (0);
}

int				count_steps(t_room *way, int ants)
{
	int			i;

	i = 0;
	while (way->next)
	{
		i++;
		way = way->next;
	}
	return ((i - 1) + ants);
}

short int		ft_pwrbase(ssize_t num, int base)
{
	short int	counter;

	base = (!base) ? 10 : base;
	counter = 1;
	if (num < 0 || base < 0)
		counter++;
	if (num == base && base < 10)
		return (counter);
	while ((num /= base))
		counter++;
	return (counter);
}
