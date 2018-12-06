/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:23:19 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:24:17 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			extra_se_room(t_lem *l, int is_spec)
{
	if (is_spec == 1 && l->start)
		return (set_error(l->read, "Extra START room", l->read->i + 1, ERR));
	else if (is_spec == 2 && l->end)
		return (set_error(l->read, "Extra END room", l->read->i + 1, ERR));
	return (0);
}

int			read_room(int fd, t_read *r, char which)
{
	add_to_input(r);
	lgnl(fd, &r->buf);
	if (ft_strlen(r->buf) < 5)
	{
		if (which == 's')
			return (set_error(r, "Absent START room", r->i + 1, ERR));
		else
			return (set_error(r, "Absent END room", r->i + 1, ERR));
	}
	return (0);
}

int			invalid_room(t_lem *l, int is_spec)
{
	char	**strs;

	if (!is_it_room(l->read))
	{
		return (set_error(l->read, "It does not look like a room",
				l->read->i + 1, ERR) - 1);
	}
	if (l->read->buf[0] == 'L')
	{
		return (set_error(l->read, "Room should not start from \'L\' letter",
				l->read->i + 1, ERR) - 1);
	}
	strs = ft_strsplit(l->read->buf, ' ', 0);
	if ((invalid_room_coord(l->read, strs[1], strs[2], l)) ||
			invalid_room_name(l->read, strs[0], l) ||
			(is_spec && extra_se_room(l, is_spec)))
	{
		free_str_arr(strs);
		return (1);
	}
	add_room(l, strs, is_spec);
	return (0);
}
