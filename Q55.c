#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue
struct Node* queue[100];
int front = 0, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* curr = dequeue();

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i >= n) break;

        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Right View
void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Node* q[100];
    int f = 0, r = -1;

    q[++r] = root;

    while (f <= r) {
        int size = r - f + 1;

        for (int i = 0; i < size; i++) {
            struct Node* temp = q[f++];

            // last node of level
            if (i == size - 1)
                printf("%d ", temp->data);

            if (temp->left)
                q[++r] = temp->left;
            if (temp->right)
                q[++r] = temp->right;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}