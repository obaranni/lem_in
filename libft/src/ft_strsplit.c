/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:28:24 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:39:46 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int		ft_words_numb(char const *s, char c)
{
	int			flag;
	int			numbw;

	numbw = 0;
	flag = 0;
	while (*s != '\0')
	{
		if (*s == c && flag == 1)
			flag = 0;
		if (*s != c && flag == 0)
		{
			numbw++;
			flag = 1;
		}
		s++;
	}
	return (numbw);
}

static size_t	ft_len(const char *s, char c)
{
	size_t		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**p;
	int			numbw;
	int			i;

	if (!s)
		return (NULL);
	numbw = ft_words_numb(s, c);
	if (!(p = (char**)malloc(sizeof(char*) * numbw + 1)))
		return (NULL);
	i = 0;
	while (numbw--)
	{
		while (*s == c && *s != '\0')
			s++;
		if ((p[i] = ft_strsub(s, 0, ft_len(s, c))) == NULL)
			return (NULL);
		s = s + ft_len(s, c);
		i++;
	}
	p[i] = NULL;
	return (p);
}
