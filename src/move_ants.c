/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:08:21 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:10:01 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int					is_room_busy(char *name, t_ant *ants)
{
	while (ants)
	{
		if (!ft_strcmp(ants->way->name, name))
			return (1);
		ants = ants->next;
	}
	return (0);
}

void				move_ants(t_lem *l)
{
	unsigned int	ants_finished;
	t_ant			*ant;
	t_pack			*pack;

	pack = get_best_package(l->packages);
	ants_finished = 0;
	while (ants_finished != l->read->ants_readed)
	{
		ant = pack->ants;
		while (ant)
		{
			if (ant->way->next &&
				(!ft_strcmp(ant->way->next->name, l->end->name)
				|| !is_room_busy(ant->way->next->name, pack->ants)))
			{
				ant->way = ant->way->next;
				if (l->flags.steps)
					print_ant_step(l, ant);
				if (!ft_strcmp(ant->way->name, l->end->name))
					ants_finished++;
			}
			ant = ant->next;
		}
		if (l->flags.steps)
			ft_putchar('\n');
	}
}
