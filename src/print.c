#include "../inc/lem_in.h"

void			print_way(float cap, t_room *way)
{
	ft_putstr("id: ");
	ft_putnbr(way->way_id);
	if (cap)
	{
		ft_putstr(" | cap: ");
		ft_putnbr((int)cap);
//		printf("%f", cap); // TODO: printf forbidden
	}
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

void			print_ways(float *cap, t_room **ways)
{
	int 		i;

	i = 0;
	if (!ways)
		return;
	ft_putendl("Ways:");
	while (ways[i])
	{
		if (cap)
			print_way(cap[i], ways[i]);
		print_way(0, ways[i]);
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
		print_ways(tmp_p->ways_capacity, tmp_p->parallel_ways);
		ft_putstr("Power: ");
		ft_putnbr((int)tmp_p->package_capacity);
//		printf("%f", tmp_p->package_capacity); //TODO: printf forbidden
		ft_putendl("\n********************\n");
		tmp_p = tmp_p->next;
		i++;
	}
}