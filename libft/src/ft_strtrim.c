/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:11:15 by obaranni          #+#    #+#             */
/*   Updated: 2016/12/17 14:40:21 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*ft_oneb(char const *s, int i)
{
	char	*one;

	one = (char *)malloc(sizeof(char));
	one[0] = s[i];
	return (one);
}

static int	ft_and(char const *s)
{
	int		endnumb;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			endnumb = i;
		i++;
	}
	return (endnumb);
}

static int	ft_allocate(char const *s)
{
	int		i;
	int		begin;
	int		end;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	begin = i;
	end = ft_and(s);
	return (end - begin);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_oneb(s, i));
	new = (char *)malloc(sizeof(char) * ft_allocate(s) + 2);
	if (new == NULL)
		return (NULL);
	j = 0;
	while ((s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\0') ||
			i < ft_and(s))
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
