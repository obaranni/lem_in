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

t_room			*get_last_room(t_room *head)
{
	while (head->next)
		head = head->next;
	return (head);
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
	if (tmp1 && tmp1->next)
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
	new_ways[i + 1] = NULL;
	if (way_id)
		free(l->ways);
	l->ways = new_ways;
}

int				is_crossed_room(t_neigh *neigh, t_room *way)
{
	char 		*name;

	name = neigh->origin->name;
	while (way)
	{
		if (!ft_strcmp(name, way->name))
			return (1);
		way = way->next;
	}
	return (0);
}

void			BFS(t_room *start, t_lem *l)
{
	int 		way_id;
	t_neigh		*neigh;
	t_room		*last_room;
	t_room		*new_way;


	last_room = get_last_room(start);
	if (last_room->is_processed == PROCESSED)
		return;
	last_room->is_processed = PROCESSED;
	neigh = last_room->neighbors;
	while (neigh)
	{
		if (is_crossed_room(neigh, start))
		{
			neigh = neigh->next;
			continue ;
		}
		way_id = get_way_id(l);
		new_way = create_new_way(start, neigh->origin, way_id);
		uppend_way(l, new_way);
		neigh = neigh->next;
	}

}

void			print_way(t_room *way)
{
	while (way)
	{
		if (way->next)
			printf("%s -> ", way->name);
		else
			printf("%s\n", way->name);
		way = way->next;
	}
}

void			print_ways(t_lem *l)
{
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	while (l->ways[i])
	{
		if (!ft_strcmp((get_last_room(l->ways[i]))->name, l->end->name))
		{
			j++;
			print_way(l->ways[i]);
		}
		i++;
	}
	printf("CORRECT WAYS %d\n", j);
}

int				find_ways(t_lem *l)
{
	int 		i;
	t_room		*start_cp;

	start_cp = room_dup(l->start);
	BFS(start_cp, l);
	free_room(start_cp);
	i = 0;
	while (l->ways[i])
	{
		BFS(l->ways[i], l);
		i++;
	}



	print_ways(l);
}
