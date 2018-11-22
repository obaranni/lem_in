#include "../inc/lem_in.h"

int 		is_enough_data(t_lem *l)
{
	if (!l->read->ants_readed || l->start)
		set_error(l->read, "Ants quantity are absent", l->read->i + 1, 2);
	else if (!l->start)
		set_error(l->read, "Start room are absent", l->read->i + 1, 2);
	else if (!l->end)
		set_error(l->read, "End room are absent", l->read->i + 1, 2);
	return (0);
}

int 		is_it_error(t_lem *l)
{
	if (l->read->error.err_lvl != 2)
		is_enough_data(l);
	if (l->read->error.err_lvl == 1)
	{
		ft_putstr("Lite error at line ");
		ft_putnbr(l->read->error.err_line);
		ft_putendl(".");
		ft_putstr("Error message: ");
		ft_putendl(l->read->error.err_msg);
		ft_putendl("The program will continue execution if the received data is sufficient.\nRevision...");
	}
	else if (l->read->error.err_lvl == 2)
	{
		ft_putstr("Critical error at line ");
		ft_putnbr(l->read->error.err_line);
		ft_putendl(".");
		ft_putstr("Error message: ");
		ft_putendl(l->read->error.err_msg);
	}
	else
		ft_putendl("({[no errors]})");
	ft_putendl("Terminating program");
	return (1);
}

int			main(void)
{
	t_lem	l;
    reader(&l);
    if (is_it_error(&l))
    {
    	free(l.read->input);
		return (1);
	}
    int i;
    i = 0;
    while (i < MAX && i < l.read->i)
	{
    	printf("%s\n", l.read->input[i]);
    	i++;
	}
	return (0);
}
