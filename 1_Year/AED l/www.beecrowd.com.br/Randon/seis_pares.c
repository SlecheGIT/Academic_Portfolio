#include <stdio.h>

int main () {
    int i=0, pos=0;
    float n;

    while (i<6)
    {
        scanf("%f", &n);
        if (n>0)
            pos++;
        i++;
    }
    printf("%d valores positivos\n", pos);
    
    return 0;
}