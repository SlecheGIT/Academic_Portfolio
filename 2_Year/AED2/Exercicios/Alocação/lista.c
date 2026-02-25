#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista
{
    struct lista *ant;
    int valor;
    struct lista *prox;

};


void fim(struct lista **atual, int x){
	struct lista *novo = malloc(sizeof(struct lista));
	struct lista *aux;

	if(novo)
	{
		novo->valor = x;
		novo->prox = NULL;

		//se for o primeiro
		if (*atual == NULL)
		{
			novo->ant = NULL;
			*atual = novo;
		} else {

			aux = *atual;

			while (aux->prox != NULL)
			{
				aux = aux->prox;
			}
			novo->ant = aux;
			aux->prox = novo;
			// aux = aux->prox;
		} 



	} else 
		printf("nao alocado\n\n");

}

int main () 
{
    struct lista *L = NULL;
    struct lista *p = NULL;
	
	fim(&L, 4);
	fim(&L, 3);
	fim(&L, 2);
	fim(&L, 1);
	fim(&L, 0);
		
	
	while( L )
	{
		printf("[%i]->", L->valor);
		if (L->prox==NULL)
			break;
		L = L->prox;
	}	
	printf("\n");
	printf("\n");

	while( L != NULL)
	{
		printf("[%i]->", L->valor);
		if (L->ant ==NULL)
			break;
		L = L->ant;
	}	
	printf("aqui\n");
	printf("\n");

    return 0;
}