#include<stdio.h>;
#include<stdlib.h>;

struct node
{
    int data;
    struct node*next;
};

struct node*head=NULL;

void create()
{
    struct node*newnode,*temp;
    int choice=1;

    while(choice)
    {
         newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);
    }
}

void deleteFirst()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("First element deleted\n");
    }
}

void deleteSpecified()
{
    struct node *temp, *prev;
    int key;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found\n");
    }
    else
    {
        if (prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        free(temp);
        printf("Specified element deleted\n");
    }
}

void deleteLast()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Last element deleted\n");
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
        printf("Last element deleted\n");
    }
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;

        printf("Linked List: ");

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Create Linked List");
        printf("\n2. Delete First Element");
        printf("\n3. Delete Specified Element");
        printf("\n4. Delete Last Element");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                deleteSpecified();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
