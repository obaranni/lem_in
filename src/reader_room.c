#include "../inc/lem_in.h"

int 		read_room(t_read *r, char which)
{
	get_next_line(0, &r->buf);
	if (ft_strlen(r->buf) < 5)
	{
		if (which == 's')
			set_error(r, "Absent START room", r->i + 1, ERR);
		else
			set_error(r, "Absent END room", r->i + 1, ERR);
		return (0);
	}
	return (1);
}

int 		valid_room_name(t_read *r, char *name, t_lem *l)
{
	t_room	*tmp;
	int 	i;

	i = 0;
	tmp = l->start;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name))
		{
			set_error(r, "Room with same name exist", r->i + 1, ERR);
			return (1);
		}
		tmp = tmp->next;
	}
	while (name[i])
	{
		if (!ft_isalpha(name[i]) && !ft_isdigit(name[i]))
		{
			set_error(r, "Room name should contain alphabet and digits", r->i + 1, ERR);
			return (1);
		}
		i++;
	}
	if (i > 11)	// ???
	{
		set_error(r, "Room name must not exceed 10", r->i + 1, ERR);
		return (1);
	}
	return (0);
}

int 		valid_room_coord(t_read *r, int x, int y, t_lem *l)
{
	t_room	*tmp;

	tmp = l->start;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
		{
			set_error(r, "Room with same coordinates exist", r->i + 1, ERR);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int 		is_it_room(t_read *r)
{
	int		i;
	char 	**strs;

	strs = ft_strsplit(r->buf, ' ');
	i = 0;
	while (strs[i])
		i++;
	free_str_arr(strs);
	if (i == 3)
		return (0);
	return (1);
}

// proverky na 'L'
int 		valid_room(t_read *r, t_lem *l)
{
	char 	**strs;

	strs = ft_strsplit(r->buf, ' ');
	if (is_it_room(r))
	{
		set_error(r, "Invalid room", r->i + 1, ERR);
		return (0);
	}
	if (valid_room_name(r, strs[0], l) ||
		valid_room_coord(r, ft_atoi(strs[1]), ft_atoi(strs[2]), l))
		return (1);
	add_room(l, strs);
	//free(strs);
	return (0);
}