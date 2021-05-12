#include "list.h"

void	list_empty(t_list *lst, size_t data_size, fptr print_fn, del free_data)
{
	lst->head = NULL;
	lst->tail = NULL;
	lst->len = 0;
	lst->data_size = data_size;
	lst->print_fn = print_fn;
	lst->free_data = free_data;
}

void	cpy_data(t_list *lst, t_listNode *node, void *data)
{
	size_t	i;

	i = 0;
	while (i < lst->data_size)
	{
		*(char *)(node->data + i) = *(char *)(data + i);
		i++;
	}
}

void	list_add(t_list *lst, void *new_data, bool push)
{
	t_listNode	*new_listNode;

	new_listNode = (t_listNode *)malloc(sizeof(t_listNode));
	new_listNode->data = malloc(lst->data_size);
	if (lst->head && lst->tail)
	{
		lst->head->prev = new_listNode;
		new_listNode->next = (lst->head);
		lst->tail->next = new_listNode;
		new_listNode->prev = (lst->tail);
	}
	else
	{
		new_listNode->next = new_listNode;
		lst->head = new_listNode;
		new_listNode->prev = new_listNode;
		lst->tail = new_listNode;
	}
	cpy_data(lst, new_listNode, new_data);
	if (push)
		lst->head = new_listNode;
	else
		lst->tail = new_listNode;
	lst->len++;
}

void	list_push(t_list *lst, void *new_data)
{
	list_add(lst, new_data, true);
}

void	list_append(t_list *lst, void *new_data)
{
	list_add(lst, new_data, false);
}

void	node_destroy(t_list *lst, t_listNode *node)
{
	if(lst->len > 1)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		if(lst->head == node)
			lst->head = node->next;
		if(lst->tail == node)
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

void	list_destroy(t_list *lst)
{
	int			i;
	t_listNode	*node;
	t_listNode	*nxt;

	i = lst->len;
	node = lst->head;
	while (i > 0)
	{
		nxt = node->next;
		if (lst->free_data)
			lst->free_data(node->data);
		free(node);
		node = nxt;
		i--;
	}
	lst->head = NULL;
	lst->tail = NULL;
}

t_listNode	*select_node(t_list *lst, int i)
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

void	*list_get(t_list* lst, int index, bool remove)
{
	t_listNode	*node;
	void		*out;

	node = select_node(lst, index);
	out = node->data;
	if (remove && lst->len > 0)
		node_destroy(lst, node);
	return (out);
}

void list_print(t_list *lst)
{
	int i;
	t_listNode *node;

	i = lst->len;
	node = lst->head;
	printf("l(");
	while (i> 0)
	{
		lst->print_fn(node->data);
		node = node->next;
		if (i > 1)
			printf(", ");
		i--;
	}
	printf(")");
}
