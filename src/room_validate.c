/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_validate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:33:09 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 16:27:38 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

int			invalid_room_name(t_read *r, char *name, t_lem *l)
{
	t_room	*tmp;

	tmp = l->head;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (set_error(r, "Room with same name exist", r->i + 1, ERR));
		tmp = tmp->next;
	}
	if (l->flags.vis && ft_strlen(name) > MAX_NAME_R)
	{
		return (set_error(r, "Room cannot be visualized, too long name",
				r->i + 1, ERR));
	}
	return (0);
}

int			is_digits_in_coord(char *c)
{
	if ((*c == '+' || *c == '-') && *(c + 1) && *(c + 1) != '0')
		c++;
	while (*c)
	{
		if (!ft_isdigit(*c))
			return (0);
		c++;
	}
	return (1);
}

int			invalid_room_coord(t_read *r, char *c_x, char *c_y, t_lem *l)
{
	int		x;
	int		y;
	t_room	*tmp;

	if (!is_digits_in_coord(c_x) || !is_digits_in_coord(c_y))
		return (set_error(r, "Invalid coordinates!", r->i, ERR));
	x = ft_atoi(c_x);
	y = ft_atoi(c_y);
	tmp = l->head;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
		{
			return (set_error(r, "The room could not be visualized, due to"
								" overlapping coordinates.", r->i + 1, ERR));
		}
		tmp = tmp->next;
	}
	return (0);
}

int			count_chars(char *s, char c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s == c)
			i++;
		s++;
	}
	return (i);
}

int			is_it_room(t_read *r)
{
	int		i;
	char	**strs;

	if (count_chars(r->buf, ' ') > 2)
		return (0);
	strs = ft_strsplit(r->buf, ' ', 0);
	i = 0;
	while (strs && strs[i])
		i++;
	free_str_arr(strs);
	return (i == 3);
}
