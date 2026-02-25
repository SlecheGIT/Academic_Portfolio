#include <stdio.h>

int main () {
    int i=0, r, n;
    scanf("%d", &r);

    while (i<r)
    {
        scanf("%d", &n);

        if (n==0)
            printf("NULL\n");
        else if (n%2==0 && n>0)
            printf("EVEN POSITIVE\n");
        else if (n%2==0 && n<0)
            printf("EVEN NEGATIVE\n");
        else if (n%2!=0 && n>0)
            printf("ODD POSITIVE\n");
        else if (n%2!=0 && n<0)
            printf("ODD NEGATIVE\n");
        i++;
    }
    
    return 0;
}