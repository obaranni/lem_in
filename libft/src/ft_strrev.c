/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:26:25 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:39:14 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strrev(char *s1)
{
	char	*s2;
	int		lenth;
	int		i;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	lenth = 0;
	while (s1[lenth] != '\0')
		lenth++;
	if ((s2 = (char*)malloc(sizeof(char) * lenth)) == NULL)
		return (NULL);
	while (lenth != 0)
	{
		s2[i] = s1[lenth - 1];
		i++;
		lenth--;
	}
	s2[i] = '\0';
	return (s2);
}
