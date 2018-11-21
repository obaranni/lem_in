#include "../inc/lem_in.h"

int 		is_enough_data()
{
	if (1)
	{
		ft_putendl("Enough. Continue execution...");
		return (1);
	}
	else
		ft_putendl("Missing ? !!!");
	return (0);
}

int 		is_it_error(t_lem *l)
{
	if (l->read->error.err_lvl == 1)
	{
		ft_putstr("Lite error at line ");
		ft_putnbr(l->read->error.err_line);
		ft_putendl(".");
		ft_putstr("Error message: ");
		ft_putendl(l->read->error.err_msg);
		ft_putendl("The program will continue execution if the received data is sufficient.\nRevision...");
		if (is_enough_data())
			return (0);
	}
	else if (l->read->error.err_lvl == 2)
	{
		ft_putstr("Critical error at line ");
		ft_putnbr(l->read->error.err_line);
		ft_putendl(".");
		ft_putstr("Error message: ");
		ft_putendl(l->read->error.err_msg);
	}
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
