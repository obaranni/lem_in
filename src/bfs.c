//
// Created by Oleksandr Barannik on 11/29/18.
//
#include "../inc/lem_in.h"

int 			get_way_id(t_lem *l)
{
	int 		i;

	i = 0;
	while (l->ways && l->ways[i])
		i++;
	return (i);
}

t_neigh			*neigh_dup(t_neigh *src)
{
	t_neigh		*new;

	new = (t_neigh *)malloc(sizeof(t_neigh));
	new->origin = src->origin;
	new->next = 0;
	return (new);
}

void			cp_neighbors(t_room *dst, t_room *src)
{
	t_neigh		*tmp1;
	t_neigh		*tmp2;

	tmp1 = src->neighbors;
	if (tmp1)
		dst->neighbors = neigh_dup(tmp1);
	if (tmp1->next)
		tmp1 = tmp1->next;
	else
		return;
	tmp2 = dst->neighbors;
	while (tmp1)
	{
		tmp2->next = neigh_dup(tmp1);
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
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
	copy->x = src->x;
	copy->y = src->y;
	cp_neighbors(copy, src);
	return (copy);
}

t_room			*create_room_pair(t_room *top, t_room *bott, int way_id)
{
	t_room		*new_top;
	t_room		*new_bott;

	new_top = room_dup(top);
	new_bott = room_dup(bott);
	new_top->next = new_bott;
	new_top->way_id = way_id;
	new_bott->way_id = way_id;
	return (new_top);
}

void			uppend_way(t_lem *l, t_room *new_part)
{
	t_room		**new_ways;
	int 		way_id;
	int 		i;

	way_id = get_way_id(l);
	new_ways = (t_room**)malloc(sizeof(t_room*) * (way_id + 2));
	i = 0;
	while (i < way_id)
	{
		new_ways[i] = l->ways[i];
		i++;
	}
	new_ways[i] = new_part;
	new_ways[i]->is_processed = PROCESSED;
	new_ways[i + 1] = NULL;
	if (way_id)
		free(l->ways);
	l->ways = new_ways;
}

void			BFS(t_room *start, t_lem *l)
{
	int 		way_id;
	t_neigh		*tmp_neigh;
	tmp_neigh = start->neighbors;
	while (start->next && start->is_processed == PROCESSED)
		start = start->next;
	while (tmp_neigh)
	{
		way_id = get_way_id(l);
		uppend_way(l, create_room_pair(start, tmp_neigh->origin, way_id));
		tmp_neigh = tmp_neigh->next;
	}

}

int		find_ways(t_lem *l)
{
	// creating genesis ways
	BFS(l->start, l);

	//
}
