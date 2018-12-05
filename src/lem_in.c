#include "../inc/lem_in.h"

void        init_flags(t_flags *flags)
{
    flags->vis = 0;
    flags->bad_cases = 0;
    flags->print = 0;
    flags->fd = 0;
}

void		init_lem(t_lem *l)
{
	l->start = NULL;
	l->end = NULL;
	l->head = NULL;
	l->ways = NULL;
	l->packages = NULL;
	init_flags(&l->flags);
}

int 		is_enough_data(t_lem *l)
{
	if (!l->read->ants_readed)
		return (set_error(l->read, "Ants quantity are absent", l->read->i + 1, ERR));
	else if (!l->start)
		return (set_error(l->read, "Start room are absent", l->read->i + 1, ERR));
	else if (!l->end)
		return (set_error(l->read, "End room are absent", l->read->i + 1, ERR));
	return (0);
}

int 		is_it_error(t_lem *l) // TODO: something with errors doljno byt
{
	t_err	*tmp_err;
	int 	is_err;

	is_err = 0;
	tmp_err = l->read->errors;
	while (tmp_err)
	{
		if (tmp_err->lvl == 2)
			is_err = 1;
		if (tmp_err->lvl == 1)
			ft_putstr("A warning occurred on the ");
		else
			ft_putstr("An error occurred on the ");
		ft_putnbr(tmp_err->line);
		ft_putendl(" line.");
		ft_putstr("Explanation message: ");
		ft_putendl(tmp_err->msg);
		ft_putchar('\n');
		tmp_err = tmp_err->next;
	}
	return (is_err);
}

int 		try_read(t_lem *l)
{
	if (!reader(l))
		is_enough_data(l);
	if (is_it_error(l))
	{
		free_all(l);
//		system("leaks lem-in");
		return (1);
	}
	return (0);
}

int 		try_find_ways(t_lem *l)
{
	find_ways(l);
	if (is_it_error(l))
	{
		free_all(l);
//		system("leaks lem-in");
		return (1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_lem l;

    init_lem(&l);
	check_arguments(&(l.flags), av, ac);
	if (try_read(&l))
		return (WRONG_INPUT);
	if (try_find_ways(&l))
		return (WRONG_WAYS);


	create_packages(&l);
//	get_best_package(&l);

	free_all(&l);
//	system("leaks lem-in");
	return (0);
}
