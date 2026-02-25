#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gera_cpf_valido(char *cpf[])
{
    int dig[11];
    dig[9] = 0, dig[10] = 0;

    for (int i1 = 10, i2 = 2, i = 0; (i < 9); i++, i1--, i2++)
    {
        dig[i] = rand() % 10;
        *cpf[i] = dig[i] + '0';
        dig[9] += dig[i] * i1;
        dig[10] += dig[i] * i2;
    }
    if ((dig[9] % 11) < 2)
        dig[9] = 0;
    else
        dig[9] = 11 - (dig[9] % 11);
        
    if ((dig[10] % 11) < 2)
        dig[10] = 0;
    else
    dig[10] = 11 - (dig[10] % 11);

    *cpf[9] = dig[9] + '0';
    *cpf[10] = dig[10] + '0';
}

int main()
{
    srand(time(NULL));
    char cpf[50] [15];
    int cpf_cont=0, vezes;
    char *p[15];
    
    scanf("%d", &vezes);
    for (int i =0 ; i < vezes ; i++)
    {
        for (int i = 0; i < 11; i++)
            p[i] = &cpf[cpf_cont] [i];

        gera_cpf_valido(p);
        cpf_cont++;
    }

    for (int i = 0; i < cpf_cont; i++)
    {
    printf("\n\n %i : ", i);
    printf("%c", cpf[i][0] );
    printf("%c", cpf[i][1] );
    printf("%c.", cpf[i][2] );
    printf("%c", cpf[i][3] );
    printf("%c", cpf[i][4] );
    printf("%c.", cpf[i][5] );
    printf("%c", cpf[i][6] );
    printf("%c", cpf[i][7] );
    printf("%c-", cpf[i][8] );
    printf("%c", cpf[i][9] );
    printf("%c", cpf[i][10]);
    }
    return 0;
}