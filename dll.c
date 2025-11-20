#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if (!newnode) return;

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

// Insert at end
void insertAtEnd(int value) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    if (!newnode) return;

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    if (temp->next == NULL) {   // Only one node
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Display forward
void displayForward() {
    struct Node *temp = head;
    printf("Forward: ");

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display reverse
void displayReverse() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("Reverse: List is empty\n");
        return;
    }

    // Go to the last node
    while (temp->next != NULL)
        temp = temp->next;

    printf("Reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Example main function to test all operations
int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtEnd(30);
    insertAtEnd(40);
    displayForward();  // Output: Forward: 20 10 30 40 
    displayReverse();  // Output: Reverse: 40 30 10 20

    deleteFromBeginning();
    displayForward();  // Output: Forward: 10 30 40 
    deleteFromEnd();
    displayForward();  // Output: Forward: 10 30 
    displayReverse();  // Output: Reverse: 30 10

    return 0;
}
