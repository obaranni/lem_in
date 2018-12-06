/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:41:36 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 14:41:37 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

static t_ant		*create_ant(int id)
{
	t_ant			*new;

	new = (t_ant*)malloc(sizeof(t_ant));
	new->id = id;
	new->next = NULL;
	new->way = NULL;
	return (new);
}

void				create_ants(int quantity, t_pack *pack)
{
	int				i;
	t_ant			*head;

	i = 0;
	pack->ants = create_ant(i++);
	head = pack->ants;
	while (i < quantity)
	{
		head->next = create_ant(i);
		head = head->next;
		i++;
	}
}
