#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    scanf("%s", s);

    int l = 0;
    int r = strlen(s) - 1;
    int is_pal = 1;

    while (l < r) {
        if (s[l] != s[r]) {
            is_pal = 0;
            break;
        }
        l++;
        r--;
    }

    if (is_pal)
        printf("YES");
    else
        printf("NO");

    return 0;
}
