#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 200

typedef struct {
    int arr[MAX_SIZE];  
    int top;        
} Stack;

// Function to initialize stack
void initialize(Stack *stack) {
    if (stack == NULL) return; // check for NULL pointer
    stack->top = -1;  
}

// Function to check if stack is empty
bool isEmpty(Stack *stack) {
    if (stack == NULL) return true; // NULL is empty
    return stack->top == -1;  
}

// Function to check if stack is full
bool isFull(Stack *stack) {
    if (stack == NULL) return false; // NULL stack cannot be full
    return stack->top >= MAX_SIZE - 1;  
}

// Push an element to top of stack
void push(Stack *stack, int value) {
    if (stack == NULL) { 
        printf("Error: Stack pointer is NULL\n");
        return;
    }

    if (isFull(stack)) { // if it surpasses max amount of values
        printf("Stack Overflow\n");
        return;
    }

    stack->arr[++stack->top] = value; 
}

// Pop an element from the stack
bool pop(Stack *stack, int *result) {
    if (stack == NULL) {
        printf("Error: Stack pointer is NULL\n");
        return false;
    }

    if (isEmpty(stack)) {
        printf("Stack Underflow\n"); // no values to pop
        return false;
    }

    *result = stack->arr[stack->top]; // store popped value 
    stack->top--;
    return true;
}

// Show top element of the stack
bool peek(Stack *stack, int *result) {
    if (stack == NULL) {
        printf("Error: Stack pointer is NULL\n");
        return false;
    }

    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return false;
    }

    *result = stack->arr[stack->top];
    return true;
}

int main() {
    Stack stack;
    initialize(&stack);

    int choice, value;

    while (true) {
        printf("\n=== Stack Menu ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("Enter value: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                //  print if pop was successful
                if (pop(&stack, &value)) {
                    printf("Popped: %d\n", value);
                }
                break;

            case 3:
                //  print if peek was successful
                if (peek(&stack, &value)) {
                    printf("Top element: %d\n", value);
                }
                break;

            case 4:
                if (isEmpty(&stack)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Your stack: ");
                    for (int i = 0; i <= stack.top; i++) {
                        printf("%d ", stack.arr[i]);
                    }
                    printf("\n");
                }
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}