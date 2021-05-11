#ifndef LIST_H
#define LIST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

typedef void (*fptr)(void *);

typedef struct s_listNode
{
    void  *data;
  
    struct s_listNode *next;
    struct s_listNode *prev;
}               t_listNode;

typedef struct s_list{
  t_listNode* head;
  t_listNode* tail;
  int len;
  size_t data_size;

  fptr print_fn;
}             t_list;

void list_empty(t_list *lst, size_t data_size, fptr print_fn);
void list_add(t_list* lst, void *new_data, bool push);
void list_push(t_list* lst, void *new_data);
void list_append(t_list* lst, void *new_data);
void* list_get(t_list* lst, int i, bool remove);
void list_print(t_list *lst);

#endif