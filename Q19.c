#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    
    // Read array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minSum = 1000000;  // large value
    int num1 = 0, num2 = 0;

    // Check all pairs
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if (abs(sum) < abs(minSum)) {
                minSum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    printf("%d %d\n", num1, num2);

    return 0;
}