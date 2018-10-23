/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:19:08 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:38:28 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		io;
	int		j;
	size_t	tmp;

	tmp = len;
	io = 0;
	if (little[0] == '\0')
		return ((char*)&big[0]);
	while (big[io] != '\0' && len > 0)
	{
		j = 0;
		len = tmp;
		while (*((unsigned char*)big + j + io) == little[j] && little[j] != '\0'
				&& *((unsigned char*)big + j + io) != '\0' && len-- > 0)
			j++;
		if (little[j] == '\0')
			return ((char*)&big[io]);
		io++;
		tmp--;
	}
	return (NULL);
}
