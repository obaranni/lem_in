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
	struct timespec tstart, tend;


	tstart.tv_nsec = 0;
	tstart.tv_sec = 0;
	tend.tv_nsec = 0;
	tend.tv_sec = 0;
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	if (try_read(l))
		return (WRONG_INPUT);
	clock_gettime(CLOCK_MONOTONIC, &tend);
	printf("reading took about %.5f seconds\n",
		   ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
		   ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));


	tstart.tv_nsec = 0;
	tstart.tv_sec = 0;
	tend.tv_nsec = 0;
	tend.tv_sec = 0;
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	if (try_find_ways(l))
		return (WRONG_WAYS);
	clock_gettime(CLOCK_MONOTONIC, &tend);
	printf("ways finding took about %.5f seconds\n",
		   ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
		   ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

	print_outline(l);

	tstart.tv_nsec = 0;
	tstart.tv_sec = 0;
	tend.tv_nsec = 0;
	tend.tv_sec = 0;
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	prepare_packages(l);
	clock_gettime(CLOCK_MONOTONIC, &tend);
	printf("pack preparing took about %.5f seconds\n",
		   ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
		   ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));


	tstart.tv_nsec = 0;
	tstart.tv_sec = 0;
	tend.tv_nsec = 0;
	tend.tv_sec = 0;
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	prepare_ants(l);
	clock_gettime(CLOCK_MONOTONIC, &tend);
	printf("ants preparing took about %.5f seconds\n",
		   ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
		   ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));


	tstart.tv_nsec = 0;
	tstart.tv_sec = 0;
	tend.tv_nsec = 0;
	tend.tv_sec = 0;
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	move_ants(l);
	clock_gettime(CLOCK_MONOTONIC, &tend);
	printf("ants moving took about %.5f seconds\n",
		   ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -
		   ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
	return (0);
}
// TODO: invalid links like start-1-1-1-1-1 should be fixed
// TODO: put all print calls into one function witch should be called after moving ants (except ants moving)
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
			print_error_msg(&l.flags, l.flags.fd->file);
			print_error_msg(&l.flags, " does not exist!\n\n");
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
