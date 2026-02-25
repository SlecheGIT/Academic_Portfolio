#include <stdio.h>

void extenso (long int saldo) {
    int a01, a02, a03, a04, a05, a06;
    if (saldo!=0) {
        a06 = (saldo % 1000000) / 100000;
        a05 = (saldo % 100000) / 10000;
        a04 = (saldo % 10000) / 1000;
        a03 = (saldo % 1000) / 100;
        a02 = (saldo % 100) / 10;
        a01 = (saldo % 10);

        if (a06 == 1)
        {
            if (a05 == 0 && a04 == 0)
                printf("CEM ");
            else
                printf("CENTO E ");
        } else if (a06 == 2)
            printf("DUZENTOS ");
        else if (a06 == 3)
            printf("TREZENTOS ");
        else if (a06 == 4)
            printf("QUATROCENTOS ");
        else if (a06 == 5)
            printf("QUINHENTOS ");
        else if (a06 == 6)
            printf("SEISCENTOS ");
        else if (a06 == 7)
            printf("SETECENTOS ");
        else if (a06 == 8)
            printf("OITOCENTOS ");
        else if (a06 == 9)
            printf("NOVECENTOS ");
        
        if ((a06!=1 && a06!=0) && (a05!=0 || a04!=0))
            printf("E ");

        if (a05 == 1)
        {
            if (a04 == 0)
                printf("DEZ ");
            else if (a04 == 1)
                printf("ONZE ");
            else if (a04 == 2)
                printf("DOZE ");
            else if (a04 == 3)
                printf("TREZE ");
            else if (a04 == 4)
                printf("QUATORZE ");
            else if (a04 == 5)
                printf("QUINZE ");
            else if (a04 == 6)
                printf("DEZESSEIS ");
            else if (a04 == 7)
                printf("DEZESSETE ");
            else if (a04 == 8)
                printf("DEZOITO ");
            else if (a04 == 9)
                printf("DEZENOVE ");
        }
        else if (a05 == 2)
            printf("VINTE ");
        else if (a05 == 3)
            printf("TRINTA ");
        else if (a05 == 4)
            printf("QUARENTA ");
        else if (a05 == 5)
            printf("CINQUENTA ");
        else if (a05 == 6)
            printf("SESSENTA ");
        else if (a05 == 7)
            printf("SETENTA ");
        else if (a05 == 8)
            printf("OITENTA ");
        else if (a05 == 9)
            printf("NOVENTA ");

        if ((a05 != 1 && a05 != 0) && a04 != 0)
            printf("E ");

        if (a05 != 1)
        {
            if (a04 == 1 && a05 != 0)
                printf("UM ");
            else if (a04 == 2)
                printf("DOIS ");
            else if (a04 == 3)
                printf("TRES ");
            else if (a04 == 4)
                printf("QUATRO ");
            else if (a04 == 5)
                printf("CINCO ");
            else if (a04 == 6)
                printf("SEIS ");
            else if (a04 == 7)
                printf("SETE ");
            else if (a04 == 8)
                printf("OITO ");
            else if (a04 == 9)
                printf("NOVE ");
        }
        if (a04 != 0 || a05 != 0 || a06 != 0) {
            if ((a03!=0 && a02==0 && a01==0))
                printf("MIL E ");
            else if (a03!=0 || (a03==0 && a02==0 && a01==0))
                printf("MIL ");
            else if (a03==0 )
                printf("MIL E ");
        }
        if (a03 == 1)
        {
            if (a02 == 0 && a01 == 0)
                printf("CEM ");
            else
                printf("CENTO ");
        }
        if (a03 == 2)
            printf("DUZENTOS ");
        else if (a03 == 3)
            printf("TREZENTOS ");
        else if (a03 == 4)
            printf("QUATROCENTOS ");
        else if (a03 == 5)
            printf("QUINHENTOS ");
        else if (a03 == 6)
            printf("SEISCENTOS ");
        else if (a03 == 7)
            printf("SETECENTOS ");
        else if (a03 == 8)
            printf("OITOCENTOS ");
        else if (a03 == 9)
            printf("NOVECENTOS ");
        if (a03 != 0 && !(a02 == 0 && a01 == 0))
            printf("E ");

        if (a02 == 1) {
            if (a01 == 0)
                printf("DEZ ");
            else if (a01 == 1)
                printf("ONZE ");
            else if (a01 == 2)
                printf("DOZE");
            else if (a01 == 3)
                printf("TREZE ");
            else if (a01 == 4)
                printf("QUATORZE ");
            else if (a01 == 5)
                printf("QUINZE");
            else if (a01 == 6)
                printf("DEZESSEIS ");
            else if (a01 == 7)
                printf("DEZESSETE ");
            else if (a01 == 8)
                printf("DEZOITO ");
            else if (a01 == 9)
                printf("DEZENOVE ");
        }
        else if (a02 == 2)
            printf("VINTE ");
        else if (a02 == 3)
            printf("TRINTA ");
        else if (a02 == 4)
            printf("QUARENTA ");
        else if (a02 == 5)
            printf("CINQUENTA ");
        else if (a02 == 6)
            printf("SESSENTA ");
        else if (a02 == 7)
            printf("SETENTA ");
        else if (a02 == 8)
            printf("OITENTA ");
        else if (a02 == 9)
            printf("NOVENTA ");

        if (a02 != 0 && a02 != 1 && a01 != 0)
            printf("E ");
        if (a02 != 1)
        {
            if (a01 == 1)
                printf("UM ");
            else if (a01 == 2)
                printf("DOIS ");
            else if (a01 == 3)
                printf("TRES ");
            else if (a01 == 4)
                printf("QUATRO ");
            else if (a01 == 5)
                printf("CINCO ");
            else if (a01 == 6)
                printf("SEIS ");
            else if (a01 == 7)
                printf("SETE ");
            else if (a01 == 8)
                printf("OITO ");
            else if (a01 == 9)
                printf("NOVE ");
        }
        printf("REAIS");
    } else
        printf("ZERO REAIS");
}

int main () {
    int sald;
    scanf("%d", &sald);
    extenso(sald);
}

