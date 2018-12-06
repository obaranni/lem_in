/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:43:50 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:44:35 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		append_error(t_read *r, t_err *new_err)
{
	t_err	*tmp;

	if (!r->errors)
	{
		r->errors = new_err;
		return ;
	}
	tmp = r->errors;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_err;
}

int			set_error(t_read *r, char *err_msg, int err_line, int err_lvl)
{
	t_err	*new_err;

	new_err = (t_err*)malloc(sizeof(t_err));
	new_err->msg = (char*)malloc(sizeof(char)
		* (ft_strlen(err_msg) + 1));
	ft_strcpy(new_err->msg, err_msg);
	new_err->line = err_line;
	new_err->lvl = err_lvl;
	new_err->next = NULL;
	append_error(r, new_err);
	return (1);
}
