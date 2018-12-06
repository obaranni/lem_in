/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:14:22 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:15:21 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void			print_outline(t_lem *l)
{
	if (!l->flags.outline)
		return ;
	if (l->flags.color)
		ft_putstr(CYAN);
	ft_putchar('\n');
	ft_putstr(l->read->input);
	ft_putchar('\n');
	if (l->flags.color)
		ft_putstr(RESET);
}

void			print_package_info(t_lem *l, int total_steps)
{
	if (l->flags.color)
		ft_putstr(YELLOW);
	ft_putstr("Steps to perform: ");
	if (l->flags.color)
		ft_putstr(MAGENTA);
	ft_putnbr(total_steps);
}

void			print_packages(t_lem *l, t_pack *packages)
{
	t_pack		*tmp_p;
	int			i;

	i = 0;
	tmp_p = packages;
	while (tmp_p)
	{
		if (l->flags.color)
			ft_putstr(L_BLUE);
		ft_putstr("\n***** Package ");
		ft_putnbr(i + 1);
		ft_putendl(" *****");
		print_ways(l, tmp_p->ants_on_ways, tmp_p->ways_capacity,
				tmp_p->parallel_ways);
		print_package_info(l, tmp_p->total_steps);
		if (l->flags.color)
			ft_putstr(L_BLUE);
		ft_putendl("\n********************\n");
		if (l->flags.color)
			ft_putstr(RESET);
		tmp_p = tmp_p->next;
		i++;
	}
}

void			print_ants(t_lem *l, t_ant *ant)
{
	if (l->flags.color)
		ft_putstr(CYAN);
	while (ant)
	{
		ft_putstr("\n***** ANT ");
		ft_putnbr(ant->id + 1);
		ft_putendl(" *****");
		ft_putstr("Ant way_id: ");
		ft_putnbr(ant->way->way_id);
		ft_putendl("\n*****************\n");
		ant = ant->next;
	}
	if (l->flags.color)
		ft_putstr(RESET);
}
