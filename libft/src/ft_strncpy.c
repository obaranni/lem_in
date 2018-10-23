/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:27:48 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:37:34 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (i != len)
	{
		if (src[i] == '\0')
			flag = 1;
		else
			dst[i] = src[i];
		if (flag)
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
