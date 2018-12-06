/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:04:02 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:04:36 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			try_read(t_lem *l)
{
	if (!reader(l))
		is_enough_data(l);
	if (is_it_error(l))
	{
		free_all(l);
		return (1);
	}
	return (0);
}

int			try_find_ways(t_lem *l)
{
	find_ways(l);
	if (is_it_error(l))
	{
		free_all(l);
		return (1);
	}
	return (0);
}

int			lem_in(t_lem *l)
{
	if (try_read(l))
		return (WRONG_INPUT);
	if (try_find_ways(l))
		return (WRONG_WAYS);
	prepare_packages(l);
	prepare_ants(l);
	move_ants(l);
	return (0);
}

int			main(int ac, char **av)
{
	t_lem	l;
	int		c;

	init_lem(&l);
	init_flags(&(l.flags));
	check_arguments(&(l.flags), av, ac);
	while (l.flags.files--)
	{
		if (l.flags.fd->file && (l.flags.fd->fd =
				open(l.flags.fd->file, O_RDONLY)) == -1)
		{
			free_all(&l);
			continue ;
		}
		print_header(&l);
		if ((c = lem_in(&l)))
			return (c);
		print_footer(&l);
		free_all(&l);
		init_lem(&l);
	}
	return (0);
}
