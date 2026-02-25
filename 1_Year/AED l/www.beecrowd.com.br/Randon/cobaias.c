#include <stdio.h>

int main()
{
    float cob, ratos = 0, coelhos = 0, sapos = 0; 
    int r;
    char c;

    scanf("%d", &r);
    for (int i = 0; i < r; i++)
    {
        scanf("%f %c", &cob, &c);
        if (c == 'C')
            coelhos += cob;
        else if (c == 'R')
            ratos += cob;
        else if (c == 'S')
            sapos += cob;
    }
    cob = sapos + ratos + coelhos;
    printf("Total: %.0f cobaias\n", cob);
    printf("Total de coelhos: %.0f\n", coelhos);
    printf("Total de ratos: %.0f\n", ratos);
    printf("Total de sapos: %.0f\n", sapos);
    printf("Percentual de coelhos: %.2f %%\n", (coelhos/cob)*100);
    printf("Percentual de ratos: %.2f %%\n", (ratos/cob)*100);
    printf("Percentual de sapos: %.2f %%\n", (sapos/cob)*100);


    return 0;
}