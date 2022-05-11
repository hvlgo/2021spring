#include <stdio.h>

int main()
{
    char c1, c2, c3, c4, c5;
    scanf("%c%c%c", &c1, &c2, &c3);
    c4 = getchar();
    c5 = getchar();
    putchar(c1);
    putchar(c2);
    printf("%c%c\n", c4, c5);
}
