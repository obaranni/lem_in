/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_packages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:43:47 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 14:43:51 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int				is_same_packages(t_pack *p1, t_pack *p2)
{
	int			i;
	int			j;
	int			found;

	i = 0;
	found = 0;
	while (p1->parallel_ways[i])
	{
		j = 0;
		while (p2->parallel_ways[j])
		{
			if (p1->parallel_ways[i] == p2->parallel_ways[j])
			{
				found++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (found == get_way_id(p1->parallel_ways) &&
	found == get_way_id(p2->parallel_ways))
		return (1);
	return (0);
}

void			remove_same_packages(t_lem *l)
{
	t_pack		*first;
	t_pack		*sec;

	first = l->packages;
	while (first->next)
	{
		sec = first->next;
		if (is_same_packages(first, sec))
		{
			first->next = sec->next;
			free(sec->parallel_ways);
			free(sec);
			first = l->packages;
			continue ;
		}
		first = first->next;
	}
}

void			create_packages(t_lem *l)
{
	int			i;
	int			j;
	int			count;

	count = 0;
	i = -1;
	while (l->ways[++i])
	{
		j = 0;
		upend_package(l, i);
		upend_way(&(get_pack_by_id(l, i)->parallel_ways), l->ways[i]);
		while (l->ways[j])
		{
			if (i == j)
				j++;
			if (!l->ways[j])
				break ;
			if (is_ways_parallel_in_package(get_pack_by_id(l, i), l->ways[j]))
			{
				upend_way(&(get_pack_by_id(l, i)->parallel_ways), l->ways[j]);
				count++;
			}
			j++;
		}
	}
}
