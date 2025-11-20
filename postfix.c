#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;  // Push: increment first
}

int pop() {
    return stack[top--]; // Pop: decrement after returning value
}

int evaluate_postfix(char postfix[]) {
    int i, a, b, result;
    char c;
    for (i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];
        if (isdigit(c)) { // Correct function, no space
            push(c - '0'); // Convert char digit to integer
        }
        else {
            b = pop();
            a = pop();
            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = pow(a, b); break; // Use pow for exponentiation
                default: printf("Invalid operator: %c\n", c); return -1;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    printf("Evaluation result: %d\n", evaluate_postfix(postfix));
    return 0;
}