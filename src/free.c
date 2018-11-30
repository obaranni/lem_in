#include "../inc/lem_in.h"

void		free_str_arr(char **strs)
{
	int 	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void		free_neighbors(t_neigh *neigh)
{
	t_neigh	*tmp_n;

	while (neigh)
	{
		tmp_n = neigh;
		free(neigh);
		neigh = tmp_n->next;
	}
}

void		free_room(t_room *room)
{

	free_neighbors(room->neighbors);
	free(room->name);
	free(room);
}

void		free_rooms(t_room *head)
{
	t_room	*tmp;

	while (head)
	{
		tmp = head;
		free_room(head);
		head = tmp->next;
	}
}

void		free_errors(t_err *errors)
{
	t_err	*tmp;


	while (errors)
	{
		tmp = errors;
		free(errors->msg);
		free(errors);
		errors = tmp->next;
	}
}

void		free_ways(t_room **ways)
{
	int 	i;

	while (ways && ways[i])
	{
		free_rooms(ways[i]);
		i++;
	}
	if (ways)
		free(ways);
}

void		free_all(t_lem *l)
{
	free_rooms(l->head);
	free(l->read->input);
	free_errors(l->read->errors);
	free(l->read);
	free_ways(l->ways);
}