/*  Fazer um programa que receba via argumento dois conjuntos de numeros inteiros onde
    cada conjunto tem 5 numeros. O primeiro conjunto deve ser armazenado no vetor A e o
    segundo conjunto no vetor B. Construa um vetor C com os numeros repetidos entre
    A e B. O numero repetido deve aparecer uma unica vez no vetor C. Informe os repetidos.

    Ex. app 1 2 3 4 5 4 20 2 1 2

        SAIDA_1 = Os numeros do conjunto A sao: 1 2 3 4 5
        SAIDA_2 = Os numeros do conjunto B sao: 4 20 2 1 2
        SAIDA_3 = O numero 1 eh repetido!
        SAIDA_3 = O numero 2 eh repetido!
        SAIDA_3 = O numero 4 eh repetido!


    Ex. app 6 3 2 5 3 9 30 66 3 70

        SAIDA_1 = Os numeros do conjunto A sao: 6 3 2 5 3
        SAIDA_2 = Os numeros do conjunto B sao: 9 30 66 3 70
        SAIDA_3 = O numero 3 eh repetido!


*/
#include <stdio.h>
#include <stdlib.h>

#define SAIDA_1 "\nSAIDA_1 = Os numeros do conjunto A sao: "
#define SAIDA_2 "\nSAIDA_2 = Os numeros do conjunto B sao: "
#define SAIDA_3 "\nSAIDA_3 = O numero %d eh repetido!"
#define SAIDA_4 "\nSAIDA_4 = Nao existem numeros repetidos entre os dois conjuntos!\n"
#define SAIDA_5 "\nSAIDA_5 = A quantidade invalida de argumentos!\n"

int main(int argc, char *argv[])
{
    int A[5], B[5], C[5] ;
    int i, j,k=0, c = 0, cont = 0;
    int repeti=0;

    if (argc == 11) {
        for (i = 0; i < 5; i++)
        {
            A[i] = atoi(argv[i]);
            B[i] = atoi(argv[i+5]);
        }  
        printf(SAIDA_1);
        for ( i = 0; i < 5; i++)
            printf(" %d", A[i]);
        printf(SAIDA_2);
        for (i = 0; i < 5; i++)
            printf("%d ", B[i]);

        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (A[i] == B[j])
                {
                    cont = 1;
                    while (c<k)
                    {
                        if (A[i]==C[c])
                            repeti=1;
                        c++;
                    }
                    c=0;
                    if (repeti==0){
                        C[k] = A[i];
                        printf(SAIDA_3, C[k]);
                          
                        k++;
                    }
                    repeti=0;
                }
                
            }

        }
        if (cont == 0)
            printf(SAIDA_4);
        else
            printf("\n");
        
    } else    
        printf(SAIDA_5);


    return 0;
}
