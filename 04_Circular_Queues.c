#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Circular Queue Overflow!\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % MAX;
        queue[rear] = value;

        printf("%d is inserted into the queue.\n", value);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue Underflow!\n");
    }
    else
    {
        printf("Deleted element is: %d\n", queue[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is Empty!\n");
    }
    else
    {
        printf("Circular Queue elements are:\n");

        i = front;

        while (1)
        {
            printf("%d\n", queue[i]);

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- CIRCULAR QUEUE OPERATIONS ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

