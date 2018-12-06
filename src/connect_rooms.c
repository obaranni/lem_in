/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:41:10 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 14:41:12 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return ;
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
