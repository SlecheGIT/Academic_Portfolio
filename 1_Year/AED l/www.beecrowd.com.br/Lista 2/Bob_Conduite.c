#include <stdio.h>

int main ()
{
    int n, n2, i, r;

    scanf("%d", &r);
    for (i=0; i<r; i++)
    {
        scanf("%d %d",&n ,&n2);
        printf("%d\n", n+n2);
    }

    return 0;
}
/*
3 - repetir programa

1 + 1 = 2
8 + 2 = 10
2 + 8 = 10
*/