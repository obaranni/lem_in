/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:17:57 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:18:16 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			is_it_ants(t_read *r)
{
	char	*box;

	box = r->buf;
	if (r->buf && *r->buf)
	{
		while (*box)
		{
			if (!ft_isdigit(*box))
				return (0);
			box++;
		}
	}
	return (1);
}

int			read_ants(t_read *r)
{
	if (r->ants_readed)
	{
		set_error(r, "Ants already read!", r->i + 1, ERR);
		return (0);
	}
	r->ants_readed = (unsigned int)ft_atoi(r->buf);
	if (ft_strlen(r->buf) != (size_t)ft_pwrbase(r->ants_readed, 10))
	{
		set_error(r, "Too many ants!", r->i + 1, ERR);
		return (0);
	}
	return (1);
}
