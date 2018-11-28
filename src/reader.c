#include "../inc/lem_in.h"


void		add_to_input(t_read *r)
{
//	r->input[r->i] = (char*)malloc(sizeof(char) * ft_strlen(r->buf));
//	ft_strcpy(r->input[r->i], r->buf);
	r->in_str = (char*)malloc(sizeof(char) * ft_strlen(r->buf));
	ft_strcpy(r->input[r->i], r->buf);
	r->i++;
	free(r->buf);
}

int 		valid(t_read *r, t_lem *l)
{
	if (is_it_ants(r))
		return (read_ants(r));
	else if (!ft_strcmp(r->buf, START))
		return (!read_room(r, START[2]) && !invalid_room(l, START_R));
	else if (!ft_strcmp(r->buf, END))
		return(!read_room(r, END[2]) && !invalid_room(l, END_R));
	else if (r->buf[0] == '#')
		return (1);
	else if (is_it_room(r))
		return (!invalid_room(l, COMMON_R));
	else if (ft_strchr(r->buf, '-'))
		return (!invalid_link(l));
	else
		return (set_error(r, "Record format is broken, find the error and try again.", r->i + 1, ERR) - 1);
}

void		reader_init(t_lem *l)
{
	l->read = (t_read*)malloc(sizeof(t_read));
	l->read->errors = NULL;
	l->read->ants_readed = 0;
	l->read->i = 0;
	l->start = NULL;
	l->end = NULL;
	l->head = NULL;
	l->read->input = (char **)malloc(sizeof(char*) * MAX_INSTR);
}

int         reader(t_lem *l)
{
	reader_init(l);
	// TODO: change MAX_INSTR to reading into one string with \n's
	while (l->read->i < MAX_INSTR && lgnl(fd, &(l->read->buf)))
	{
    	if (l->read->buf[0] && l->read->buf[0] != 10 && valid(l->read, l))
    		add_to_input(l->read);
		else
		{
			free(l->read->buf);
			return (1);
		}
	}
	return (0);
}