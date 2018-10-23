/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:53:23 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:25:31 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i) != 0)
			return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
		i++;
	}
	return (0);
}
