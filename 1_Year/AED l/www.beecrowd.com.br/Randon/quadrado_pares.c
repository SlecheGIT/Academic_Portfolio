#include <stdio.h>

int main () {
    int i=1, n, r;
    scanf("%d", &r);

    while (i<=r)
    {
        if (i%2==0)
            printf("%d^2 = %d\n", i, (i*i));
        i++;
    }
    

    return 0;
}