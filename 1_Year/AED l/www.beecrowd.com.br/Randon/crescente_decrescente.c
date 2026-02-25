#include <stdio.h>

int main () {
    int x, y;
    while (x!=y)
    {
    scanf("%d %d", &x, &y);
    if (x==y)
        return 0;
    else if (x>y)
        printf("Decrescente\n");
    else
        printf("Crescente\n");
    }
}