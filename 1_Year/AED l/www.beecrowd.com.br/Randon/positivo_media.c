#include <stdio.h>

int main () {
    int i=0;
    float n, media=0, cont=0;

    while (i<6)
    {
        scanf("%f", &n);
        if (n>0)
        {
            cont++;
            media+=n;
        }
        i++;
    }
    printf("%.0f valores positivos\n", cont);
    printf("%.1f\n", media/cont);
    
    return 0;
}