#include "../inc/lem_in.h"

void			prepare_packages(t_lem *l)
{
	create_packages(l);
	if (l->flags.print && l->flags.bad_cases)
		print_packages(l, l->packages);
	remove_same_packages(l);
	set_packages_capacity(l->packages);
	set_ants_quantity_on_ways(l, l->packages);
	if (l->flags.print)
		print_packages(l, l->packages);
}