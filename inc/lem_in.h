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
# include <sys/stat.h>
# include <fcntl.h>
# define WRONG_ARGUMENTS 2
# define WRONG_FILE 3
# define WRONG_INPUT 4
# define WRONG_WAYS 5
# define START "##start"
# define END "##end"
# define COMMON_R 0
# define START_R 1
# define END_R 2
# define MAX_NAME_R 11
# define WAR 1
# define ERR 2
# define NOT_PROCESSED 0
# define PROCESSED 1
# define INT_MAX 2147483647

typedef struct      s_room	t_room;
typedef struct		s_neigh t_neigh;
typedef struct		s_err	t_err;
typedef struct		s_ant	t_ant;
typedef struct		s_pack	t_pack;

struct				s_neigh
{
	t_room			*origin;
	t_neigh			*next;
};

struct      		s_room
{
	char 			*name;
	int 			x;
	int 			y;
	t_neigh			*neighbors;
	t_room			*next;
	int 			way_id;
	int 			is_processed;
};

typedef struct		s_ant
{
	int				id;
	t_room			*way;
	t_ant			*next;
}					t_ant;

typedef struct		s_pack
{
	int 			id;
	int 			ants_setted;
	int 			ways_num;
	int 			total_steps;
	t_ant			*ants;
	float 			*ways_capacity;
	int 			*ants_on_ways;
	int 			*load_on_ways;
	t_room			**parallel_ways;
	t_pack			*next;
}					t_pack;

typedef struct		s_err
{
	char 			*msg;
	int 			line;
	int 			lvl;
	t_err			*next;
}					t_err;

typedef struct		s_read
{
	int 			i;
	unsigned int	ants_readed;
	char            *input;
	char			*buf;
	char 			*l_r1;
	char 			*l_r2;
	t_err			*errors;
}					t_read;

typedef struct		s_fd
{
	int 			fd;
	char 			*name;
	struct s_fd		*next;
}					t_fd;

typedef struct		s_flags
{
	int 			print:1;
	int				vis:1;
	int				bad_cases:1;
	int				o_visual:1;
	int 			fd;
}					t_flags;

typedef struct      s_lem
{
	t_flags			flags;
	t_read			*read;
	t_room			*head;
 	t_room			*start;
 	t_room			*end;
 	t_room			**ways;
 	t_pack			*packages;
}                   t_lem;

/*
** Check arguments
*/

int					check_arguments(t_flags *flags, char **av, int ac);

/*
**	 Reader | rooms functions
*/

int					is_it_room(t_read *r);
void				add_room(t_lem *l, char **room, int is_spec);
int					invalid_room(t_lem *l, int is_spec);
int					read_room(int fd, t_read *r, char which);

/*
**	 Reader | links functions
*/

t_room				*find_room_byname(t_room *room, char *name);
void				link_rooms(t_room *r1, t_room *r2);
int 				is_it_link(t_lem *l, t_read *r);
int					invalid_link(t_lem *l);

/*
**	 Reader | ants functions
*/

int					is_it_ants(t_read *r);
int					read_ants(t_read *r);

/*
**	 Free functions
*/

void				free_ways(t_room **ways);
void				free_room(t_room *room);
void				free_rooms(t_room *room);
void				free_neighbors(t_neigh *neigh);
void				free_all(t_lem *l);
void				free_str_arr(char **strs);
void				free_errors(t_err *errors);

/*
**	 Error functions
*/

int 				set_error(t_read *r, char *err_msg, int err_line, int err_lvl);

/*
**	 Reader | general functions
*/

void				add_to_input(t_read *r);
int 				reader(t_lem *l);

/*
**	 BFS (ways finding)
*/

int 				count_steps(t_room* way, int ants);
int					find_ways(t_lem *l);

/*
**	 Ways functions
*/

void				upend_way(t_room ***ways, t_room *new_part);
int 				get_way_id(t_room **ways);

/*
**	 Packages functions
*/

void				remove_same_packages(t_lem *l);
void				set_packages_capacity(t_pack *pack);
void				prepare_packages(t_lem *l);
void				set_ants_quantity_on_ways(t_lem *l, t_pack *packages);
void				create_packages(t_lem *l);
t_pack        		*get_best_package(t_pack *pack);

/*
**	 Ants functions
*/
void				set_ants_on_ways(t_pack *pack);
void				prepare_ants(t_lem *l);
void				create_ants(int quantity, t_pack *pack);
void				move_ants(t_lem *l);

/*
**	 Print functions
*/

void			print_ant_step(t_ant *ant);
void			print_ants(t_ant *ant);
void			print_way(int ants, float cap, t_room *way);
void			print_ways(int *ants, float *cap, t_room **ways);
void			print_packages(t_pack *packages);

#endif
