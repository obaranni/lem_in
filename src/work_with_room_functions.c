/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_room_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:47:19 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:47:26 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_neigh			*neigbor_dup(t_neigh *neigh)
{
	t_neigh		*new_neigh;

	new_neigh = (t_neigh *)malloc(sizeof(t_neigh));
	new_neigh->origin = neigh->origin;
	new_neigh->next = NULL;
	return (new_neigh);
}

void			neighbors_dup(t_room *dst, t_room *src)
{
	t_neigh		*tmp_src;
	t_neigh		*tmp_dst;

	if (src->neighbors == NULL)
		return ;
	tmp_src = src->neighbors;
	tmp_dst = neigbor_dup(tmp_src);
	dst->neighbors = tmp_dst;
	tmp_src = tmp_src->next;
	while (tmp_src)
	{
		tmp_dst->next = neigbor_dup(tmp_src);
		tmp_dst = tmp_dst->next;
		tmp_src = tmp_src->next;
	}
}

t_room			*room_dup(t_room *src)
{
	t_room		*copy;

	copy = (t_room *)malloc(sizeof(t_room));
	copy->name = ft_strdup(src->name);
	copy->next = 0;
	copy->way_id = -1;
	copy->is_processed = NOT_PROCESSED;
	copy->neighbors = NULL;
	copy->x = src->x;
	copy->y = src->y;
	neighbors_dup(copy, src);
	return (copy);
}
