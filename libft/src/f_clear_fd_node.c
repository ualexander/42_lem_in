/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_clear_fd_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:20:27 by vsanta            #+#    #+#             */
/*   Updated: 2019/08/25 19:20:57 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_get_next_line.h"

void	fd_lst_clear(void *content, size_t size)
{
	ft_lstdel(&((t_fd *)content)->buf, ft_lstclear);
	content = NULL;
	size = 0;
}

void	clear_fd_node(t_gnl *gnl)
{
	t_list	**tmp;
	t_list	*prev;

	tmp = &gnl->fd_lst;
	prev = NULL;
	while (*tmp)
	{
		if (((t_fd *)(*tmp)->content)->fd == gnl->fd)
		{
			ft_memdel(&(*tmp)->content);
			ft_memdel((void **)tmp);
			tmp = &prev;
			return ;
		}
		prev = *tmp;
		tmp = &(*tmp)->next;
	}
}
