/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:09:53 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:35:34 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	j;
	int	dstlen;
	int	srclen;

	j = 0;
	i = ft_strlen(src);
	srclen = i;
	i = ft_strlen(dst);
	dstlen = i;
	if ((size_t)dstlen < size)
		size = (size - 1) - dstlen;
	else
		return ((size_t)srclen + size);
	while ((size_t)j < size && src[j] != '\0')
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return ((size_t)srclen + (size_t)dstlen);
}
