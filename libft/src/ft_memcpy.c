/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:50:19 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:25:47 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *out, const void *in, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char*)out + i) = *((unsigned char*)in + i);
		i++;
	}
	return (out);
}
