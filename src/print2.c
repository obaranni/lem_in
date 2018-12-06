/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:13:35 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:14:13 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void			print_usage(void)
{
	ft_putstr(L_RED);
	ft_putstr_fd("Usage: ./lem-in -[pabviwfc] < map\n", 2);
	ft_putstr(RESET);
}

void			print_error(t_err *error)
{
	if (error->lvl == 1)
		ft_putstr("A warning occurred on the ");
	else
		ft_putstr("An error occurred on the ");
	ft_putnbr(error->line);
	ft_putendl(" line.");
	ft_putstr("Explanation message: ");
	ft_putendl(error->msg);
	ft_putchar('\n');
}

void			print_header(t_lem *l)
{
	if (l->flags.color)
		ft_putstr(L_GREEN);
	ft_putstr("Input sources: ");
	if (l->flags.fd->file)
		ft_putendl(l->flags.fd->file);
	else
		ft_putstr("manual");
	if (l->flags.color)
		ft_putstr(RESET);
	ft_putstr("\n");
}

void			print_footer(t_lem *l)
{
	if (l->flags.color)
		ft_putstr(L_GREEN);
	ft_putstr("\nend of: ");
	if (l->flags.fd->file)
		ft_putendl(l->flags.fd->file);
	else
		ft_putstr("manual");
	ft_putstr("\n\n");
	if (l->flags.color)
		ft_putstr(RESET);
}

void			print_ant_step(t_lem *l, t_ant *ant)
{
	if (l->flags.color)
		ft_putstr(GREEN);
	ft_putchar('L');
	ft_putnbr(ant->id + 1);
	ft_putchar('-');
	ft_putstr(ant->way->name);
	ft_putchar(' ');
	if (l->flags.color)
		ft_putstr(RESET);
}
