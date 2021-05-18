#include "list.h"
#include "list_extras.h"

/*
** Create and print an int linked list
*/

void	test_int(void)
{
	size_t	size;
	t_dlist	lst;
	int		i;
	int		arr[5];

	size = sizeof(int);
	list_empty(&lst, size, print_int, free);
	i = 0;
	while (i < 5)
	{
		arr[i] = (i + 1) * 10;
		i++;
	}
	while (i > 0)
	{
		list_push(&lst, &arr[i - 1]);
		i--;
	}
	printf("Created integer linked list: \n");
	list_print(&lst);
	i = list_get_int(&lst, -6, 0);
	printf("\ngot: %d", i);
	list_destroy(&lst);
}

/*
** Create and print a float linked list
*/

void	test_float(void)
{
	size_t	size;
	t_dlist	lst;
	int		i;
	float	arr[5];
	float	f;

	size = sizeof(float);
	list_empty(&lst, size, print_float, free);
	i = -1;
	while (i++ < 5)
		arr[i] = ((i + 1) * 10) + ((float)(i + 1) / 10);
	while (i > 0)
	{
		list_push(&lst, &arr[i - 1]);
		i--;
	}
	printf("\n\nCreated float linked list: \n");
	list_print(&lst);
	f = list_get_float(&lst, -2, 0);
	printf("\nlist_get_float(&lst, -2, false): %f", f);
	while (lst.head)
		f = list_get_float(&lst, 0, 1);
	printf("\ngot: %f", f);
}

/*
** Create and print a string linked list
*/

void	test_str(t_dlist *lst)
{
	int		i;
	char	*arr[5];
	char	*g;

	list_empty(lst, sizeof(char *), print_string, free);
	arr[0] = "hola";
	arr[1] = "buenas";
	arr[2] = "tardes";
	arr[3] = ":)";
	arr[4] = "chao";
	i = 5;
	while (i > 0)
	{
		list_push(lst, &arr[i - 1]);
		i--;
	}
	arr[0] = "que miras?";
	printf("\n\nCreated string linked list: \n");
	list_print(lst);
	g = list_get_str(lst, 2, 1);
	printf("\ngot: %s", g);
}

/*
** Create and print a list of lists
*/

void	test_lst(t_dlist *lst)
{
	t_dlist	lst2;
	t_dlist	l;
	int		i;

	list_empty(&lst2, sizeof(t_dlist), print_list, free);
	i = 5;
	while (i > 0)
	{
		list_push(&lst2, lst);
		i--;
	}
	printf("\n\nCreated list of string linked list: \n");
	list_print(&lst2);
	l = list_get_list(&lst2, 2, 0);
	printf("\ngot: ");
	list_print(&l);
	printf("\n");
	list_destroy(&lst2);
}

int	main(void)
{
	t_dlist	list;

	test_int();
	test_float();
	test_str(&list);
	test_lst(&list);
	return (0);
}
