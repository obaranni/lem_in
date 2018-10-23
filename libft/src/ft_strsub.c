/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:10:24 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:40:40 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			j;

	if (s == NULL)
		return (NULL);
	sub = NULL;
	i = 0;
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (i < start)
		i++;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		sub[j] = s[i];
		j++;
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
