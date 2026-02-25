#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t = 0, m1 = 0, m2 = 0, ptds = 0;
    int i1, i2, aux;

    printf("Digite o total de azulejos: \n");
    scanf("%d", &t);
    if (t < 3 || t > 10000)
    {
        while (t < 3 || t > 10000)
        {
            printf("\nO total tem que estar entre 3 a 10000\n Digite novamente: ");
            scanf("%d", &t);
        }
    }

    printf("\nDigite o primeiro multiplo de azulejos que serao pintados:\n");
    scanf("%d", &m1);
    if (m1 < 2 || m1 > t)
    {
        while (m1 < 2 || m1 > t) {
            printf("\nO multiplo tem que estar entre 2 a %d\n Digite novamente: ", t);
            scanf("%d", &m1);
        }
    }

    printf("\nDigite o segundo multiplo de azulejos que serao pintados:\n");
    scanf("%d", &m2);
    if (m2 < 2 || m2 > t)
    {
        while (m2 < 2 || m2 > t) {
        printf("\nO multiplo tem que estar entre 2 a %d\n Digite novamente: ", t);
        scanf("%d", &m2);
        }
    }
    
    i1=m1, i2=m2;
    while(m1<=t || m2<=t)
    {
        if (m1<m2 && m1<=t)
            ptds++, m1+=i1;
        else if (m2<m1 && m2<=t)
            ptds++, m2+=i2;
        if(m1==m2 && (m1<=t && m2<=t))
            ptds++, m1+=i1, m2+=i2;
    }    
    printf("\n--> %d\n", ptds);
    return 0;
}