/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:21:03 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 13:22:41 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int			ft_iswsps(const char *str)
{
	size_t x;

	x = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			x++;
		str++;
	}
	return (x == ft_strlen(str));
}

static int			c_words(const char *s, char c, int code)
{
	int				i;
	int				flag;
	int				count_words;

	flag = 0;
	count_words = 0;
	if (!s || (i = 0))
		return (0);
	while (s[i])
	{
		while (s[i] && (s[i] == c ||
						(code == 1 && (s[i] == ' ' || s[i] == '\t'))))
		{
			i++;
			flag = 0;
		}
		while (s[i] && ((s[i] != c && !code) ||
			(code == 1 && (s[i] != ' ' && s[i] != '\t' && s[i] != c))))
		{
			i++;
			if (flag == 0 && (flag = 1))
				count_words++;
		}
	}
	return (count_words);
}

static size_t		len_split(const char **string, char c, int code)
{
	char			*wip;
	int				i;
	size_t			ret;

	if (!(*string))
		return (0);
	wip = (char *)*string;
	i = 0;
	ret = 0;
	while (wip[i] && (wip[i] == c ||
		(code == 1 && (wip[i] == ' ' || wip[i] == '\t'))))
		i++;
	while (wip[i] && ((wip[i] != c && !code) ||
		(code == 1 && (wip[i] != ' ' && wip[i] != '\t' && wip[i] != c))))
	{
		ret++;
		i++;
	}
	return (ret);
}

static char			*get_word(const char **string, char c, int code)
{
	char			*ret;
	int				i;
	int				temp;

	i = 0;
	if (!(temp = len_split(string, c, code)))
		return (NULL);
	ret = ft_strnew(temp);
	while (**string && (**string == c ||
		(code == 1 && (**string == ' ' || **string == '\t'))))
		(*string)++;
	while (**string && ((**string != c && !code) ||
		(code == 1 && (**string != ' ' && **string != '\t' && **string != c))))
	{
		ret[i++] = **string;
		(*string)++;
	}
	return (ret);
}

char				**ft_strsplit(const char *string, char c, int code)
{
	char			**dest;
	int				numb_wrds;
	int				counter;

	if (!string || ft_iswsps(string) || !(numb_wrds = c_words(string, c, code)))
		return (NULL);
	counter = 0;
	dest = (char **)malloc(sizeof(char *) * (numb_wrds + 1));
	while (numb_wrds--)
		dest[counter++] = get_word(&string, c, code);
	dest[counter] = NULL;
	return (dest);
}
