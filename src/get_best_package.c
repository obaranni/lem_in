//
// Created by Oleksandr Barannik on 2018-12-04.
//

#include "../inc/lem_in.h"

t_pack			*get_best_package(t_pack *pack)
{
	int 		min_steps;
	t_pack		*best;

	best = 0;
	min_steps = INT_MAX;
	while (pack)
	{
		if (pack->total_steps < min_steps)
		{
			best = pack;
			min_steps = pack->total_steps;
		}
		pack = pack->next;
	}
	return (best);
}