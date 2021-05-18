/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 10:04:30 by fgata-va          #+#    #+#             */
/*   Updated: 2021/05/18 17:48:22 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_extras.h"

void	print_int(void *n)
{
	printf(" %d", *(int *)n);
}

void	print_float(void *f)
{
	printf(" %f", *(float *)f);
}

void	print_string(void *str)
{
	printf(" %s", *(char **)str);
}

void	print_list(void *lst)
{
	list_print(lst);
}
