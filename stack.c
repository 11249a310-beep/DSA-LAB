#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Check if stack is full
int isFull() {
    return top == MAX - 1;
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// Push function
void push(int x) {
    if (isFull()) {
        printf("Stack overflow! Cannot push %d\n", x);
    } else {
        stack[++top] = x;
        printf("%d pushed into stack.\n", x);
    }
}

// Pop function
void pop() {
    if (isEmpty()) {
        printf("Stack underflow! Cannot pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Peek function
void peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

// Display stack contents
void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
