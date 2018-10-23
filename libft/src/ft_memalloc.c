/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:16:25 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:24:46 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void		*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	t;

	t = 0;
	mem = NULL;
	mem = (void*)malloc(size);
	if (mem)
	{
		while (t < size)
		{
			*((char*)mem + t) = 0;
			t++;
		}
	}
	return (mem);
}
