#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void free_string(void *data)
{
  free(*(char **)data);
}

void print_string(void *data){
  printf("%s", *(char **)data);
}

int main(){
  list lst;
  lst = list_new(sizeof(char*), free_string, print_string);
  char* i = strdup("hola");
  list_append(&lst, &i);
  i = strdup("buenas");
  list_append(&lst, &i);
  i = strdup("tardes");
  list_append(&lst, &i);
  list_push(&lst, &i);
  list_print(&lst);


  i = *(char **)list_get(&lst, -30, FALSE);
  printf("%s", i);
}
