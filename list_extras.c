#include "list.h"

int list_get_int(t_list *lst, int i, bool remove){
    return(*(int *)list_get(lst, i, remove));
}
char list_get_char(t_list *lst, int i, bool remove){
    return(*(char *)list_get(lst, i, remove));
}
float list_get_float(t_list *lst, int i, bool remove)
{
	float	f;
	void	*p;

	p = list_get(lst, i, remove);
	f = *(float *)p;
	if (remove)
		free(p);
	return (f);
}
char* list_get_str(t_list *lst, int i, bool remove)
{
	void	*p;
	char	*str;

	p = list_get(lst, i, remove);
	str = *(char **)p;
	if (remove)
		free(p);
	return (str);
}

t_list list_get_list(t_list *lst, int i, bool remove)
{
	void	*p;
	t_list	lst2;

	p = list_get(lst, i, remove);
	lst2 = *(t_list *)p;
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

void print_list(void *lst){
  list_print(lst);
}
