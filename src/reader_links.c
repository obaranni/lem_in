#include "../inc/lem_in.h"

int 		is_room_exist(char *name, t_room *room)
{
	int 	exist;

	exist = 0;
	while (room)
	{
		if (!ft_strcmp(room->name, name))
		{
			exist = 1;
			break;
		}
		room = room->next;
	}
	return (exist);
}

int 		invalid_rooms(char *n1, char *n2, t_lem *l)
{
	char 	*err;

	if (!is_room_exist(n1, l->head))
		err = ft_strjoin("There are no rooms with name: ", n1);
	else if (!is_room_exist(n2, l->head))
		err = ft_strjoin("There are no rooms with name: ", n2);
	else
		return (0);
	set_error(l->read, err, l->read->i, ERR);
	free(err);
	return (1);
}

int 		is_it_link(t_lem *l)
{
	char 	**strs;

	strs = ft_strsplit(l->read->buf, '-', 1);
	if (!strs || !strs[0] || !strs[1] || strs[2])
	{
		free_str_arr(strs);
		return (0);
	}
	return (1);
}


// relink     			rooma-rooma						-
// invalid name			rooma-romb						-
// double link			rooma-roomb  => roomb-rooma		-

int 		invalid_link(t_lem *l)
{
	char 	**strs;

	strs = ft_strsplit(l->read->buf, '-', 1);
	if (invalid_rooms(strs[0], strs[1], l))
		return (1);
	return(0);
}