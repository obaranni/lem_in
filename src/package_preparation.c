/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   package_preparation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:10:22 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 15:10:40 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void			prepare_packages(t_lem *l)
{
	create_packages(l);
	if (l->flags.packages && l->flags.bad_cases)
		print_packages(l, l->packages);
	remove_same_packages(l);
	set_packages_capacity(l->packages);
	set_ants_quantity_on_ways(l, l->packages);
	if (l->flags.packages)
		print_packages(l, l->packages);
}
