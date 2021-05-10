#ifndef __LIST_H
#define __LIST_H

// a common function used to free malloc'd objects
typedef void (*freeFunction)(void *);

typedef void (*printFunction)(void *);

typedef void (*copyFunction)(void **, void *);

typedef enum { FALSE, TRUE } bool;

typedef struct _listNode {
  void *data;
  struct _listNode *next;
  struct _listNode *prev;
} listNode;

typedef struct {
  int logicalLength;
  int elementSize;
  listNode *head;
  listNode *tail;
  freeFunction freeFn;
  printFunction printFn;
	copyFunction copyFn;

} list;

list list_new(int elementSize, freeFunction freeFn, printFunction printFn, copyFunction copyFn);
void list_destroy(list *list);

void list_append(list *list, void *element);
void list_push(list *list, void *element);
int list_size(list *list);
void list_print(list *list);
void list_get(list *list, int index, void* element, bool removeFromList);

#endif
