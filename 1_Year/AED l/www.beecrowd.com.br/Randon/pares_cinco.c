#include <stdio.h>

int main () {
    int n[5], i=0, p=0;

    while (i<5)
    {
        scanf("%d", &n[i]);
        if (n[i]%2==0)
            p++;
        
        i++;
    }
    printf("%d valores pares\n", p);

    return 0;
}