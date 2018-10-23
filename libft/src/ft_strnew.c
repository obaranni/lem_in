/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:47:23 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:37:59 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strnew(size_t size)
{
	char	*nstr;

	nstr = NULL;
	nstr = (char *)malloc(sizeof(char) * size + 1);
	if (nstr)
	{
		nstr[size] = '\0';
		while (size != 0)
		{
			size--;
			nstr[size] = 0;
		}
	}
	return (nstr);
}
