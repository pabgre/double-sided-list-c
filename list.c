#include "list.h"


void list_empty(t_list *lst, size_t data_size, fptr print_fn){
  lst->head = NULL;
  lst->tail = NULL;

  lst->len = 0;
  lst->data_size = data_size;
  lst->print_fn = print_fn;
}
  


void list_add(t_list* lst, void *new_data, bool push)
{
    t_listNode* new_listNode = (t_listNode*)malloc(sizeof(t_listNode));
  
    new_listNode->data  = malloc(lst->data_size);

    if(lst->head){
      lst->head->prev = new_listNode;
      new_listNode->next = (lst->head);
    }else{
      new_listNode->next = new_listNode;
      lst->head= new_listNode;
    }
    if(lst->tail){
      lst->tail->next = new_listNode;
      new_listNode->prev = (lst->tail);
    }else{
      new_listNode->prev = new_listNode;
      lst->tail = new_listNode;
    }

    size_t i;
    i = 0;
    while (i< lst->data_size){
        *(char *)(new_listNode->data + i) = *(char *)(new_data + i);
        i++;
      }
  
    if (push)
      (lst->head)  = new_listNode;
    else
      (lst->tail)  = new_listNode;
    
    lst->len++;
}
void list_push(t_list* lst, void *new_data)
{
    list_add(lst, new_data, true);
}

void list_append(t_list* lst, void *new_data)
{
    list_add(lst, new_data, false);
}

void* list_get(t_list* lst, int i, bool remove){
  t_listNode *node;
  void *out;

  out = NULL;
  if (lst->len > 0){
    node = lst->head;
    if (i < 0){
      i =lst->len - i % lst->len;
      while (i > 0)
        {
            node = node->prev;
            i--;
        }

    }else{
        i = i % lst->len;

        while (i > 0)
        {
            node = node->next;
            i--;
        }
    }

    out = node->data;
    if(remove && lst->len > 0){
      if(lst->len > 1){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        if(lst->head == node){
          lst->head = node->next;
        }
        if(lst->tail == node){
          lst->head = node->prev;
        }
      }else{
        lst->head = NULL;
        lst->tail = NULL;
      }
      lst->len--;
      free(node);
    }
  }
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
  
