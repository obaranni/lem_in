/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:58:58 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 14:59:00 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void		init_flags(t_flags *flags)
{
	flags->vis = 0;
	flags->bad_cases = 0;
	flags->packages = 0;
	flags->ants = 0;
	flags->info = 0;
	flags->ways = 0;
	flags->steps = 0;
	flags->outline = 0;
	flags->color = 0;
	flags->files = 0;
	flags->fd = NULL;
}

void		init_lem(t_lem *l)
{
	l->start = NULL;
	l->end = NULL;
	l->head = NULL;
	l->ways = NULL;
	l->packages = NULL;
	l->read = NULL;
}

void		reader_init(t_lem *l)
{
	l->read = (t_read*)malloc(sizeof(t_read));
	l->read->errors = NULL;
	l->read->ants_readed = 0;
	l->read->i = 0;
	l->read->input = NULL;
}
