/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:52:20 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 14:52:23 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		free_str_arr(char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void		free_neighbors(t_neigh *neigh)
{
	t_neigh	*tmp_n;

	while (neigh)
	{
		tmp_n = neigh->next;
		free(neigh);
		neigh = tmp_n;
	}
}

void		free_room(t_room *room)
{
	free_neighbors(room->neighbors);
	free(room->name);
	free(room);
}

void		free_rooms(t_room *head)
{
	t_room	*tmp;

	while (head)
	{
		tmp = head->next;
		free_room(head);
		head = tmp;
	}
}

void		free_errors(t_err *errors)
{
	t_err	*tmp;

	while (errors)
	{
		tmp = errors;
		free(errors->msg);
		free(errors);
		errors = tmp->next;
	}
}
