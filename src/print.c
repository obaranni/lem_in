#include "../inc/lem_in.h"

void			print_way(t_lem *l, int ants, float cap, t_room *way)
{
	ft_putstr("id: ");
	ft_putnbr(way->way_id);
	if (cap > 0.0)
	{
		ft_putstr(" | cap percent: ");
		ft_putnbr_float(0, cap);
		ft_putchar('%');
	}
	ft_putstr(" | rooms: ");
	ft_putnbr(count_steps(way, 0));
	ft_putstr(" | ants: ");
	ft_putnbr(ants);
	ft_putstr(" | steps: ");
	if (ants)
		ft_putnbr(count_steps(way, ants));
	else
		ft_putchar('0');
	ft_putstr(" | ");
	while (way)
	{
		if (way->next)
		{
			ft_putstr(way->name);
			ft_putstr(" -> ");
		}
		else
			ft_putendl(way->name);
		way = way->next;
	}
}

void			print_ways(t_lem *l, int *ants, float *cap, t_room **ways)
{
	int 		i;

	i = 0;
	if (!ways)
		return;
	ft_putendl("Ways:");
	while (ways[i])
	{
		if (cap)
			print_way(l, ants[i], cap[i], ways[i]);
		else
			print_way(l, 0, 0, ways[i]);
		i++;
	}
	ft_putchar('\n');
	ft_putstr("Ways counter: ");
	ft_putnbr(i);
	ft_putchar('\n');
}

void			print_packages(t_lem *l, t_pack *packages)
{
	t_pack		*tmp_p;
	int 		i;

	i = 0;
	tmp_p = packages;
	if (l->flags.color)
		ft_putstr(MAGENTA);
	while (tmp_p)
	{
		ft_putstr("\n***** Package ");
		ft_putnbr(i + 1);
		ft_putendl(" *****");
		print_ways(l, tmp_p->ants_on_ways, tmp_p->ways_capacity, tmp_p->parallel_ways);
		ft_putstr("Steps to perform: ");
		ft_putnbr(tmp_p->total_steps);
		ft_putendl("\n********************\n");
		tmp_p = tmp_p->next;
		i++;
	}
	if (l->flags.color)
		ft_putstr(RESET);
}

void			print_ants(t_lem *l, t_ant *ant)
{
	while (ant)
	{
		ft_putstr("\n***** ANT ");
		ft_putnbr(ant->id + 1);
		ft_putendl(" *****");
		ft_putstr("Ant way: ");
		ft_putnbr(ant->way->way_id);
		ft_putendl("\n*****************\n");
		ant = ant->next;
	}
}

void				print_ant_step(t_lem *l, t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->id + 1);
	ft_putchar('-');
	ft_putstr(ant->way->name);
	ft_putchar(' ');
}