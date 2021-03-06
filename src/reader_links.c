/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:18:37 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:19:43 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int					is_room_exist(char *name, t_room *room, int from)
{
	int				exist;
	int				i;

	i = 1;
	exist = 0;
	while (room)
	{
		if (i >= from && !ft_strcmp(room->name, name))
		{
			i++;
			exist = 1;
			break ;
		}
		i++;
		room = room->next;
	}
	return (i * exist);
}

int					invalid_rooms(char *n1, char *n2, t_lem *l, int set_err)
{
	char			*err;

	if (!is_room_exist(n1, l->head, 1))
		err = ft_strjoin("There are no rooms with name: ", n1);
	else if (!is_room_exist(n2, l->head, 1))
		err = ft_strjoin("There are no rooms with name: ", n2);
	else
		return (0);
	if (set_err)
		set_error(l->read, err, l->read->i, ERR);
	free(err);
	return (1);
}

int					is_it_link(t_lem *l, t_read *r)
{
	unsigned int	i;
	char			*n1;
	char			*n2;

	i = 1;
	while (r->buf[0] && r->buf[i])
	{
		if (r->buf[i] == '-')
		{
			n1 = ft_strsub(r->buf, 0, i);
			n2 = ft_strsub(r->buf, i + 1, (ft_strlen(r->buf) - i + 1));
			if (!invalid_rooms(n1, n2, l, 0))
			{
				r->l_r1 = n1;
				r->l_r2 = n2;
				return (1);
			}
			free(n1);
			free(n2);
		}
		i++;
	}
	return (0);
}

t_room				*find_room_byname(t_room *room, char *name)
{
	while (room)
	{
		if (!ft_strcmp(room->name, name))
			return (room);
		room = room->next;
	}
	return (NULL);
}

int					invalid_link(t_lem *l)
{
	if (!is_it_link(l, l->read))
		return (set_error(l->read, "Invalid link", l->read->i + 1, ERR));
	link_rooms(find_room_byname(l->head, l->read->l_r1),
		find_room_byname(l->head, l->read->l_r2));
	free(l->read->l_r1);
	free(l->read->l_r2);
	return (0);
}
