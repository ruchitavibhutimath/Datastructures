#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};

struct node *head = NULL;

int count()
{
int c = 0;
struct node *temp = head;

while (temp != NULL)
{
    c++;
    temp = temp->next;
}

return c;

}

void insert_begin()
{
struct node *newnode;

newnode = (struct node *)malloc(sizeof(struct node));

printf("Enter data: ");
scanf("%d", &newnode->data);

newnode->next = head;
head = newnode;

}

void insert_end()
{
struct node *newnode, *temp;

newnode = (struct node *)malloc(sizeof(struct node));

printf("Enter data: ");
scanf("%d", &newnode->data);

newnode->next = NULL;

if (head == NULL)
{
    head = newnode;
}
else
{
    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

}

void insert_pos()
{
struct node *newnode, *temp;
int pos, i;

printf("Enter position: ");
scanf("%d", &pos);

if (pos < 1 || pos > count() + 1)
{
    printf("Invalid position!\n");
    return;
}

newnode = (struct node *)malloc(sizeof(struct node));

printf("Enter data: ");
scanf("%d", &newnode->data);

if (pos == 1)
{
    newnode->next = head;
    head = newnode;
}
else
{
    temp = head;

    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

}

void display()
{
struct node *temp = head;

if (head == NULL)
{
    printf("List is empty!\n");
    return;
}

printf("Linked List: ");

while (temp != NULL)
{
    printf("%d -> ", temp->data);
    temp = temp->next;
}

printf("NULL\n");

}

int main()
{
int choice;

while (1)
{
    printf("\n--- LINKED LIST MENU ---\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Display\n");
    printf("5. Count\n");
    printf("6. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            insert_begin();
            break;

        case 2:
            insert_end();
            break;

        case 3:
            insert_pos();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Total nodes = %d\n", count());
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice!\n");
    }
}

return 0;

}
