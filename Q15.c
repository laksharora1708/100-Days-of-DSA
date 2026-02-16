#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;

    // Input the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Sum of primary diagonal (only valid where i == j)
    int limit = (m < n) ? m : n;  // Works even for non-square matrices
    for (int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    printf("%d", sum);

    return 0;
}
