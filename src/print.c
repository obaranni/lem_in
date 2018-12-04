#include "../inc/lem_in.h"

void			print_way(t_room *way)
{
	int 		id_printed;

	id_printed = 0;
	while (way)
	{
		if (!id_printed)
		{
			id_printed = 1;
			ft_putstr("way_id: ");
			ft_putnbr(way->way_id);
			ft_putstr(" | ");
		}
		if (way->next)
		{
			ft_putstr(way->name);
			ft_putstr(" -> ");
		}
		else
		{
			ft_putendl(way->name);
			id_printed = 0;
		}
		way = way->next;
	}
}

void			print_ways(t_room **ways)
{
	int 		i;

	i = 0;
	if (!ways)
		return;
	ft_putendl("Ways:");
	while (ways[i])
	{
		print_way(ways[i]);
		i++;
	}
	ft_putchar('\n');
	ft_putstr("Ways counter: ");
	ft_putnbr(i);
	ft_putchar('\n');
}

void			print_packages(t_pack *packages)
{
	t_pack		*tmp_p;
	int 		i;

	i = 0;
	tmp_p = packages;
	while (tmp_p)
	{
		ft_putstr("\n***** Package ");
		ft_putnbr(i + 1);
		ft_putendl(" *****");
		print_ways(tmp_p->parallel_ways);
		tmp_p = tmp_p->next;
		i++;
		ft_putendl("********************\n");
	}
}