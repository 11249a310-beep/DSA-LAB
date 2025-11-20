#include <stdio.h>
#include <stdlib.h>

// Define a node for the queue
struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Function to add an element to the queue
void enqueue(int value) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL) {   // Queue is empty
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Node added to queue: %d\n", value);
}

// Function to remove an element from the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *temp = front;
    printf("Node dequeued from queue: %d\n", front->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Function to display queue elements
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n----- Queue Menu -----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
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
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
