#include <stdio.h>

#define MAX 100

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Queue operations
void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

// Stack operations
void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int N, x;

    scanf("%d", &N);

    // Input queue elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue -> stack
    for (int i = 0; i < N; i++) {
        push(dequeue());
    }

    // Step 2: Move stack -> queue
    for (int i = 0; i < N; i++) {
        enqueue(pop());
    }

    // Print reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}