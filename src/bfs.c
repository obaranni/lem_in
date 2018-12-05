//
// Created by Oleksandr Barannik on 11/29/18.
//
#include "../inc/lem_in.h"

int 			get_way_id(t_room **ways)
{
	int 		i;

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
	int 		way_id;
	int 		i;

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
	if (!ft_strcmp(last_room->name, l->end->name))
		return;
	neigh = last_room->neighbors;
	while (neigh)
	{
		if (is_crossed_room(neigh, start))
		{
			neigh = neigh->next;
			continue ;
		}
		way_id = get_way_id(l->ways);
		new_way = create_new_way(start, neigh->origin, way_id);
		upend_way(&l->ways, new_way);
		neigh = neigh->next;
	}

}

void			remove_bad_ways(t_lem *l)
{
	t_room **full_ways;
	int i;
	int j;

	j = 0;
	i = 0;
	if (!l->ways)
		return;
	while (l->ways[i])
	{
		if (!ft_strcmp((get_last_room(l->ways[i]))->name, l->end->name))
			j++;
		i++;
	}
	full_ways = (t_room **)malloc(sizeof(t_room *) * (j + 1));
	full_ways[j] = NULL;
	i = 0;
	j = 0;
	while (l->ways[i])
	{
		if (!ft_strcmp((get_last_room(l->ways[i]))->name, l->end->name))
			full_ways[j++] = l->ways[i];
		else
			free_rooms(l->ways[i]);

		i++;
	}
	free(l->ways);
	l->ways = full_ways;
}

int 				count_steps(t_room* way, int ants)
{
	int 			i;

	i = 0;
	while (way->next)
	{
		i++;
		way = way->next;
	}
	return ((i - 1) + ants);
}

int				find_ways(t_lem *l)
{
	int 		i;
	t_room		*start_cp;

	start_cp = room_dup(l->start);
	BFS(start_cp, l); // check returned NULL
	free_room(start_cp);
	i = 0;
	if (!l->ways)
		return (set_error(l->read, "There are no connections between the rooms", l->read->i, ERR));
	while (l->ways[i])
	{
		BFS(l->ways[i], l);
		i++;
	}
	if (l->flags.print && l->flags.bad_cases)
		print_ways(0, l->ways);
	remove_bad_ways(l);
	if (!l->ways[0])
		return (set_error(l->read, "The Start and End rooms are not connected", l->read->i, ERR));
	if (l->flags.print)
		print_ways(0, l->ways);


//	printf("Ants: %d\n", l->read->ants_readed);
//	i = 0;
//	while (l->ways[i])
//	{
//		print_way(l->ways[i]);
//		printf("Steps: %d\n\n", count_steps(l->ways[i], l->read->ants_readed));
//		i++;
//	}


	return (0);
}