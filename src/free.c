/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:51:23 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 14:51:25 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		free_ways(t_room **ways)
{
	int		i;

	i = 0;
	while (ways && ways[i])
	{
		free_rooms(ways[i]);
		i++;
	}
	if (ways)
		free(ways);
}

void		free_ants(t_ant *ant)
{
	t_ant	*tmp;

	while (ant)
	{
		tmp = ant->next;
		free(ant);
		ant = tmp;
	}
}

void		free_packages(t_pack *pack)
{
	t_pack	*tmp;

	while (pack)
	{
		tmp = pack->next;
		free_ants(pack->ants);
		free(pack->ants_on_ways);
		free(pack->load_on_ways);
		free(pack->ways_capacity);
		free(pack->parallel_ways);
		free(pack);
		pack = tmp;
	}
}

void		free_fd(t_fd **fd)
{
	t_fd	*temp;

	temp = *fd;
	*fd = (*fd)->next;
	close(temp->fd);
	free(temp->file);
	free(temp);
}

void		free_all(t_lem *l)
{
	if (l->read)
	{
		free(l->read->input);
		free_errors(l->read->errors);
		free(l->read);
	}
	free_ways(l->ways);
	free_rooms(l->head);
	free_packages(l->packages);
	free_fd(&(l->flags.fd));
}
