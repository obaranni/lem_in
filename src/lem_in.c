#include "../inc/lem_in.h"

void		init_lem(t_lem *l)
{
	l->start = NULL;
	l->end = NULL;
	l->head = NULL;
	l->ways = NULL;
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

int 		is_it_error(t_lem *l)
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
		ft_putendl("");
		tmp_err = tmp_err->next;
	}
	return (is_err);
}

int			main(void)
{
	t_lem l;

	fd = open("/Users/obaranni/projects/lem_in/testing_files/valid13", O_RDONLY);
	init_lem(&l);
	l.vis = 1; // TODO: visual mod
	if (!reader(&l))
		is_enough_data(&l);
	if (is_it_error(&l))
	{
//    	free_all(l.read->input);
		return (1);
	}
	find_ways(&l);
	//system("leaks lem-in");
	return (0);
}
