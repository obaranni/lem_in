/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:30:20 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 14:31:03 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void			bfs(t_room *start, t_lem *l)
{
	int			way_id;
	t_neigh		*neigh;
	t_room		*last_room;
	t_room		*new_way;

	struct timespec tstart, tend;


	tstart.tv_nsec = 0;
	tstart.tv_sec = 0;
	tend.tv_nsec = 0;
	tend.tv_sec = 0;
	clock_gettime(CLOCK_MONOTONIC, &tstart);


	last_room = get_last_room(start);
	if (last_room->is_processed == PROCESSED)
		return ;
	last_room->is_processed = PROCESSED;
	if (!ft_strcmp(last_room->name, l->end->name))
		return ;
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

	clock_gettime(CLOCK_MONOTONIC, &tend);
	printf("one way preparing took about %.5f seconds\n",
		   ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
		   ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
}

void			remove_bad_ways(t_lem *l)
{
	t_room		**full_ways;
	int			i;
	int			j;

	j = 0;
	i = 0;
	if (!l->ways)
		return ;
	while (l->ways[i])
		if (!ft_strcmp((get_last_room(l->ways[i++]))->name, l->end->name))
			j++;
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

int				find_ways(t_lem *l)
{
	int			i;
	t_room		*start_cp;

	start_cp = room_dup(l->start);
	bfs(start_cp, l);
	free_room(start_cp);
	i = 0;
	if (!l->ways)
	{
		return (set_error(l->read, "There are no connections between the rooms",
				l->read->i, ERR));
	}
	while (l->ways[i])
		bfs(l->ways[i++], l);
	if (l->flags.ways && l->flags.bad_cases)
		print_ways(l, 0, 0, l->ways);
	remove_bad_ways(l);
	if (!l->ways[0])
	{
		return (set_error(l->read, "The Start and End rooms are not connected",
				l->read->i, ERR));
	}
	if (l->flags.ways)
		print_ways(l, 0, 0, l->ways);
	return (0);
}
