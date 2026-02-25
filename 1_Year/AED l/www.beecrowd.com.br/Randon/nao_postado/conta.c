#include <stdio.h>

int main () {
    int r, conta=0, n;
    scanf("%d", &r);
    for (int i=0; i<r; i++){
        scanf("%d", &n);
        if (n%2!=0)
            conta++;
        printf("%d\n", conta);
        conta=0;
    }        

    return 0;
}