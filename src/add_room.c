#include "../inc/lem_in.h"

void		add_room(t_lem *l, char **room, int is_spec)
{
	t_room	*tmp;
	t_room	*new;

	tmp = l->head;
	new = (t_room*)malloc(sizeof(t_room));
	new->name = (char*)malloc(sizeof(char) * (ft_strlen(room[0]) + 1));
	ft_strcpy(new->name, room[0]);
	new->x = ft_atoi(room[1]);
	new->y = ft_atoi(room[2]);
	new->next = 0;
	new->neighbors = 0;
	free_str_arr(room);
	if (is_spec == 1)
		l->start = new;
	else if (is_spec == 2)
		l->end = new;
	if (l->head == 0)
	{
		l->head = new;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void		append_neigh(t_room *main, t_room *to_append)
{
	t_neigh	*tmp;
	t_neigh	*new;

	new = (t_neigh*)malloc(sizeof(t_neigh*));
	new->origin = to_append;
	new->next = 0;
	if (main->neighbors == 0)
	{
		main->neighbors = new;
		return;
	}
	tmp = main->neighbors;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void		link_rooms(t_room *r1, t_room *r2)
{
	append_neigh(r1, r2);
	append_neigh(r2, r1);
}