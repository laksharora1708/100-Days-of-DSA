#include <stdio.h>

int main() {
    int p, q;

    scanf("%d", &p);
    int A[p];
    for(int i = 0; i < p; i++)
        scanf("%d", &A[i]);

    scanf("%d", &q);
    int B[q];
    for(int i = 0; i < q; i++)
        scanf("%d", &B[i]);

    int C[p + q];
    int i = 0, j = 0, k = 0;

    while(i < p && j < q) {
        if(A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while(i < p)
        C[k++] = A[i++];

    while(j < q)
        C[k++] = B[j++];

    for(int i = 0; i < p + q; i++)
        printf("%d ", C[i]);

    return 0;
}