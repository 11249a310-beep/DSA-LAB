#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
    printf("Inserted -> %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Deleted -> %d\n", queue[front]);
    front++;
}

void peek() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front element -> %d\n", queue[front]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    peek();
    display();

    enqueue(40);
    enqueue(50);
    display();

    return 0;
}
