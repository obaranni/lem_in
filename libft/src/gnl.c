/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lgnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:41:18 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/20 10:41:30 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char			*append_char(char **s, char c)
{
	char			*temp;
	size_t			len;

	if (!*s)
	{
		temp = ft_memalloc(2);
		temp[0] = c;
		temp[1] = '\n';
		return (temp);
	}
	len = ft_strlen(*s);
	temp = ft_memalloc(len + 2);
	ft_strcpy(temp, *s);
	temp[len] = c;
	temp[len + 1] = '\n';
	free(*s);
	*s = NULL;
	return (temp);
}

int					lgnl(int fd, char **line)
{
	char			buf;
	ssize_t 		len;

	len = 0;
	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	while ((len += read(fd, &buf, 1) > 0))
	{
		if (buf == '\0' || buf == '\n')
			break ;
		*line = append_char(line, buf);
	}
	return ((int)ft_strlen(*line));
}