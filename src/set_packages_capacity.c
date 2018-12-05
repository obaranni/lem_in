//
// Created by Oleksandr Barannik on 12/5/18.
//

#include "../inc/lem_in.h"

void		set_packages_capacity(t_pack *pack)
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
		pack->ants_on_ways = (int*)malloc(sizeof(int) * (pack->ways_num + 1));
		pack->ants_on_ways[pack->ways_num] = -1;
		pack->load_on_ways = (int*)malloc(sizeof(int) * (pack->ways_num + 1));
		pack->load_on_ways[pack->ways_num] = -1;
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
			pack->ants_on_ways[i] = 0;
			pack->load_on_ways[i] = count_steps(pack->parallel_ways[i], 0);
			i++;
		}
		pack = pack->next;
	}
}