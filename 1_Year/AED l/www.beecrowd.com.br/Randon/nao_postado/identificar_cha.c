#include <stdio.h>

int main () {
    int cha, n, cont=0;

    scanf("%d", &n);

    for (int i=0; i<5; i++){
        scanf("%d", &cha);
        if (cha==n)
            cont++;
    }
    printf("%d\n", cont);
    return 0;
}