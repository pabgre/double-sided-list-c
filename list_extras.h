#ifndef LIST_EXTRAS_H
#define LIST_EXTRAS_H
#include "list.h"

int list_get_int(t_dlist *lst, int i, bool remove);
char list_get_char(t_dlist *lst, int i, bool remove);
float list_get_float(t_dlist *lst, int i, bool remove);
char* list_get_str(t_dlist *lst, int i, bool remove);
t_dlist list_get_list(t_dlist *lst, int i, bool remove);
void print_int(void *n);
void print_float(void *f);
void print_string(void *str);
void print_list(void *lst);

#endif
