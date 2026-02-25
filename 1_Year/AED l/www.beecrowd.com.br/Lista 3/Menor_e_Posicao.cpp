#include <stdio.h>

int main()
{
    int menor = 999, i, r, pos;

    scanf("%d", &r);

    int vet[r];

    for (i = 0; i < r; i++)
    {
        scanf("%d", &vet[i]);
        if (vet[i] < menor)
        {
            menor = vet[i];
            pos = i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", menor, pos);

    return 0;
}
