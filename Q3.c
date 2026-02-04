#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &k);

    int comparisons = 0, found_index = -1;

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1)
        printf("Found at index %d\n", found_index);
    else
        printf("Not Found\n");

    printf("Comparisons = %d\n", comparisons);

    return 0;
}
