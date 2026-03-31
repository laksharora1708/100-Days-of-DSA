#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int arr[], int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Rotate list right by k
struct Node* rotateRight(struct Node* head, int k) {
    if(head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node *temp = head;
    int n = 1;

    // Find length and last node
    while(temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Make circular
    temp->next = head;

    k = k % n;  // handle large k
    int steps = n - k;

    // Move to (n-k)th node
    struct Node* newTail = head;
    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Set new head
    struct Node* newHead = newTail->next;

    // Break the circle
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// ---- Main ----
int main() {
    int n, k;

    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &k);

    struct Node* head = createList(arr, n);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}