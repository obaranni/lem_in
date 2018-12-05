#include "../inc/lem_in.h"

void				set_ants_on_ways(t_pack *pack)
{
	t_ant			*ant;
	int 			i;
	int 			j;

	i = 0;
	j = 0;
	ant = pack->ants;
	while (ant)
	{
		if (i == pack->ants_on_ways[j])
		{
			i = 0;
			j++;
			continue;
		}
		ant->way = pack->parallel_ways[j];
		i++;
		ant = ant->next;
	}
}

int 				is_room_busy(char *name, t_ant *ants)
{
	while (ants)
	{
		if (!ft_strcmp(ants->way->name, name))
			return (1);
		ants = ants->next;
	}
	return (0);
}



void				move_ants(t_lem *l, t_pack *pack)
{
	int 			ants_finished;
	t_ant			*ant;

	create_ants(l->read->ants_readed, pack);
	set_ants_on_ways(pack);
	if (l->flags.print && l->flags.bad_cases)
		print_ants(pack->ants);
	ants_finished = 0;
	while (ants_finished != l->read->ants_readed)
	{
		ant = pack->ants;
		while (ant)
		{
			if (ant->way->next && (!ft_strcmp(ant->way->next->name, l->end->name) || !is_room_busy(ant->way->next->name, pack->ants)))
			{
				ant->way = ant->way->next;
				print_ant_step(ant);
				if (!ft_strcmp(ant->way->name, l->end->name))
					ants_finished++;
			}
			ant = ant->next;
		}
		ft_putchar('\n');
	}
}