/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:27:53 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:26:49 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src <= dst)
	{
		i = len;
		while (i != 0)
		{
			i--;
			*((unsigned char*)dst + i) = *((unsigned char*)src + i);
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char*)dst + i) = *((unsigned char*)src + i);
			i++;
		}
	}
	return (dst);
}
