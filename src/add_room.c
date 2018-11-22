#include "../inc/lem_in.h"

void		add_room(t_lem *l, char **room, int is_spec)
{
	t_room	*tmp;
	t_room	*new;

	tmp = l->head;
	new = (t_room*)malloc(sizeof(t_room));
	new->name = room[0];
	new->x = ft_atoi(room[1]);
	new->y = ft_atoi(room[2]);
	new->next = 0;
	free(room[1]);
	free(room[2]);
	free(room);
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