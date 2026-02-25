#include <stdio.h>

int main () {
    float n, quant, soma;

    scanf("%f %f", &n, &quant);

    if (n==1)
        n=4*quant;
    else if (n==2)
        n=4.5*quant;
    else if (n==3)
        n=5*quant;
    else if (n==4)
        n=2*quant;
    else if (n==5)
        n=1.5*quant;

    printf("Total: R$ %.2lf\n", n);

    return 0;
}