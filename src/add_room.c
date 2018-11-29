#include "../inc/lem_in.h"

void		add_room(t_lem *l, char **room, int is_spec)
{
	t_room	*tmp;
	t_room	*new;

	tmp = l->head;
	new = (t_room *)malloc(sizeof(t_room));

	new->name = ft_strdup(room[0]);

	new->x = ft_atoi(room[1]);
	new->y = ft_atoi(room[2]);
	new->way_id = -1;
	new->is_processed = NOT_PROCESSED;

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