#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int len, char* str) {
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    int n1, n2;
    char *s1 = NULL, *s2 = NULL;

    scanf("%d", &n1);
    getchar();
    s1 = calloc(n1 + 1, sizeof(char));
    if (!s1) return 1;

    for (int i = 0; i < n1; ++i)
        scanf("%c", &s1[i]);
    s1[n1] = '\0';

    scanf("%d", &n2);
    getchar();
    s2 = calloc(n2 + 1, sizeof(char));
    if (!s2) return 1;

    for (int i = 0; i < n2; ++i)
        scanf("%c", &s2[i]);
    s2[n2] = '\0';

    for (int i = 0; i <= n2 - n1; ++i) {
        if (strncmp(&s2[i], s1, n1) == 0) {
            reverse(n1, &s2[i]);
            i += n1 - 1;
        }
    }

    printf("%s\n", s2);

    free(s1);
    free(s2);

    return 0;
}

