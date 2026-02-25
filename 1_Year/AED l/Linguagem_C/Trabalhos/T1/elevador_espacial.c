#include <stdio.h>

int main()
{
    int a1, a01, a02, a03, a04, a05, a06;
    int andar, i;
    //entrada de dados
    printf("\nDigite o numero do andar: ");
    scanf("%d", &andar);

    while (!(andar >= 1 && andar <= 1000000)){
        if (!(andar >= 1 && andar <= 1000000)){
            printf("\nO andar deve estar entre 1 a 10^6, digite novamente: ");
            scanf("%d", &andar);
        }
    }
        for (i = 1; i <= andar; i++) {
            //separação das casas numericas
            a06 =  i / 1000000;
            a05 = (i % 1000000) / 100000;
            a04 = (i % 100000) / 10000;
            a03 = (i % 10000) / 1000;
            a02 = (i % 1000) / 100;
            a01 = (i % 100) / 10;
            a1  = (i % 10);

            //verificação de 4 ou 13
            if (((a06==1) && (a05 == 3)) || ((a05==1) && (a04 == 3)) || ((a04==1) && (a03 == 3)) || ((a03==1) && (a02 == 3)) || ((a02==1) && (a01 == 3)) || ((a01==1) && (a1  == 3)))
                andar++;
            else if ((a06 == 4) || (a05 == 4) || (a04 == 4) || (a03 == 4) || (a02 == 4) || (a01 == 4) || (a1 == 4))
                andar++;
        }

    printf("\n%d", andar);

    return 0;
}
