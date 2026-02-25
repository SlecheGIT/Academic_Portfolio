#include <stdio.h>

int main () {
    int n, v[10];

    scanf ("%d", &n);
    
    for (int i=0; i<10; i++){
        printf("N[%d] = %d\n", i, n);
        n= n*2;
    }

    return 0;
}