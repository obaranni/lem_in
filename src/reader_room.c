#include "../inc/lem_in.h"

int			extra_se_room(t_lem *l, int is_spec)
{
	if (is_spec == 1 && l->start)
		return (set_error(l->read, "Extra START room", l->read->i + 1, ERR));
	else if (is_spec == 2 && l->end)
		return(set_error(l->read, "Extra END room", l->read->i + 1, ERR));
	return (0);
}

int 		read_room(t_read *r, char which)
{
	add_to_input(r);
	get_next_line(fd, &r->buf);
	if (ft_strlen(r->buf) < 5)
	{
		if (which == 's')
			return (set_error(r, "Absent START room", r->i + 1, ERR));
		else
			return (set_error(r, "Absent END room", r->i + 1, ERR));
	}
	return (0);
}

int 		invalid_room_name(t_read *r, char *name, t_lem *l)
{
	t_room	*tmp;

	tmp = l->head;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (set_error(r, "Room with same name exist", r->i + 1, ERR));
		tmp = tmp->next;
	}
	if (l->vis && ft_strlen(name) > MAX_NAME_R)
		return (set_error(r, "Room cannot be visualized, too long name", r->i + 1, ERR));
	return (0);
}

int 		invalid_room_coord(t_read *r, int x, int y, t_lem *l)
{
	t_room	*tmp;

	tmp = l->head;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (set_error(r, "The room could not be visualized, due to overlapping coordinates.", r->i + 1, ERR));
		tmp = tmp->next;
	}
	return (0);
}

int 		is_it_room(t_read *r)
{
	int		i;
	char 	**strs;

	strs = ft_strsplit(r->buf, ' ', 1);
	i = 0;
	while (strs && strs[i])
		i++;
	free_str_arr(strs);
	return (i != 3 ? 0 : 1);
}

int 		invalid_room(t_lem *l, int is_spec)
{
	char 	**strs;

	if (!is_it_room(l->read))
		return (set_error(l->read, "It does not look like a room", l->read->i + 1, ERR) - 1);
	if (l->read->buf[0] == 'L')
		return (set_error(l->read, "Room should not start from \'L\' letter", l->read->i + 1, ERR) - 1);
	strs = ft_strsplit(l->read->buf, ' ', 1);

	if ((l->vis && invalid_room_coord(l->read, ft_atoi(strs[1]),
			ft_atoi(strs[2]), l)) ||
			invalid_room_name(l->read, strs[0], l) ||
			(is_spec && extra_se_room(l, is_spec)))
	{
		free_str_arr(strs);
		return (1);
	}
	add_room(l, strs, is_spec);
	return (0);
}