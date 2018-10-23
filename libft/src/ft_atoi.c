/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:56:06 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:07:42 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int			ft_tonumb(const char *str, int i, int flag, int end)
{
	unsigned int	sum;
	unsigned int	prod;

	prod = 1;
	sum = 0;
	while (end >= i)
	{
		sum = sum + ((str[end] - 48) * prod);
		prod = prod * 10;
		end--;
	}
	if (flag == 1)
		return ((int)sum * -1);
	return ((int)sum);
}

int					ft_atoi(const char *str)
{
	size_t			i;
	size_t			end;
	int				flag;

	flag = 0;
	i = 0;
	if (*str == 0 || str == 0)
		return (0);
	while (str[i] && (str[i] == '\r' || str[i] == '\v' ||
		str[i] == '\f' || str[i] == '\n' || str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '-')
	{
		flag = 1;
		i++;
	}
	if (str[i] == '+' && !flag)
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	end = i;
	while (str[end] >= '0' && str[end] <= '9')
		end++;
	return (ft_tonumb(str, i, flag, end - 1));
}
