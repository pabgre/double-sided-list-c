/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:48:40 by psan-gre          #+#    #+#             */
/*   Updated: 2021/05/18 17:47:55 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	cpy_data(t_dlist *lst, t_listNode *node, void *data)
{
	size_t	i;

	i = 0;
	while (i < lst->data_size)
	{
		*(char *)(node->data + i) = *(char *)(data + i);
		i++;
	}
}

void	node_destroy(t_dlist *lst, t_listNode *node)
{
	if (lst->len > 1)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		if (lst->head == node)
			lst->head = node->next;
		if (lst->tail == node)
			lst->head = node->prev;
	}
	else
	{
		lst->head = NULL;
		lst->tail = NULL;
	}
	lst->len--;
	free(node);
}

t_listNode	*select_node(t_dlist *lst, int i)
{
	t_listNode	*node;

	if (lst->len > 0)
		node = lst->head;
	if (i < 0)
	{
		i = lst->len - i % lst->len;
		while (i > 0)
		{
			node = node->prev;
			i--;
		}
	}
	else
	{
		i = i % lst->len;
		while (i > 0)
		{
			node = node->next;
			i--;
		}
	}
	return (node);
}

void	list_push(t_dlist *lst, void *new_data)
{
	list_add(lst, new_data, true);
}

void	list_append(t_dlist *lst, void *new_data)
{
	list_add(lst, new_data, false);
}
