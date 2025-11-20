#include <stdio.h>
#define Max 100

// Function to traverse and print the array elements
void traverse(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to insert an element at a given position
void insert(int arr[], int *n, int pos, int value) {
    if (*n >= Max) {
        printf("Array is full.\n");
        return;
    }
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    (*n)++;
}

// Function to delete an element from a given position
void delete(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

// Function to search for a value in the array
int search(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value)
            return i; // Value found, return index
    }
    return -1; // Value not found
}

int main() {
    int arr[Max], n = 0;
    int ch, pos, value, idx;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                traverse(arr, n);
                break;
            case 2:
                printf("Enter position (0-based) and value: ");
                scanf("%d%d", &pos, &value);
                insert(arr, &n, pos, value);
                break;
            case 3:
                printf("Enter position (0-based): ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                idx = search(arr, n, value);
                if (idx >= 0)
                    printf("Found at position: %d\n", idx);
                else
                    printf("Not found\n");
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 5); // Exit condition when choice is 5

    return 0;
}
