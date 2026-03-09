#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert nodes at the end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node* temp = NULL;

    while (l1 != NULL && l2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        if (l1->data < l2->data) {
            newNode->data = l1->data;
            l1 = l1->next;
        } else {
            newNode->data = l2->data;
            l2 = l2->next;
        }
        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Append remaining nodes of l1
    while (l1 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = l1->data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
        l1 = l1->next;
    }

    // Append remaining nodes of l2
    while (l2 != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = l2->data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
        l2 = l2->next;
    }

    return result;
}

// Print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, value;

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }

    struct Node* merged = mergeLists(list1, list2);

    printList(merged);

    return 0;
}