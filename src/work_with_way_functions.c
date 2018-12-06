/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_way_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:47:42 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:48:20 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_room			*way_dup(t_room *src_head, int way_id)
{
	t_room		*new_head;
	t_room		*tmp1;
	t_room		*tmp2;

	new_head = room_dup(src_head);
	new_head->way_id = way_id;
	new_head->is_processed = PROCESSED;
	tmp1 = new_head;
	while (src_head->next)
	{
		tmp2 = room_dup(src_head->next);
		tmp2->way_id = way_id;
		tmp2->is_processed = PROCESSED;
		tmp1->next = tmp2;
		src_head = src_head->next;
		tmp1 = tmp1->next;
	}
	return (new_head);
}

t_room			*create_new_way(t_room *way_head, t_room *new_room, int way_id)
{
	t_room		*new_way;
	t_room		*last_room;

	new_way = way_dup(way_head, way_id);
	last_room = get_last_room(new_way);
	last_room->next = room_dup(new_room);
	last_room->next->way_id = way_id;
	return (new_way);
}

void			upend_way(t_room ***ways, t_room *new_part)
{
	t_room		**new_ways;
	int			way_id;
	int			i;

	way_id = get_way_id(*ways);
	new_ways = (t_room**)malloc(sizeof(t_room*) * (way_id + 2));
	i = 0;
	while (i < way_id)
	{
		new_ways[i] = (*ways)[i];
		i++;
	}
	new_ways[i] = new_part;
	new_ways[i + 1] = NULL;
	if (way_id)
		free(*ways);
	*ways = new_ways;
}
