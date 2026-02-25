/*  Resolva T4 usando modulariza��o. Os dados de execu��o dever�o ser
    recebidos via argumento do programa na linha de comando.

    Exemplos de execu��es

    app 3 GCTTTCGACGAT GATCGAGCTTCGAA GGTCTAGCTAAT TCGA

    SAIDA_2 = Quantidade de bacterias: 3
    SAIDA_3 = Bacteria: GCTTTCGACGAT
    SAIDA_3 = Bacteria: GATCGAGCTTCGAA
    SAIDA_3 = Bacteria: GGTCTAGCTAAT
    SAIDA_4 = Virus: TCGA
    SAIDA_5 = Bacteria infectada: GCTT
    SAIDA_5 = Bacteria infectada: GAGCTA
    SAIDA_5 = Bacteria infectada: GGTCTAGCTAAT
    SAIDA_6 = DNA resultante: GCT



    app 5 AGCT TGC CGCAA TGTC ATGTTC T

    SAIDA_2 = Quantidade de bacterias: 5
    SAIDA_3 = Bacteria: AGCT
    SAIDA_3 = Bacteria: TGC
    SAIDA_3 = Bacteria: CGCAA
    SAIDA_3 = Bacteria: TGTC
    SAIDA_3 = Bacteria: ATGTTC
    SAIDA_4 = Virus: T
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: CGCAA
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_6 = DNA resultante: GC


*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LIMITE_BACTERIAS 10
#define COMPR_BACTERIAS 1000
#define COMPR_VIRUS 1000

#define SAIDA_2 "\nSAIDA_2 = Quantidade de bacterias: %d"
#define SAIDA_3 "\nSAIDA_3 = Bacteria: %s"
#define SAIDA_4 "\nSAIDA_4 = Virus: %s"
#define SAIDA_5 "\nSAIDA_5 = Bacteria infectada: %s"
#define SAIDA_6 "\nSAIDA_6 = DNA resultante: %s"
#define SAIDA_7 "\nSAIDA_7 = NUMERO INVALIDO DE ARGUMENTOS"
#define SAIDA_8 "\nSAIDA_8 = Tamanho do Virus Invalido!"
#define SAIDA_9 "\nSAIDA_9 = Tamanho da Bacteria Invalido!"
#define SAIDA_10 "\nSAIDA_10 = CARACTERES INVALIDOS"


void removeSubstring(char *string, const char *sub)
{
    int n = strlen(string);
    int m = strlen(sub);
    char temp[COMPR_BACTERIAS]; // uma cópia temporária da string de bacterias contaminada
    int i, j, k;

    for (i = 0; i <= n - m; i++) //compara todas as variaveis para encontrar a sucessao correta do virus
    {
        for (j = i; j < i + m; j++)
        {
            if (string[j] != sub[j - i])
                break;
        }

        if (j == i + m)
        {
        
            for (k = 0; k < i; k++)
            {
                temp[k] = string[k];
            }

            for (int x = i + m; x < n; x++, k++)
            {
                temp[k] = string[x];
            }

            temp[k] = '\0'; // limpa as variaveis que foram alocadas para frente

            strcpy(string, temp); // substitui a bacteria comum pela contaminada

            // Atualize os índices para a próxima iteração
            n = strlen(string);
            i--;
        }
    }
}

// Função para encontrar a maior substring comum entre duas strings
char *Maior_Dna(char *str1, char *str2) {
    int DNA1 = strlen(str1);
    int DNA2 = strlen(str2);
    int maxLen = 0;
    int startPos = 0;
        // malloc aloca a memoria de forma dinamica
    int **teste = (int **)malloc((DNA1 + 1) * sizeof(int *));
    for (int i = 0; i <= DNA1; i++) {
        teste[i] = (int *)malloc((DNA2 + 1) * sizeof(int));
    }
        // monta a tabela de LCS, usando progamacao dinamica
    for (int i = 0; i <= DNA1; i++) {
        for (int j = 0; j <= DNA2; j++) {
            if (i == 0 || j == 0) {
                teste[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) { 
                teste[i][j] = teste[i - 1][j - 1] + 1;
                if (teste[i][j] > maxLen) {
                    maxLen = teste[i][j];
                    startPos = i - maxLen;
                }
            } else {
                teste[i][j] = 0;
            }
        }
    }
        // armazena a maior substring entre duas strings, retornando em result
    char *result = (char *)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, str1 + startPos, maxLen);
    result[maxLen] = '\0';
         // limpando o buffer resultante    
    for (int i = 0; i <= DNA1; i++) {
        free(teste[i]);
    }
    free(teste);

    return result;
}

// Função para encontrar a maior substring comum entre as bacterias
char *DNA_Result(char **strings, int numStrings) {
    char *substring = strings[0];
    int len = strlen(substring);

    for (int i = 1; i < numStrings; i++) {
        substring = Maior_Dna(substring, strings[i]);
    }

    return substring;
}

int main (int argc, char *argv[]){
    int nBacterias, menorBac = 1000, maiorBac = 0, posi;
    char BACTERIAS[LIMITE_BACTERIAS][COMPR_BACTERIAS] = {'\0'};
    char VIRUS[COMPR_VIRUS] = {'\0'};

    nBacterias = atoi(argv[1]);  // aloca o argumento recebido na variavel
    
    
    if (nBacterias+3 != argc) // comparando com a quantidade de entradas
    {
        printf("%d", argc);
        printf(SAIDA_7);
        return 0;
    }
    if (nBacterias<1 || nBacterias > 10){// verrificação das entradas
        printf(SAIDA_7);
        return 0 ;
    }
    for(int i=2;i<argc-1;i++) {
        strcpy(BACTERIAS[i-2],argv[i]); // aloca o argumento recebido na variavel
        if ((strlen(BACTERIAS[i-2]) < 1) || (strlen(BACTERIAS[i-2]) > COMPR_BACTERIAS))
        {
            printf(SAIDA_9);
            return 0;
        }
        for (int j = 0; j < strlen(BACTERIAS[i-2]); j++)
            if ((BACTERIAS[i-2][j] != 'A') && (BACTERIAS[i-2][j] != 'C') && (BACTERIAS[i-2][j] != 'G') && (BACTERIAS[i-2][j] != 'T'))
            {
                printf(SAIDA_10);
                return 0;
            }
    }
    strcpy(VIRUS,argv[argc-1]); // aloca o argumento recebido na variavel
    for (int i = 0; i < strlen(VIRUS); i++)
        if ((VIRUS[i] != 'A') && (VIRUS[i] != 'C') && (VIRUS[i] != 'G') && (VIRUS[i] != 'T'))
        {
            printf(SAIDA_10);
            return 0;
        }
    
    if ((strlen(VIRUS)<1) || (strlen(VIRUS)>1000)) 
    {
        printf(SAIDA_8);
        return 0;
    }

        // imprime a quantia de bacterias
    printf(SAIDA_2, nBacterias);
    for (int i = 0; i < nBacterias; i++)
        printf(SAIDA_3, BACTERIAS[i]); // imprime, em um loop, as bacterias inseridas
    printf(SAIDA_4, VIRUS); // imprime o virus
     // recebe as bacterias e o virus e apaga a substring VIRUS em cada BACTERIA
    for (int i = 0; i < nBacterias; i++)  
    {     //remove o virus em cada bacteria
        removeSubstring(BACTERIAS[i], VIRUS);
        printf(SAIDA_5, BACTERIAS[i]); //impressao do virus descontaminado
        
    }
        // aloca a memoria na string de bacterias 
    char **strings = (char **)malloc(nBacterias * sizeof(char *));

      for (int i = 0; i < nBacterias; i++) {
            //armazena as bacterias em um vetor de strings    
        char matriz[1000];
        strcpy(matriz,BACTERIAS[i]);

        

        strings[i] = strdup(matriz); //atribui os valores 
    }
        //chama a funcao que econtra a maior substring
    char *DnaResultante =DNA_Result(strings, nBacterias);

    printf(SAIDA_6, DnaResultante); // imprime o DNA resultante

        // Liberação da memoria, que foi alocada dinamicamente
    for (int i = 0; i < nBacterias; i++) {
        free(strings[i]);
    }
    free(strings); // limpando o buffer resultante
    free(DnaResultante);
      


    return 0;
}



