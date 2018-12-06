#include "../inc/lem_in.h"

void			print_way_info(t_room *way, int ants, float cap)
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
}

void			print_way(t_lem *l, int ants, float cap, t_room *way)
{
	if (l->flags.info)
		print_way_info(way, ants, cap);
	if (l->flags.color)
		ft_putstr(YELLOW);
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
	if (l->flags.color)
		ft_putstr(MAGENTA);
}

void 			print_ways_info(t_lem *l, int i)
{
	if (l->flags.color)
		ft_putstr(YELLOW);
	ft_putstr("\nWays counter: ");
	if (l->flags.color)
		ft_putstr(MAGENTA);
	ft_putnbr(i);
	if (l->flags.color)
		ft_putstr(RESET);
	ft_putchar('\n');
}

void			print_ways(t_lem *l, int *ants, float *cap, t_room **ways)
{
	int 		i;

	i = 0;
	if (!ways)
		return;
	if (l->flags.color)
		ft_putstr(YELLOW);
	ft_putendl("Ways:");
	if (l->flags.color)
		ft_putstr(MAGENTA);
	while (ways[i])
	{
		if (cap)
			print_way(l, ants[i], cap[i], ways[i]);
		else
			print_way(l, 0, 0, ways[i]);
		i++;
	}
	print_ways_info(l, i);
}