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
# include <stdio.h>
# define NAME "obaranni.filler"
# define MAPCHARS ".xXoO"
# define MAP_F	(f->game.map.field)
# define MAP_X	(f->game.map.field_size.x)
# define MAP_Y	(f->game.map.field_size.y)
# define FIGCHARS ".*"
# define POSITOINS (f->game.figure.positions)
# define FIG		(f->game.figure)
# define FIGF_F	(f->game.figure.figure_full.field)
# define FIGF_X	(f->game.figure.figure_full.field_size.x)
# define FIGF_Y	(f->game.figure.figure_full.field_size.y)
# define FIGS_F	(f->game.figure.figure_short.field)
# define FIGS_X	(f->game.figure.figure_short.field_size.x)
# define FIGS_Y	(f->game.figure.figure_short.field_size.y)
# define PRIOR	(f->game.priorities)
# define ENEMY (-2)
# define MY (-1)
# define DOT (0)

typedef struct			s_cord
{
	int					x;
	int					y;
}						t_cord;

typedef struct			s_field
{
	char				**field;
	t_cord				field_size;
}						t_field;

typedef struct			s_fig_pos
{
	t_cord				pos;
	int					score;
	int					setted;
}						t_fig_pos;

typedef	struct			s_figure
{
	int					min_x;
	int					min_y;
	int					max_x;
	int					max_y;
	t_fig_pos			**positions;
	t_field				figure_full;
	t_field				figure_short;
	t_cord				offset;
}						t_figure;

typedef struct			s_game
{
	char				*my_player;
	char				*en_player;
	int					**priorities;
	t_field				map;
	t_figure			figure;
	t_cord				step_cord;
}						t_game;

typedef struct			s_filler
{
	int					graph_mode;
	int					log_mode;
	FILE				*file;
	char				**input;
	t_game				game;
}						t_filler;

void					free_input(t_filler *f);
void					free_all(t_filler *f);
int						get_next_line(const int fd, char **line);

void					logbook(t_filler *f, char *log_func);

void					cut_figure(t_filler *f);
void					fill_priorities_map(t_filler *f);
void					find_map(t_filler *f, int *i);
void					find_figure(t_filler *f, int *i);
int						parser(t_filler *f, int i);

int						visualize_game(t_filler *f);

int						responder(t_filler *f);

int						brute_force(t_filler *f);
void					set_priorities(t_filler *f);
int						analizer(t_filler *f);

void					validate_figure_part(t_filler *f, int *i);
int						validator(t_filler *f);

int						reader(t_filler *f, int fd);
#endif
