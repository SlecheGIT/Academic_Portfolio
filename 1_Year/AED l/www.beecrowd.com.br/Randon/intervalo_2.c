#include <stdio.h>

int main () {
    int n, r, i=0, in=0, out=0;
    scanf("%d", &r);

    while (i<r)
    {
        scanf("%d", &n);
        if (n>=10 && n<=20)
            in++;
        else
            out++;
        i++;
    }
    printf("%d in\n", in);
    printf("%d out\n", out);

    
    return 0;
}