#include <stdio.h>

int main()
{
    double nota1, nota2;

    do {
        scanf("%lf", &nota1);
        if (nota1 < 0 || nota1 > 10)
            printf("nota invalida\n");
    } while (nota1 < 0 || nota1 > 10);

    do {
        scanf("%lf", &nota2);
        if (nota2 < 0 || nota2 > 10)
            printf("nota invalida\n");
    } while (nota2 < 0 || nota2 > 10);
    printf("media = %.2f\n", (nota1 + nota2) / 2.0);
    return 0;
}