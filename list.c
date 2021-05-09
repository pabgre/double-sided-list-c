#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.h"

list list_new(int elementSize, freeFunction freeFn, printFunction printFn)
{
  list list;
  if(elementSize > 0){
    list.logicalLength = 0;
    list.elementSize = elementSize;
    list.head = list.tail = NULL;
    list.freeFn = freeFn;
    list.printFn = printFn;
  }else{
    list.logicalLength = 0;
    list.elementSize = 0;
    list.head = list.tail = NULL;
    list.freeFn = freeFn;
    list.printFn = printFn;
  }
  return(list);
}

void list_destroy(list *list)
{
  listNode *current;

  int index;

  index = list->logicalLength;
  while(index > 0) {
    current = list->head;
    list->head = current->next;

    if(list->freeFn) {
      list->freeFn(current->data);
    }

    free(current->data);
    free(current);
    index--;
  }
}

void list_append(list *list, void *element)
{
  listNode *node = malloc(sizeof(listNode));
  node->data = malloc(list->elementSize);
  node->next = NULL;
  node->prev = NULL;

  memcpy(node->data, element, list->elementSize);

  if(list->logicalLength == 0) {
    list->head = list->tail = node;
    node->next = node;
    node->prev = node;
  } else {
    list->tail->next = node;
    list->head->prev = node;
    node->next = list->head;
    node->prev = list->tail;
    list->tail = node;
  }

  list->logicalLength++;
}

void list_push(list *list, void *element)
{
  listNode *node = malloc(sizeof(listNode));
  node->data = malloc(list->elementSize);
  node->next = NULL;
  node->prev = NULL;

  memcpy(node->data, element, list->elementSize);

  if(list->logicalLength == 0) {
    list->head = list->tail = node;
    node->next = node;
    node->prev = node;
  } else {
    list->tail->next = node;
    list->head->prev = node;
    node->next = list->head;
    node->prev = list->tail;
    list->head = node;
  }

  list->logicalLength++;
}


void* list_get(list *list, int index, bool removeFromList)
{
  void* element;
  if(list->logicalLength > 0){
    listNode *node = list->head;

    if(index >= 0){
        while(index > 0){
          node = node->next;
          index--;
        }
    }else{
      while(index < 0){
        node = node->prev;
        index++;
      }
    }
    memcpy(element, node->data, list->elementSize);

    if(removeFromList) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      list->logicalLength--;

      free(node->data);
      free(node);
    }
  }else{
    //element=NULL;
  }
  return(element);
}


void list_print(list *list){
  int index;
  listNode *node;

  index = list->logicalLength;
  node = list->head;
  printf("l(");
  if (list->printFn != NULL){
    while(index > 0){
      list->printFn(node->data);
      node = node->next;
      if (index > 1){
        printf(", ");
      }
      index--;
    }
  }else{
    printf("No print function");
  }
  printf(")");

}

int list_size(list *list)
{
  return list->logicalLength;
}
