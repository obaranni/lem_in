/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:07:55 by obaranni          #+#    #+#             */
/*   Updated: 2016/12/05 16:50:14 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		*((unsigned char*)dest + i) = *((unsigned char*)src + i);
		if (*((unsigned char*)src + i) == (unsigned char)c)
			return ((char*)dest + i + 1);
		n--;
		i++;
	}
	return (NULL);
}
