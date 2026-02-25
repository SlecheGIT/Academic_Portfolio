#include <stdio.h>

int main () {
    int n, k, i=1, t, soma;

    scanf("%d", &t);
    while (i<t){
        scanf("%d %d", &n, &k);
        soma = (n/k) + (n%k);
        printf("%d\n",soma);
        i++;
    }
    return 0;
}