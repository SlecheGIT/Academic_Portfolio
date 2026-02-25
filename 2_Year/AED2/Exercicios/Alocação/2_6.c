/*
(2.8) Apresentar os algoritmos de inserção e remoção numa lista circular encadeada.
*/
#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int valor;
	struct lista *prox;
};

void insere(struct lista **atual, int x)
{
	struct lista *novo = malloc(sizeof(struct lista));
	struct lista *ultimo;
	struct lista *aux;

	if(novo)
	{
		novo->valor = x;

		//se for o primeiro
		if (*atual == NULL)
		{
			*atual = novo;
		    (*atual)->prox = *atual;
		} else {

			aux = *atual;

			while (aux->prox != *atual){
                ultimo = aux;
				aux = aux->prox;
            }
            
            novo->prox = *atual;
			ultimo->prox = novo;
		} 
	} else 
		printf("nao alocado\n\n");

}

int main()
{
	struct lista *L = NULL;
	struct lista *p;
	
	insere(&L, 4);
	insere(&L, 3);
	insere(&L, 2);
	insere(&L, 1);
	insere(&L, 0);
		
	p = L;
    int i=0;
    printf("print\n");
	while( i!=8 )
	{
		printf("[%i]->", p->valor);
		p = p->prox;
        i++;
	}	
	
	printf("\n");
	
	return 0;
}