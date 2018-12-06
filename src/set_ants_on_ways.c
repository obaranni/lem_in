/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ants_on_ways.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:37:25 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:37:33 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void				set_total_steps(t_pack *pack)
{
	int				max_steps;
	int				i;

	i = 0;
	max_steps = 0;
	while (pack->load_on_ways[i] != -1)
	{
		if (pack->load_on_ways[i] > max_steps)
			max_steps = pack->load_on_ways[i];
		i++;
	}
	pack->total_steps = max_steps;
}

void				increase_load(t_pack *packages)
{
	int				i;
	int				min_l;
	int				to_set;

	i = 0;
	to_set = 0;
	min_l = INT_MAX;
	while (packages->load_on_ways[i] != -1)
	{
		if (packages->load_on_ways[i] < min_l)
		{
			min_l = packages->load_on_ways[i];
			to_set = i;
		}
		i++;
	}
	packages->load_on_ways[to_set] += 1;
	packages->ants_on_ways[to_set] += 1;
	packages->ants_setted++;
}

void				set_ants_quantity_on_ways(t_lem *l, t_pack *packages)
{
	while (packages)
	{
		while (packages->ants_setted != l->read->ants_readed)
			increase_load(packages);
		set_total_steps(packages);
		packages = packages->next;
	}
}
