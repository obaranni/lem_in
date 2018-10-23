/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:20:12 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/02 15:24:19 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*con;
	size_t	i;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->next = NULL;
	if (content == NULL)
	{
		new->content_size = 0;
		new->content = NULL;
		return (new);
	}
	i = 0;
	if ((new->content = (void*)malloc(sizeof(content_size))) == NULL)
		return (NULL);
	new->content_size = content_size;
	con = new->content;
	while (i != content_size)
	{
		*((char*)con + i) = *((char*)content + i);
		i++;
	}
	new->next = NULL;
	return (new);
}
