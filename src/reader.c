/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:15:37 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:17:43 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		add_to_input(t_read *r)
{
	char	*tmp;

	if (!r->input)
	{
		r->input = ft_strjoin(r->buf, "\n");
	}
	else
	{
		tmp = r->input;
		r->input = ft_strjoin(r->input, r->buf);
		free(tmp);
		tmp = r->input;
		r->input = ft_strjoin(r->input, "\n");
		free(tmp);
	}
	r->i++;
	free(r->buf);
}

int			valid(t_read *r, t_lem *l)
{
	if (is_it_ants(r))
		return (read_ants(r));
	else if (!ft_strcmp(r->buf, START))
		return (!read_room(l->flags.fd->fd, r,
					START[2]) && !invalid_room(l, START_R));
	else if (!ft_strcmp(r->buf, END))
		return (!read_room(l->flags.fd->fd, r,
					END[2]) && !invalid_room(l, END_R));
	else if (r->buf[0] == '#')
		return (1);
	else if (is_it_room(r))
		return (!invalid_room(l, COMMON_R));
	else if (ft_strchr(r->buf, '-'))
		return (!invalid_link(l));
	else
		return (set_error(r, "Record format is broken,"
				" find the error and try again.", r->i + 1, ERR) - 1);
}

int			reader(t_lem *l)
{
	reader_init(l);
	while (lgnl(l->flags.fd->fd, &(l->read->buf)))
	{
		if (valid(l->read, l) == 1)
			add_to_input(l->read);
		else
		{
			free(l->read->buf);
			return (1);
		}
	}
	return (0);
}
