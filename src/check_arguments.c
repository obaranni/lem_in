#include "../inc/lem_in.h"

int 			get_file(t_flags *flags, char *s)
{
	flags->file = 1;
	flags->fd = open(s, O_RDONLY);
	if (flags->fd < 0)
	{
		ft_putendl_fd("Wrong file!", 2);
		exit(WRONG_FILE);
	}
	return (0);
}


int				get_flags_help(t_flags *flags, char *av, char *file)
{
	while (*av)
	{
		if (*av == 'p')
			flags->print = 1;
		else if (*av == 'v')
			flags->vis = 1;
		else if (*av == 'b')
			flags->bad_cases = 1;
		else if (*av == 'o')
			flags->o_visual = 1;
		else if (*av == 'f')
		{
			get_file(flags, file);
		}
		else
			return (1);
		av++;
	}
	return (0);
}

int				get_flags(t_flags *flags, char **av)
{
	int			counter;

	counter = 0;
	while (av[counter] && *(av[counter]) == '-')
	{
		if (ft_strcmp(av[counter], "-p") == 0)
			flags->print = 1;
		else if (ft_strcmp(av[counter], "-v") == 0)// Рыба
			flags->vis = 1;
		else if (ft_strcmp(av[counter], "-b") == 0)// Рыба
			flags->bad_cases = 1;
		else if (ft_strcmp(av[counter], "-o") == 0)// Рыба
			flags->o_visual = 1;
		else if (av[counter + 1] && ft_strcmp(av[counter], "-f") == 0)// Рыба
		{
			get_file(flags, av[counter + 1]);
			counter++;
		}
		else if (*(av[counter]) == '-')
			if (av[counter + 1] && get_flags_help(flags, (av[counter] + 1), av[counter + 1]) == 1)
			{
				ft_putstr_fd("Usage: ./lem-in [-pvaof] < map\n", 2);
				exit (WRONG_ARGUMENTS);
			}
		counter++;
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
	return (0);
}