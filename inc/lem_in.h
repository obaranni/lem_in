/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:12:48 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/24 15:14:24 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include <stdio.h>
# include "stdlib.h"
# define START "##start"
# define END "##end"
# define MAX 4096
# define WAR 1
# define ERR 2


typedef struct      s_room
{
	char 			*name;
	int 			x;
	int 			y;
	struct s_room	*start;
	struct s_room	*next;
}                   t_room;

typedef struct		s_err
{
	char 			*err_msg;
	int 			err_line;
	int 			err_lvl;
}					t_err;

typedef struct		s_read
{
	int 			i;
	int 			ants_readed;
	int 			ants;
	char            **input;
	char 			*buf;
	t_err			error;
}					t_read;

typedef struct      s_lem
{
	t_read			*read;
 	t_room			*start;
 	t_room			*end;
}                   t_lem;
void				add_room(t_lem *l, char **room);
int					is_it_room(t_read *r);
void				free_str_arr(char **strs);
void 				set_error(t_read *r, char *err_msg, int err_line, int err_lvl);
int					is_it_ants(t_read *r);
int					read_ants(t_read *r);
int					valid_room(t_read *r, t_lem *l);
int					read_room(t_read *r, char which);
int 				reader(t_lem *l);

#endif
