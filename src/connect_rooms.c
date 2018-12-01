//
// Created by Oleksandr Barannik on 11/29/18.
//

#include "../inc/lem_in.h"

void		append_neigh(t_room *main, t_room *to_append)
{
	t_neigh	*tmp;
	t_neigh	*new;

	new = (t_neigh *)malloc(sizeof(t_neigh));
	new->origin = to_append;
	new->next = 0;
	if (main->neighbors == 0)
	{
		main->neighbors = new;
		return;
	}
	tmp = main->neighbors;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void		link_rooms(t_room *r1, t_room *r2)
{
	append_neigh(r1, r2);
	append_neigh(r2, r1);
}