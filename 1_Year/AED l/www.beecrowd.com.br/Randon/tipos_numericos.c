#include <stdio.h>

int main () {
    int n, pos=0, neg=0, par=0, impar=0, i=0;

    while (i<5)
    {
    scanf("%d", &n);

    if (n>0)
        pos++;
    else if (n<0)
        neg++;

    if (n%2==0)
        par++;
    else if (n%2!=0)
        impar++;
    i++;
    }
    printf("%d valor(es) par(es)\n", par);
    printf("%d valor(es) impar(es)\n", impar);
    printf("%d valor(es) positivo(s)\n", pos);
    printf("%d valor(es) negativo(s)\n", neg);
    
    return 0;
}