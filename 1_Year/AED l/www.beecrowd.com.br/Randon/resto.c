#include <stdio.h>

int main () {
    int n, i=1;
    scanf("%d", &n);

    while (i<100)
    {   
        if (i%n==2)
            printf("%d\n", i);
    
        i++;
    }
    
    return 0;
}