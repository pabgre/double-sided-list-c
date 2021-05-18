/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 22:07:28 by psan-gre          #+#    #+#             */
/*   Updated: 2021/05/18 19:00:27 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef void (*t_fptr)(void *);

typedef void (*t_del)(void *);

typedef struct s_listNode
{
	void				*data;
	struct s_listNode	*next;
	struct s_listNode	*prev;
}						t_listNode;

typedef struct s_dlist
{
	t_listNode*	head;
	t_listNode*	tail;
	int			len;
	size_t		data_size;
	t_fptr		print_fn;
	t_del		free_data;
}				t_dlist;

void	list_empty(t_dlist *lst, size_t data_size, t_fptr print_fn, t_del free_data);
void	list_add(t_dlist* lst, void *new_data, bool push);
void	list_push(t_dlist* lst, void *new_data);
void	list_append(t_dlist* lst, void *new_data);
void	*list_get(t_dlist* lst, int i, bool remove);
void	list_print(t_dlist *lst);
void	list_destroy(t_dlist *lst);
void	cpy_data(t_dlist *lst, t_listNode *node, void *data);
t_listNode	*select_node(t_dlist *lst, int i);
void	node_destroy(t_dlist *lst, t_listNode *node);

#endif
