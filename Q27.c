#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
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

// Function to find length
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list
    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for(int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Traverse both lists
    while(head1 != NULL && head2 != NULL) {
        if(head1->data == head2->data)
            return head1->data;

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1; // No intersection
}

// ---- Main ----
int main() {
    int n, m;

    scanf("%d", &n);
    int arr1[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &m);
    int arr2[m];
    for(int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    struct Node* head1 = createList(arr1, n);
    struct Node* head2 = createList(arr2, m);

    int result = findIntersection(head1, head2);

    if(result != -1)
        printf("%d\n", result);
    else
        printf("No Intersection\n");

    return 0;
}