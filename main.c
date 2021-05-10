#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void free_string(void *data)
{
  free((char *)data);
}

void print_string(void *data){
  printf("%s", (char *)data);
}

void copy_string(void** element, void* str){
	*element = strdup(*(char **)str);
}


void print_int(void *data){
  printf("%d", (int)data);
}

void copy_int(void** element, void* nb){
	*(int *)element = *(int *)nb;
}



int main(){
	list lst;
	lst = list_new(sizeof(char*), free_string, print_string, copy_string);
	char* i = "hola";
	list_append(&lst, &i);
	i = "buenas";
	list_append(&lst, &i);
	i = "tardes";
	list_append(&lst, &i);
	list_push(&lst, &i);

	list_print(&lst);


 	list_get(&lst, 3, &i, FALSE);
	printf("%s", i);
	list_destroy(&lst);


lst = list_new(sizeof(int), NULL, print_int, copy_int);
	int j = 4;
	list_append(&lst, &j);
	j = 6;
	list_append(&lst, &j);
	j = 7;
	list_append(&lst, &j);
	list_push(&lst, &j);

	list_print(&lst);

	list_destroy(&lst);





	system("leaks a.out");


}
