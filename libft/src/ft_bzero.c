/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:32:46 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:08:24 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_bzero(void *b, size_t length)
{
	size_t i;

	i = 0;
	while (i < length)
	{
		*(char*)(b + i) = 0;
		i++;
	}
}