// Test program to understand building linked lists

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Global variables
typedef struct link
{
    int a;
    int b;
    struct link *next;
}
node;
node *list = NULL;

// Function prototypes
void display_menu(void);
void release(node *ptr);
void add(int *A, int *B);
void see(void);

int main(void)
{
    int A = 1;
    int B = 1;
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
                add(*A, *B);
                A++;
                B++;
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
                break;

            // Display menu again
            case 5:
                display_menu();
                break;
        }
    }
    while (option > 0 && option < 6);

    release(list);

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

void add(int *A, int *B)
{
    printf("Add new element:\n\n");
    node *buf = malloc(sizeof(node));
    if (buf == NULL)
    {
        printf("Error 1: Pointer to NULL.\n");
        release(list);
        return;
    }

    buf -> a = A;
    buf -> b = B;

    // If it's first element
    if (list == NULL)
    {   buf -> next = NULL;
        list = buf;
    }
    else
    {
        node *tmp = list;
        list = buf;
        list -> next = tmp;
    }
    return;
}

void release(node *ptr)
{
    if (ptr -> next == NULL)
    {
        free(ptr);
        return;
    }
    else
    {
        release(ptr -> next);
    }
}

void see(void)
{
    for (node *tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        printf("%i\n", tmp -> a);
        printf("%i\n", tmp -> b);
        printf("\n");
    }
}