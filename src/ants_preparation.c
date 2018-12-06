/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_preparation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:55:14 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 13:55:57 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				set_ants_on_ways(t_pack *pack)
{
	t_ant			*ant;
	int				i;
	int				j;

	i = 0;
	j = 0;
	ant = pack->ants;
	while (ant)
	{
		if (i == pack->ants_on_ways[j])
		{
			i = 0;
			j++;
			continue;
		}
		ant->way = pack->parallel_ways[j];
		i++;
		ant = ant->next;
	}
}

void				prepare_ants(t_lem *l)
{
	t_pack			*pack;

	pack = get_best_package(l->packages);
	create_ants(l->read->ants_readed, pack);
	set_ants_on_ways(pack);
	if (l->flags.ants)
		print_ants(l, pack->ants);
}
