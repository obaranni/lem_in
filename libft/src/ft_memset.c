/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:31:51 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:27:11 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *str, int nb, size_t len)
{
	size_t	i;
	char	*tm;

	tm = str;
	i = 0;
	while (i != len)
	{
		tm[i] = nb;
		i++;
	}
	return (str);
}
