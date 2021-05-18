/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:04:38 by psan-gre          #+#    #+#             */
/*   Updated: 2021/05/18 17:42:49 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int list_get_int(t_dlist *lst, int i, bool remove)
{
	return(*(int *)list_get(lst, i, remove));
}
char list_get_char(t_dlist *lst, int i, bool remove)
{
	return(*(char *)list_get(lst, i, remove));
}
float list_get_float(t_dlist *lst, int i, bool remove)
{
	float	f;
	void	*p;

	p = list_get(lst, i, remove);
	f = *(float *)p;
	if (remove)
		free(p);
	return (f);
}
char* list_get_str(t_dlist *lst, int i, bool remove)
{
	void	*p;
	char	*str;

	p = list_get(lst, i, remove);
	str = *(char **)p;
	if (remove)
		free(p);
	return (str);
}

t_dlist list_get_list(t_dlist *lst, int i, bool remove)
{
	void	*p;
	t_dlist	lst2;

	p = list_get(lst, i, remove);
	lst2 = *(t_dlist *)p;
	if (remove)
	{
		list_destroy(p);
		free(p);
	}
	return (lst2);
}

void print_int(void *n)
{
	printf(" %d", *(int *)n);
}

void print_float(void *f)
{
	printf(" %f", *(float *)f);
}

void print_string(void *str)
{
	printf(" %s", *(char **)str);
}

void print_list(void *lst)
{
	list_print(lst);
}
