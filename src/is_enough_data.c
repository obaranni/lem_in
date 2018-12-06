/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enough_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:00:12 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:00:28 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int		is_enough_data(t_lem *l)
{
	if (!l->read->ants_readed)
		return (set_error(l->read,
				"Ants quantity are absent", l->read->i + 1, ERR));
	else if (!l->start)
		return (set_error(l->read,
				"Start room are absent", l->read->i + 1, ERR));
	else if (!l->end)
		return (set_error(l->read, "End room are absent", l->read->i + 1, ERR));
	return (0);
}
