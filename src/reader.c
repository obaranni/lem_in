#include "../inc/lem_in.h"



void		add_to_input(t_read *r)
{
	r->input[r->i] = (char*)malloc(sizeof(char) * ft_strlen(r->buf));
	ft_strcpy(r->input[r->i], r->buf);
	r->i++;
	//free(r->buf);
}



int 		valid(t_read *r, t_lem *l)
{
	if (is_it_ants(r))
	{
		if (r->ants_readed)
		{
			set_error(r, "Ants already readed!", r->i + 1, WAR);
			return (0);
		}
		read_ants(r);
		return (1);
	}
	else if (!ft_strcmp(r->buf, START))
	{
		if (!read_room(r, START[2]))
			if (!invalid_room(r, l))
				return (1);
	}
	else if (!ft_strcmp(r->buf, END))
	{
		if (!read_room(r, END[2]))
			if (!invalid_room(r, l))
				return (1);
	}
	else if (r->buf[0] == '#')
		add_to_input(r);
	else if (is_it_room(r))
	{
		if (!invalid_room(r, l))
			return (1);
	}
	return (0);
}

// check is it dir, do i have permissions

int         reader(t_lem *l)
{
	t_read	*r;

	r = (t_read*)malloc(sizeof(t_read));
	r->ants_readed = 0;
	r->error.err_lvl = 0;
	l->read = r;
	l->start = 0;
	l->end = 0;
	l->head = 0;
	r->i = 0;
	r->input = (char **)malloc(sizeof(char*) * MAX);
	while (r->i < MAX && get_next_line(0, &r->buf))
	{
    	if (r->buf[0] && valid(r, l))
    		add_to_input(r);
		else
		{
			//if (r->buf[0])
			//	free(r->buf);
			if (r->error.err_lvl == 2)
				return (1);
			else
				break ;
		}
	}
	return (0);
}