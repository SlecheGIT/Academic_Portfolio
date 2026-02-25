#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, ir, i=1, soma=0, r;

    scanf("%d", &r);
    for (ir=1; ir<=r; ir++)
    {
        scanf("%d",&n);
        while (i<n)
        {
            if (n%i==0)
            {
                soma= soma+i;
            }
            i++;
        }
            if (soma==n)
                {
                printf("%d eh perfeito\n", n);
                } else {
                printf("%d nao eh perfeito\n", n);
            }
        i=1;
        soma=0;
     }
    return 0;
}
/*
3 - repetir programa

6 | 6 eh perfeito
5 | 5 nao eh perfeito
28 |5 nao eh perfeito
*/