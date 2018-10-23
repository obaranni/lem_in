/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:24:33 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:38:43 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c1;
	int		prev;

	c1 = (char)c;
	prev = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			prev = i;
		i++;
	}
	if (c1 == '\0')
		return ((char*)(s + i));
	else if (prev == -1)
		return ((char*)NULL);
	else
		return ((char*)(s + prev));
}
