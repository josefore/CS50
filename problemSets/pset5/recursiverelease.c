/* Test program to understand building linked lists
 * This version:
 ** recursive function to free memory
 ** list is a main local variable */

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

// Function prototypes
void display_menu(void);
void release(node *lista);
node *head(node *list);
void see(node *lista);
void search(node *lista);
void supr(node **lista);

int main(void)
{
    node* list = NULL;;

    // Local variables
    int option = 0;

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
                list = head(list);
                break;

            // Delete
            case 2:
                supr(&list);
                break;

            // See full list
            case 3:
                see(list);
                break;

            // Search
            case 4:
                search(list);
                break;

            // Display menu again
            case 5:
                display_menu();
                break;
        }
    }
    while (option > 0 && option < 6);

    release(list); // Si no funciona podria ser porque esta variable deberia ser local

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

node *head(node *lista)
{
    printf("Add new element:\n\n");
    node *buf = malloc(sizeof(node));
    if (buf == NULL)
    {
        printf("Error 1: Pointer to NULL.\n");
        release(lista);
        return NULL;
    }

    buf -> a = get_int("a: ");
    buf -> b = get_int("b: ");
    buf -> next = lista;
    return buf;
}

void supr(node **list)
{
    if (*list == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    int s = get_int("What would you like to delete? ");
    for (node *tmp = *list; tmp != NULL; tmp = tmp -> next)
    {
       if (tmp -> a == s || tmp -> b == s)
       {
           printf("a: %i\n", tmp -> a);
           printf("b: %i\n", tmp -> b);
       }
    }
    printf("\n");

    node *past = *list;
    s = get_int("Type in the value of 'a' you would like to delete: ");
    for (node *tmp = *list; tmp != NULL; tmp = tmp -> next)
    {
        if (tmp -> a == s)
        {
            printf("Are you sure you want to delete the following elemnt? y/n\n");
            printf("a: %i\n", tmp -> a);
            printf("b: %i\n", tmp -> b);

            char *opt = get_string("Option: ");
            if (opt[0] == 'y')
            {
                if (tmp == *list)
                { *list = tmp -> next; }
                else
                { past -> next = tmp -> next; }
                free(tmp);
                printf("Element released\n");
                return;
            }
        }

        past = tmp;
    }
    printf("Not found.\n");
}

void release(node *lista)
{
    if (lista == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    release(lista -> next);
    free(lista);
}

void see(node *lista)
{
    if (lista == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    for (node *tmp = lista; tmp != NULL; tmp = tmp -> next)
    {
        printf("a: %i\n", tmp -> a);
        printf("b: %i\n", tmp -> b);
        printf("\n");
    }
}

void search(node *lista)
{
    if (lista == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    int s = get_int("What would you like to search? ");
    for (node *tmp = lista; tmp != NULL; tmp = tmp -> next)
    {
       if (tmp -> a == s || tmp -> b == s)
       {
           printf("a: %i\n", tmp -> a);
           printf("b: %i\n", tmp -> b);
       }
    }
    printf("\n");
}