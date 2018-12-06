/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:54:47 by obaranni          #+#    #+#             */
/*   Updated: 2018/12/06 14:55:22 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

t_fd			*create_fd(void)
{
	t_fd		*temp;

	temp = (t_fd *)malloc(sizeof(t_fd));
	*temp = (t_fd){0, NULL, NULL};
	return (temp);
}

int				get_file(t_flags *flags, char **av)
{
	t_fd		*temp;

	flags->fd = create_fd();
	temp = flags->fd;
	while (*av)
	{
		temp->file = ft_strdup(*av);
		av++;
		if (*av)
		{
			temp->next = (t_fd *)malloc(sizeof(t_fd));
			*temp->next = (t_fd){0, NULL, NULL};
			temp = temp->next;
		}
		flags->files++;
	}
	if (flags->fd == NULL || flags->fd->file == NULL)
	{
		free(flags->fd);
		print_error_msg(flags, "There are no files!\n");
		exit(WRONG_ARGUMENTS);
	}
	return (0);
}
