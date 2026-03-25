#include <stdio.h>
#include <ctype.h>   // for isalnum()

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Priority of operators
int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main() {
    char exp[MAX];
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        
        // If operand, print it
        if (isalnum(exp[i])) {
            printf("%c", exp[i]);
        }
        // If '(', push it
        else if (exp[i] == '(') {
            push(exp[i]);
        }
        // If ')', pop until '('
        else if (exp[i] == ')') {
            while (stack[top] != '(') {
                printf("%c", pop());
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (top != -1 && priority(stack[top]) >= priority(exp[i])) {
                printf("%c", pop());
            }
            push(exp[i]);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}