#include "../inc/lem_in.h"

t_fd			*create_fd(void)
{
	t_fd		*temp;

	temp = (t_fd *)malloc(sizeof(t_fd));
	*temp = (t_fd){0, NULL, NULL};
	return (temp);
}

int 			get_file(t_flags *flags, char **av)
{
	t_fd		*temp;

	flags->fd = create_fd();
	temp = flags->fd;
	while (*av)
	{
		temp->file = ft_strdup(*av);
		av++;
		if (*av)
		{
			temp->next = (t_fd *)malloc(sizeof(t_fd));
			*temp->next = (t_fd){0, NULL, NULL};
			temp = temp->next;
		}
		flags->files++;
	}
//	*av = NULL;
	return (0);
}

int				get_flags_help(t_flags *flags, char **av)
{
	(*av)++;
	while (*av && **av)
	{
		if (**av == 'p')
			flags->print = 1;
		else if (**av == 'v')
			flags->vis = 1;
		else if (**av == 'b')
			flags->bad_cases = 1;
		else if (**av == 'c')
			flags->color = 1;
		else if (**av == 'f')
		{
			get_flags_help(flags, av);
			av++;
			get_file(flags, av);
			break ;
		}
		else
			return (1);
		(*av)++;
	}
	return (0);
}

int				get_flags(t_flags *flags, char **av)
{
	while (*av && **av == '-')
	{
		if (ft_strcmp(*av, "-p") == 0)
			flags->print = 1;
		else if (ft_strcmp(*av, "-v") == 0)// Рыба
			flags->vis = 1;
		else if (ft_strcmp(*av, "-b") == 0)// Рыба
			flags->bad_cases = 1;
		else if (ft_strcmp(*av, "-c") == 0)// Рыба
			flags->color = 1;
		else if ((av + 1) && ft_strcmp(*av, "-f") == 0)// Рыба
		{
			get_file(flags, av + 1);
			av++;
		}
		else if (*(*av) == '-')
			if ((av + 1) && get_flags_help(flags, av) == 1)
			{
				ft_putstr_fd("Usage: ./lem-in [-pvaof] < map\n", 2);
				exit (WRONG_ARGUMENTS);
			}
		av++;
	}
	return (0);
}

int				check_arguments(t_flags *flags, char **av, int ac)
{
	if (av[1] && av[1][0] == '-')
	{
		get_flags(flags, (av + 1));
	}
	else if (ac > 2)
	{
		ft_putstr_fd("Usage: ./lem-in [-pvbof] < map\n", 2);
		exit (WRONG_ARGUMENTS);
	}
	if (flags->fd == NULL)
	{
		flags->fd = create_fd();
		flags->fd->fd = 0;
		flags->files = 1;
	}
	return (0);
}