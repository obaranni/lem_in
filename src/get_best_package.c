//
// Created by Oleksandr Barannik on 2018-12-04.
//

#include "../inc/lem_in.h"

void		set_package_power(t_pack *pack)
{
	float 	cap;
	float 	per;
	int 	i;

	while (pack)
	{
		i = 0;
		cap = 0;
		pack->ways_num = get_way_id(pack->parallel_ways);
		pack->ways_capacity = (float*)malloc(sizeof(float) * (pack->ways_num + 1));
		pack->ways_capacity[pack->ways_num] = 0;
		while (pack->parallel_ways[i])
		{
			pack->ways_capacity[i] = 1 / (float)count_steps(pack->parallel_ways[i], 1);
			cap += pack->ways_capacity[i];
			i++;
		}
		per = cap / 100;
		i = 0;
		while (pack->parallel_ways[i])
		{
			pack->ways_capacity[i] = pack->ways_capacity[i] / per;
			i++;
		}
		pack->package_capacity = cap;
		pack = pack->next;
	}
}

void        get_best_package(t_lem *l)
{
	int a;
	int i = 0;
	while (l->ways[i])
	{
		a = count_steps(l->ways[i], 1);
		print_way(0, l->ways[i]);
		printf("%f\n", (100 / (float)a));
		i++;
	}
//	set_package_power(l->packages);
}