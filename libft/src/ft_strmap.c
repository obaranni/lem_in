/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:33:12 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:36:00 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	i;
	int		len;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	new = NULL;
	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new)
	{
		while (s[i] != '\0')
		{
			new[i] = f(s[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
