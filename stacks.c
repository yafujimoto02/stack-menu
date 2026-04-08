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
    stack->top = -1;  
}

// Function to check if stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;  
}

// Function to check if stack is full
bool isFull(Stack *stack) {
    return stack->top >= MAX_SIZE - 1;  
}

// Push an element to top of stack
void push(Stack *stack, int value) {
    if (isFull(stack)) { // if it surpasses max amount of values
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value; 
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n"); //no values
        return -1;
    }

    int popped = stack->arr[stack->top];
    stack->top--;
    return popped;
}

// Show top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
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
                pop(&stack);
                break;

            case 3:
                printf("Top element: %d\n", peek(&stack));
                break;

            case 4:
                if (isEmpty(&stack)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Your stacks: ");
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