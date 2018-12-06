/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:48:31 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:48:32 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int				get_flags_help3(t_flags *flags, char **av)
{
	if (ft_strcmp(*av, "-p") == 0)
		flags->packages = 1;
	else if (ft_strcmp(*av, "-a") == 0)
		flags->ants = 1;
	else if (ft_strcmp(*av, "-w") == 0)
		flags->ways = 1;
	else if (ft_strcmp(*av, "-i") == 0)
		flags->info = 1;
	else if (ft_strcmp(*av, "-v") == 0)
		flags->vis = 1;
	else if (ft_strcmp(*av, "-b") == 0)
		flags->bad_cases = 1;
	else if (ft_strcmp(*av, "-c") == 0)
		flags->color = 1;
	else
		return (0);
	return (1);
}

int				get_flags_help2(t_flags *flags, char **av)
{
	if (**av == 'p')
		flags->packages = 1;
	else if (**av == 'a')
		flags->ants = 1;
	else if (**av == 'w')
		flags->ways = 1;
	else if (**av == 'i')
		flags->info = 1;
	else if (**av == 'v')
		flags->vis = 1;
	else if (**av == 'b')
		flags->bad_cases = 1;
	else if (**av == 'c')
		flags->color = 1;
	else
		return (0);
	return (1);
}

int				get_flags_help(t_flags *flags, char **av)
{
	(*av)++;
	while (*av && **av)
	{
		if (get_flags_help2(flags, av))
		{
			(*av)++;
			continue;
		}
		else if (**av == 'f')
		{
			get_flags_help(flags, av);
			av++;
			get_file(flags, av);
			break ;
		}
		else
			return (1);
	}
	return (0);
}

int				get_flags(t_flags *flags, char **av)
{
	while (*av && **av == '-')
	{
		if (get_flags_help3(flags, av))
		{
			av++;
			continue;
		}
		else if ((av + 1) && ft_strcmp(*av, "-f") == 0)
		{
			get_file(flags, av + 1);
			av++;
		}
		else if (*(*av) == '-')
			if ((av + 1) && get_flags_help(flags, av) == 1)
			{
				print_usage();
				exit(WRONG_ARGUMENTS);
			}
		av++;
	}
	return (0);
}

int				check_arguments(t_flags *flags, char **av, int ac)
{
	if (av[1] && av[1][0] == '-')
		get_flags(flags, (av + 1));
	else if (ac > 2)
	{
		print_usage();
		exit(WRONG_ARGUMENTS);
	}
	if (flags->fd == NULL)
	{
		flags->fd = create_fd();
		flags->fd->fd = 0;
		flags->files = 1;
	}
	return (0);
}
