// Test program to understand building linked lists

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Global variables
typedef struct link
{
    int a;
    int b;
    struct link* next;
}
node;
node* list;

// Function prototypes
void display_menu(void);
void release(void);
void add(void);
void see(void);
void search(void);

int main(void)
{
    // Local variables
    int option = 0;
    int A = 1;
    int B = 2;

    list = NULL;

    display_menu();

    do
    {
        // Prompt user for option
        do
        {
            option = get_int("Select option: ");
        }
        while (option < 1 || option > 6);

        switch (option)
        {
            // Add new element
            case 1:
                add();
                break;

            // Delete
            case 2:
                break;

            // See full list
            case 3:
                see();
                break;

            // Search
            case 4:
                search();
                break;

            // Display menu again
            case 5:
                display_menu();
                break;
        }
    }
    while (option > 0 && option < 6);

    release(); // Si no funciona podria ser porque esta variable deberia ser local

    printf("Goodbye.\n");
    return 0;
}

    // Display Menu
void display_menu(void)
{
    printf("- Menu -\n(Type in the option number):\n");
    printf("1 - Add new element\n2 - Delete\n");
    printf("3 - See full list\n4 - Search\n6 - Exit\n\n");
}

void add(void)
{
    printf("Add new element:\n\n");
    node *buf = malloc(sizeof(node));
    if (buf == NULL)
    {
        printf("Error 1: Pointer to NULL.\n");
        release();
    }

    buf -> a = get_int("a: ");
    buf -> b = get_int("b: ");
    buf -> next = list;
    list = buf;
}

void release(void)
{
    while (list != NULL)
    {
        node *tmp = list -> next;
        free(list);
        list = tmp;
    }

    return;
}

void see(void)
{
    for (node *tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        printf("a: %i\n", tmp -> a);
        printf("b: %i\n", tmp -> b);
        printf("\n");
    }
}

void search(void)
{
    int s = get_int("What would you like to search? ");
    for (node *tmp = list; tmp != NULL; tmp = tmp -> next)
    {
       if (tmp -> a == s || tmp -> b == s)
       {
           printf("a: %i\n", tmp -> a);
           printf("b: %i\n", tmp -> b);
       }
    }
    printf("\n");
}