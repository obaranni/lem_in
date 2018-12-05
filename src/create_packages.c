//
// Created by Oleksandr Barannik on 12/4/18.
//
#include "../inc/lem_in.h"

t_pack			*get_pack_by_id(t_lem *l, int id)
{
	t_pack		*tmp;

	tmp = l->packages;
	while (tmp)
	{
		if (tmp->id == id)
			break;
		tmp = tmp->next;
	}
	return (tmp);
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
				break;
			if (!ft_strcmp(w1->name, w2_tmp->name))
				return (0);
			w2_tmp = w2_tmp->next;
		}
		w1 = w1->next;
	}
	return (1);
}

void 			upend_package(t_lem *l, int id)
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
		return;
	}
	tmp = l->packages;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_pack;
}

int 			is_same_packages(t_pack *p1, t_pack *p2)
{
	int 		i;
	int 		j;
	int 		found;

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
				break;
			}
			j++;
		}
		i++;
	}
	if (found == get_way_id(p1->parallel_ways) && found == get_way_id(p2->parallel_ways))
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
			continue;
		}
		first = first->next;

	}
}

int 			is_ways_parallel_in_package(t_pack *pack, t_room *new_way)
{
	int 		i;

	i = 0;
	while (pack->parallel_ways[i])
	{
		if (!is_ways_parallel(pack->parallel_ways[i], new_way))
            return (0);
		i++;
	}
    return (1);
}

void 			create_packages(t_lem *l)
{
	int 		i;
	int 		j;
	int 		count;

	count = 0;
	i = 0;
	while (l->ways[i])
	{
		j = 0;
		upend_package(l, i);
		upend_way(&(get_pack_by_id(l, i)->parallel_ways), l->ways[i]);
		while (l->ways[j])
		{
			if (i == j)
				j++;
			if (!l->ways[j])
				break;
			if (is_ways_parallel_in_package(get_pack_by_id(l, i), l->ways[j]))
			{
				upend_way(&(get_pack_by_id(l, i)->parallel_ways), l->ways[j]);
				count++;
			}
			j++;
		}
		i++;
	}

	if (l->flags.print && l->flags.bad_cases)
		print_packages(l->packages);
	remove_same_packages(l);
	set_packages_capacity(l->packages);
	set_ants_quantity_on_ways(l, l->packages);
	if (l->flags.print)
		print_packages(l->packages);

}