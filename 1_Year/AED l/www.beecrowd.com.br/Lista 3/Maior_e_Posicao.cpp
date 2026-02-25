#include <stdio.h>

int main()
{
    long long int vet[100], maior = 0;
    int i, pos;

    for (i = 0; i < 10; i++)
    {
        scanf("%lld", &vet[i]);
        if (vet[i] > maior)
        {
            maior = vet[i];
            pos = i;
        }
    }
    printf("%lld\n", maior);
    printf("%d\n", pos);

    return 0;
}