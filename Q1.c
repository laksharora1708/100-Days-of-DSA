#include <stdio.h>

int main() {
    int n, pos, x;
    scanf("%d", &n);

    int arr[1000];  // assuming n ≤ 999 for safety
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos); // 1-based index
    scanf("%d", &x);

    // Shift elements to the right from the end to pos-1
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert x at position pos-1
    arr[pos - 1] = x;

    // Print updated array of size n+1
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
