/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:47:44 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:33:53 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		n;

	n = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * n + 1);
	if (s2 == NULL)
		return (0);
	ft_strcpy(s2, s1);
	return (s2);
}
