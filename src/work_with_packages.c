/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_packages.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:46:22 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:47:04 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_pack			*get_pack_by_id(t_lem *l, int id)
{
	t_pack		*tmp;

	tmp = l->packages;
	while (tmp)
	{
		if (tmp->id == id)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void			upend_package(t_lem *l, int id)
{
	t_pack		*new_pack;
	t_pack		*tmp;

	new_pack = (t_pack*)malloc(sizeof(t_pack));
	new_pack->id = id;
	new_pack->next = NULL;
	new_pack->parallel_ways = NULL;
	new_pack->ways_capacity = 0;
	new_pack->ants_setted = 0;
	new_pack->ways_num = 0;
	new_pack->total_steps = 0;
	new_pack->ants = NULL;
	if (!l->packages)
	{
		l->packages = new_pack;
		return ;
	}
	tmp = l->packages;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_pack;
}

int				is_ways_parallel(t_room *w1, t_room *w2)
{
	t_room		*w2_tmp;

	w1 = w1->next;
	while (w1)
	{
		if (!(w1->next))
			return (1);
		w2_tmp = w2->next;
		while (w2_tmp)
		{
			if (!(w2_tmp->next))
				break ;
			if (!ft_strcmp(w1->name, w2_tmp->name))
				return (0);
			w2_tmp = w2_tmp->next;
		}
		w1 = w1->next;
	}
	return (1);
}

int				is_ways_parallel_in_package(t_pack *pack, t_room *new_way)
{
	int			i;

	i = 0;
	while (pack->parallel_ways[i])
	{
		if (!is_ways_parallel(pack->parallel_ways[i], new_way))
			return (0);
		i++;
	}
	return (1);
}
