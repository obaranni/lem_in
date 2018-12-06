/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_package.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:53:39 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 14:53:42 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_pack			*get_best_package(t_pack *pack)
{
	int			min_steps;
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
