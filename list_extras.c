#include "list.h"

int list_get_int(t_list *lst, int i, bool remove){
    return(*(int *)list_get(lst, i, remove));
}
char list_get_char(t_list *lst, int i, bool remove){
    return(*(char *)list_get(lst, i, remove));
}
float list_get_float(t_list *lst, int i, bool remove){
    return(*(float *)list_get(lst, i, remove));
}
char* list_get_str(t_list *lst, int i, bool remove){
    return(*(char **)list_get(lst, i, remove));
}
t_list list_get_list(t_list *lst, int i, bool remove){
    return(*(t_list *)list_get(lst, i, remove));
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