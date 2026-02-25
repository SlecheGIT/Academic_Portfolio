#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char AFD (int cont_alfabeto,int cont_estado, char delta[cont_estado][cont_alfabeto+1], char alfabeto[], char caminho) 
{
    int tam = 0, cont = 0, cont_a = 0;
    char palavra[30];

    printf("Entre com a palavra a ser verificada: ");
    scanf("%s", palavra);
    tam = strlen(palavra);

    printf("\nSequencia de estados: %c ", caminho);
    for (int i = 0; i < tam; i++)
    {
        while ((caminho != delta[cont][0]) && (cont < cont_estado)) //encontra o indice do estado atual
            cont++;
        
        if (caminho == delta[cont][0])
        {
            while ((alfabeto[cont_a] != palavra[i]) && (cont_a < cont_alfabeto)) //encontra o indice do proximo estado
                cont_a++;
            
            caminho = delta[cont][cont_a+1]; //percorre para o proximo estado do automato
            printf("%c ", caminho);

            if (caminho == '-')
                return '-'; // retorna caso ja a palavra ja tenha sido declarada invalida
        }
        cont = 0;
        cont_a = 0;
    }
    printf("\n");
    return caminho; //retorna fim da palavra
}

int main () {
    char aux[30] = {0};
    char final, inicial;
    int cont_alfabeto = 0, cont_estado = 0, cont_aceitos = 0;
    int cont = 0;


    // entrada de dados do alfabeto {
    printf("Entre com o alfabeto: ");
    scanf("%s", aux);
    cont_alfabeto = strlen(aux); // contagem de caracteres
    char alfabeto[(cont_alfabeto / 2) + 1];
    for (int i = 0; i < cont_alfabeto; i++)
        if ((aux[i] != ',')  && (aux[i] != ' '))
        {
            alfabeto[cont] = aux[i]; // eliminação das virgulas
            cont++;
        }
    cont_alfabeto = (cont_alfabeto / 2) + 1; // contagem atualizada sem virgulas
    alfabeto[cont] = '\0'; //declarando fim da string
    cont = 0;
    //}


    // entrada de dados do alfabeto {
    printf("Entre com os estados: ");
    scanf("%s", aux);
    cont_estado = strlen(aux); // contagem de caracteres
    char estado[(cont_estado / 2) + 1];
    for (int i = 0; i < cont_estado; i++)
        if ((aux[i] != ',')  && (aux[i] != ' '))
        {
            estado[cont] = aux[i]; // eliminação das virgulas
            cont++;
        }
    cont_estado = (cont_estado / 2) + 1; // contagem atualizada sem virgulas
    estado[cont] = '\0'; //declarando fim da string
    cont = 0;
    //}
    

    printf("Entre com o estado inicial: ");
    scanf(" %c", &inicial); // entrada do ponto inicial, apenas 1 caracter


    // entrada de dados do alfabeto {
    printf("Entre com os estados de aceitacao: ");
    scanf("%s", aux);
    cont_aceitos = strlen(aux); // contagem de caracteres
    char aceitos[(cont_aceitos / 2) +1];
    for (int i = 0; i < cont_aceitos; i++)
        if ((aux[i] != ',')  && (aux[i] != ' '))
        {
           aceitos[cont] = aux[i]; // eliminação das virgulas
            cont++;
        }
    cont_aceitos = (cont_aceitos / 2) +1;  // contagem atualizada sem virgulas
    aceitos[cont] = '\0'; //declarando fim da string
    cont = 0;
    //}


    char delta[cont_estado][cont_alfabeto+1]; // iniciando matriz delta alocando exatamente o necessario
    
    for (int i = 0; i < cont_estado; i++)
    {
        delta[i][0] = estado[i]; // iniciando os indices da matriz
        for (int j = 0; j < cont_alfabeto; j++)
        {
            printf("Delta(%c, %c): ", delta[i][0], alfabeto[j]); 
            scanf(" %c", &delta[i][j+1]); //entrando com parametros da descrição formal
            cont++;
        }
        cont = 0;
    }

    do { 
        cont = 0;
        final = AFD(cont_alfabeto,cont_estado, delta, alfabeto, inicial); // executa a funcao de verificação
        if (final == '-')
            printf("\nA maquina travou\n-> palavra rejeitada\n");
        else {
            //verifica se a palavra terminou em algum estado de aceitção
            while ((final != aceitos[cont]) && cont < cont_aceitos) 
                cont++; // conta o indice pro vetor da posição aceita se houver
            if (final == aceitos[cont]) 
                printf("-> Palavra Aceita!\n");
            else
                printf("-> palavra rejeitada\n");
        }
        printf("---------------------\n");
        printf("\nDeseja inserir outra palavra?\n(1) para inserir\n(0) para sair\n -> ");
        scanf("%d", &cont);
        printf("\n\n");
            
    } while (cont == 1);  //repetição da palavra

    return 0;
}