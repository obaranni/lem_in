//
// Created by Oleksandr Barannik on 12/5/18.
//

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
	int 			i;
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