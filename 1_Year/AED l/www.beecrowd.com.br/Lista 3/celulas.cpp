#include <stdio.h>

int main()
{
    int n, i, sobras, notas[7];

    scanf("%d", &n);
    notas[0] = n / 100;
    n = n % 100;
    notas[1] = n / 50;
    n = n % 50;
    notas[2] = n / 20;
    n = n % 20;
    notas[3] = n / 10;
    n = n % 10;
    notas[4] = n / 5;
    n = n % 5;
    notas[5] = n / 2;
    n = n % 2;
    notas[6] = n / 1;
    n = n % 1;

    printf("%d nota(s) de R$ 100,00\n", notas[0]);
    printf("%d nota(s) de R$ 50,00\n", notas[1]);
    printf("%d nota(s) de R$ 20,00\n", notas[2]);
    printf("%d nota(s) de R$ 10,00\n", notas[3]);
    printf("%d nota(s) de R$ 5,00\n", notas[4]);
    printf("%d nota(s) de R$ 2,00\n", notas[5]);
    printf("%d nota(s) de R$ 1,00\n", notas[6]);

    return 0;
}