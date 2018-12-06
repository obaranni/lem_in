/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:03:26 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:03:43 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			is_it_error(t_lem *l)
{
	t_err	*tmp_err;
	int		is_err;

	is_err = 0;
	tmp_err = l->read->errors;
	if (l->flags.color)
		ft_putstr(L_RED);
	while (tmp_err)
	{
		if (tmp_err->lvl == 2)
			is_err = 1;
		print_error(tmp_err);
		tmp_err = tmp_err->next;
	}
	if (l->flags.color)
		ft_putstr(RESET);
	return (is_err);
}
