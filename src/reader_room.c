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
	get_next_line(0, &r->buf);
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
	int 	i;

	i = 0;

	tmp = l->head;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (set_error(r, "Room with same name exist", r->i + 1, ERR));
		tmp = tmp->next;
	}
	while (name[i])
	{
		if (!ft_isalpha(name[i]) && !ft_isdigit(name[i]))
			return (set_error(r, "Room name should contain alphabet and digits", r->i + 1, ERR));
		i++;
	}
	if (i > MAX_NAME_R)	// ???
		return (set_error(r, "Room name must not exceed 10", r->i + 1, ERR));
	return (0);
}

int 		invalid_room_coord(t_read *r, int x, int y, t_lem *l)
{
	t_room	*tmp;

	tmp = l->head;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (set_error(r, "Room with same coordinates exist", r->i + 1, ERR));
		tmp = tmp->next;
	}
	return (0);
}

int 		is_it_room(t_read *r)
{
	int		i;
	char 	**strs;
	char 	*tofree;

	tofree = ft_strdup(r->buf);
	strs = ft_strsplit(tofree, ' ', 1);
	free(tofree);
	i = 0;
	if (!strs)
		return (set_error(r, "Garbage instead of room", r->i + 1, ERR) - 1);
	while (strs[i])
		i++;
	if (i == 3)
		return (1);
	return (set_error(r, "It does not look like a room", r->i + 1, ERR) - 1);
}

// proverky na 'L'
int 		invalid_room(t_lem *l, int is_spec)
{
	char 	**strs;

	if (!is_it_room(l->read))
		return (1);
	strs = ft_strsplit(l->read->buf, ' ', 1);
	if (invalid_room_name(l->read, strs[0], l) ||
			invalid_room_coord(l->read, ft_atoi(strs[1]),
					ft_atoi(strs[2]), l) || (is_spec && extra_se_room(l, is_spec)))
		return (1);
	add_room(l, strs, is_spec);
	return (0);
}