//(2.1) Apresentar os algoritmos de inserção e remoção de uma lista ordenada em alocação sequencial.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
    int x;
    struct lista *prox;
};

void inserir (struct lista **inicio, int x) 
{
    struct lista *novo = malloc(sizeof(struct lista));
    struct lista *anterior;
    struct lista *aux;

    if (novo)
    {
        novo->x = x;
        if (*inicio == NULL){
            novo->prox = NULL;
            *inicio = novo;
        } else {
            aux = *inicio;
            
            if (x <= aux->x)
            {
                novo->prox = *inicio;
                *inicio = novo;
            } else if(x > aux->x) {

                do {
                    if(aux->prox == NULL){
                        novo->prox = NULL;
                        aux->prox = novo;
                        break;
                    }
                    anterior = aux;
                    aux = aux->prox;

                    if (x <= aux->x)
                    {
                        novo->prox = aux;
                        anterior->prox = novo;
                        break;
                    }
                    
                } while (aux);
            } 
        }
    } else 
        printf("erro ao alocar");
}

void remover (struct lista **inicio, int x) {
    struct lista *anterior;
    struct lista *aux;
    aux = *inicio;
    int pass = 1;

    if (aux->x == x)
    {
        *inicio = aux->prox;
        pass = 0; // fecha o proximo loop para encerrar o procedimento
    } // primeira verificação caso o x seja o no cabeça

    while (pass) // pass != 0
    {
        if (aux->prox == NULL) // verifica o proximo para que o aux não receba null e perca a posição
        {
            printf("variavel nao encontrada\n");
            break; // encerra o loop
        }

        anterior = aux;
        aux = aux->prox;
    
        if (aux->x == x)
        {
            anterior->prox = aux->prox; //pula o no que esta igual a x
            break;
        }
        


        
    }
    
}

void juntar(struct lista **a, struct lista **b){
    struct lista *D = malloc(sizeof(struct lista));
    
    

}

int main () {
    struct lista *A = NULL;
    struct lista *B = NULL;
    struct lista *copy;
    int x;

    printf("insira a lista, 0 para parar\n");
    do {
        scanf("%d", &x);
        inserir(&A , x);
    } while (x != 0);
        
    copy = A;
    while (copy)
    {
        printf("[%d]->", copy->x);
        if (copy->prox == NULL)
            break;
        copy = copy->prox;
    }
    printf("\n");

    system("pause");
    system("cls");
    // printf("apagar: \n");
    // scanf("%d", &x);
    // remover(&inicio, x);
    printf("insira a lista, 0 para parar\n");
    do {
        scanf("%d", &x);
        inserir(&B , x);

    } while (x != 0);
    copy = B;
    while (copy)
    {
        printf("[%d]->", copy->x);
        if (copy->prox == NULL)
            break;
        copy = copy->prox;
    }
    printf("\n");

}