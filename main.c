#include "list.h"
#include "list_extras.h"

int main()
{
    t_list lst;
    
    // Create and print an int linked list
    unsigned int_size = sizeof(int);
    list_empty(&lst, int_size, print_int);
    int arr[] = {10, 20, 30, 40, 50}, i;
    for (i=4; i>=0; i--)
       list_push(&lst, &arr[i]);
    printf("Created integer linked list is \n");
    list_print(&lst);

    int e = list_get_int(&lst, -6, false);

    printf("\ngot: %d",e);
  
    // Create and print a float linked list
    unsigned float_size = sizeof(float);
    list_empty(&lst, float_size, print_float);
    float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5};
    for (i=4; i>=0; i--)
       list_push(&lst, &arr2[i]);
    printf("\n\nCreated float linked list is \n");
    list_print(&lst);

    float f = list_get_float(&lst, -2, false);

    while(lst.len > 0)
        f = list_get_float(&lst, 0, true);



    printf("\ngot: %f",f);


     // Create and print a float linked list
    list_empty(&lst, sizeof(char*), print_string);
    char* arr3[] = {"hola", "buenas", "tardes", ":)", "chao"};
    for (i=4; i>=0; i--)
       list_push(&lst, &arr3[i]);
    arr3[0] = "que miras?";
    printf("\n\nCreated string linked list is \n");
    list_print(&lst);

    char* g = list_get_str(&lst, 2, true);

    printf("\ngot: %s",g);

    t_list lst2;
    list_empty(&lst2, sizeof(t_list), print_list);
    for (i=4; i>=0; i--)
      list_push(&lst2, &lst);
    printf("\n\nCreated list of string linked list is \n");
    list_print(&lst2);

    t_list l = list_get_list(&lst2, 2, false);

    printf("\ngot: ");
    list_print(&l);
	system("leaks a.out");
    return 0;
}