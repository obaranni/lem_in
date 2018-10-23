/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:51:41 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:37:47 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	int		flag;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	flag = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < (size_t)n)
	{
		if (s1[i] == s2[i])
			flag = 0;
		else
			return (0);
		i++;
	}
	if ((s1[i] == '\0' && s2[i] == '\0') || i == (size_t)n)
		return (1);
	return (0);
}
