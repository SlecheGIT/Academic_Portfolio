#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    struct Lista *ant;
    int x;
    struct Lista *prox;

}Lista;

void inserir (Lista **inicio, int x) {
    Lista *novo = malloc(sizeof(Lista));
    Lista *aux = *inicio;

    
    
    novo->x = x;
    novo->prox = NULL;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    novo->ant = aux;
    aux->prox = novo;
}

int main () {
    Lista *lista = malloc(sizeof(Lista));
    Lista *L;
    lista->x = NULL;
    lista->ant = NULL;
    lista->prox = NULL;

	inserir(&lista, 4);
	inserir(&lista, 3);
	inserir(&lista, 2);
	inserir(&lista, 1);
	inserir(&lista, 0);
		
    L = lista->prox;
    while( L )
	{
		printf("[%i]->", L->x);
		if (L->prox==NULL)
			break;
		L = L->prox;
	}	
	printf("\n");
	printf("\n");

    while( L )
	{
		printf("[%i]->", L->x);
		if (L->ant==NULL)
			break;
		L = L->ant;
	}	

    return 0;
}