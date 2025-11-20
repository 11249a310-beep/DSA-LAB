#include <stdio.h>
#include <stdlib.h>

// Define Node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Node creation
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at top
void insertAtTop(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Insert at end
void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at middle
void insertAtMiddle(Node** head, int value, int position) {
    if (*head == NULL || position <= 1) {
        insertAtTop(head, value);
        return;
    }
    Node* temp = *head;
    int count = 1;
    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    Node* newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete at top
void deleteAtTop(Node** head) {
    if (*head == NULL)
        return;
    Node* temp = *head;
    *head = temp->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}

// Delete at end
void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev)
        temp->prev->next = NULL;
    else
        *head = NULL;
    free(temp);
}

// Delete at middle
void deleteAtMiddle(Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position or stack is empty\n");
        return;
    }
    if (position == 1) {
        deleteAtTop(head);
        return;
    }
    Node* temp = *head;
    int count = 1;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
        return;

    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
}

// Search for value
int search(Node* head, int value) {
    int pos = 1;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

// Traverse the list
void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* stack = NULL;

    insertAtTop(&stack, 10);
    insertAtTop(&stack, 20);
    insertAtTop(&stack, 15);
    insertAtMiddle(&stack, 5, 2);

    traverse(stack);

    printf("Position of 15: %d\n", search(stack, 15));
    printf("Position of 100: %d\n", search(stack, 100));

    deleteAtTop(&stack);
    traverse(stack);

    deleteAtMiddle(&stack, 2);
    traverse(stack);

    deleteAtEnd(&stack);
    traverse(stack);

    return 0;
}
