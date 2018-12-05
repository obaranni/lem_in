#include "../inc/lem_in.h"

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
		system("leaks lem-in");
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
		system("leaks lem-in");
		return (1);
	}
	return (0);
}

//TODO: colors, printing flags for ants, packages, ways, ways+info, bad_cases, color flag

int			main(int ac, char **av)
{
	t_lem l;

	init_lem(&l);
	init_flags(&(l.flags));
	check_arguments(&(l.flags), av, ac);
	while (l.flags.files--)
	{
		if (l.flags.fd->file && (l.flags.fd->fd = open(l.flags.fd->file, O_RDONLY)) == -1)
		{
			//message about bad file
			free_all(&l);
			continue ;
		}
		ft_putstr("Input sources: ");
		if (l.flags.fd->file)
			ft_putendl(l.flags.fd->file);
		else
			ft_putstr("manual");
		ft_putstr("\n");
		if (try_read(&l))
			return (WRONG_INPUT);
		if (try_find_ways(&l))
			return (WRONG_WAYS);
		prepare_packages(&l);
		prepare_ants(&l);
		move_ants(&l);
		ft_putstr("\nend of: ");
		if (l.flags.fd->file)
			ft_putendl(l.flags.fd->file);
		else
			ft_putstr("manual");
		ft_putstr("\n\n");
		free_all(&l);
		init_lem(&l);
	}
		//	system("leaks lem-in");
	return (0);
}
