#include "../inc/lem_in.h"

void		add_room(t_lem *l, char **room)
{
	t_room	*tmp;
	t_room	*new;

	tmp = l->head;
	new = (t_room*)malloc(sizeof(t_room));
	new->name = room[0];
	new->x = ft_atoi(room[1]);
	new->x = ft_atoi(room[2]);
	new->next = 0;
	free(room);
	if (l->head == 0)
	{
		l->head = new;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}