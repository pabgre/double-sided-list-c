// C program for generic linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef void (*fptr)(void *);

/* A linked list s_listNode */
typedef struct s_listNode
{
    // Any data type can be stored in this s_listNode
    void  *data;
  
    struct s_listNode *next;
    struct s_listNode *prev;
}               t_listNode;

typedef struct s_list{
  t_listNode* head;
  t_listNode* tail;
  int len;
  size_t data_size;

  fptr printFn;
}             t_list;

typedef enum {PUSH, APPEND} e_list_action;


void list_empty(t_list *lst, size_t data_size, fptr printFn){
  lst->head = NULL;
  lst->tail = NULL;

  lst->len = 0;
  lst->data_size = data_size;
  lst->printFn = printFn;
}
  


void list_add(t_list* lst, void *new_data, e_list_action action)
{
    // Allocate memory for s_listNode
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
  
    // Copy contents of new_data to newly allocated memory.
    // Assumption: char takes 1 byte.
    size_t i;
    for (i=0; i< lst->data_size; i++)
        *(char *)(new_listNode->data + i) = *(char *)(new_data + i);
  
    // Change head pointer as new s_listNode is added at the beginning
    if (action == PUSH)
      (lst->head)  = new_listNode;
    else
      (lst->tail)  = new_listNode;
    
    lst->len++;
}
void push(t_list* lst, void *new_data)
{
    list_add(lst, new_data, PUSH);
}

void append(t_list* lst, void *new_data)
{
    list_add(lst, new_data, APPEND);
}


void* list_get(t_list* lst, int i){
  t_listNode *node;

  node = lst->head;
    while (i > 0)
    {
        
        node = node->next;
        i--;
    }
  return (node->data);
}
  
/* Function to print s_listNodes in a given linked list. fpitr is used
   to access the function to be used for printing current s_listNode data.
   Note that different data types need different specifier in printf() */
void printList(t_list *lst)
{
  int i;
  t_listNode *node;

  i = lst->len;
  node = lst->head;
    while (i> 0)
    {
      lst->printFn(node->data);
        node = node->next;
        i--;
    }
}
  
// Function to print an integer
void printInt(void *n)
{
   printf(" %d", *(int *)n);
}
  
// Function to print a float
void printFloat(void *f)
{
   printf(" %f", *(float *)f);
}

void printString(void *str)
{
   printf(" %s", *(char **)str);
}

void printLstString(void *lst){
  printList(lst);
}
  
/* Driver program to test above function */
int main()
{
    t_list lst;
    
    // Create and print an int linked list
    unsigned int_size = sizeof(int);
    list_empty(&lst, int_size, printInt);
    int arr[] = {10, 20, 30, 40, 50}, i;
    for (i=4; i>=0; i--)
       push(&lst, &arr[i]);
    printf("Created integer linked list is \n");
    printList(&lst);

    int e = *(int*)list_get(&lst, 2);

    printf("\ngot: %d",e);
  
    // Create and print a float linked list
    unsigned float_size = sizeof(float);
    list_empty(&lst, float_size, printFloat);
    float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5};
    for (i=4; i>=0; i--)
       push(&lst, &arr2[i]);
    printf("\n\nCreated float linked list is \n");
    printList(&lst);

    float f = *(float*)list_get(&lst, 2);

    printf("\ngot: %f",f);


     // Create and print a float linked list
    list_empty(&lst, sizeof(char*), printString);
    char* arr3[] = {"hola", "buenas", "tardes", ":)", "chao\n"};
    for (i=4; i>=0; i--)
       push(&lst, &arr3[i]);
    arr3[0] = "que miras?";
    printf("\n\nCreated string linked list is \n");
    printList(&lst);

    char* g = *(char**)list_get(&lst, 2);

    printf("\ngot: %s",g);

    t_list lst2;
    list_empty(&lst2, sizeof(t_list), printLstString);
    for (i=4; i>=0; i--)
      push(&lst2, &lst);
    printf("\n\nCreated list of string linked list is \n");
    printList(&lst2);




	  system("leaks a.out");
    return 0;
}