#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int x;
    struct lista *prox;
}lista;

void inserir(lista **atual, int x){
	lista *novo = malloc(sizeof(lista));
	lista *aux;

	if(novo)
	{
		novo->x = x;
		novo->prox = NULL;

		//se for o primeiro
		if (*atual == NULL)
		{
			*atual = novo;
		} else {

			aux = *atual;

			while (aux->prox != NULL)
				aux = aux->prox;
			
			aux->prox = novo;
		} 
	} else 
		printf("nao alocado\n\n");
}

void juntar(lista **A, lista **B, lista **D){
    lista *d = *A, *b = *B, *inicio = d;

    if (d == NULL)
    {
        printf("falso");
    }
    
    while (d->prox != NULL)
        d = d->prox;
    
    d->prox = b;

    *D = inicio;

}

void ordenar(lista **A, lista **B, lista **D){
    lista *d = malloc(sizeof(lista));
    lista *a = *A, *b = *B, *anterior;

    if (*D == NULL){
        d->x = a->x;
        d->prox = NULL;
        a = a->prox;
    }
    lista *inicio = d;
    do
    {
    printf("\n\nAQUIII\n\n");
        if (a->x < d->x)
        {
            a->prox = d;
            inicio = a;
        } else 
        {
            while (a->x > d->x && d->prox != NULL)
            {
                anterior = d;
                d = d->prox;
            }
            if (d->prox == NULL)
            {
                d->prox = a;
                a->prox = NULL;
            } else {

                anterior->prox = a;
                a->prox = d;
            }
        }
        

        d = inicio;
        a = a->prox;
    } while (a->prox != NULL);
    
    
    *D = d;
    
}

int main () {
    lista *A = NULL;
    lista *B = NULL;
    lista *D = NULL;
    lista *Dnada = NULL;
    lista *copy;
    int x;

    printf("insira a lista, 0 para parar\n");
    do {
        scanf("%d", &x);
        inserir(&A , x);
    } while (x != 0);
    printf("insira a lista, 0 para parar\n");
    do {
        scanf("%d", &x);
        inserir(&B , x);

    } while (x != 0);
        
    // printf("apagar: \n");
    // scanf("%d", &x);
    // remover(&inicio, x);

    copy = A;
    printf("\nLista [A] = ");
    while (copy)
    {
        printf("[%d]->", copy->x);
        if (copy->prox == NULL)
            break;
        copy = copy->prox;
    }

    printf("\n");

    printf("\nLista [B] = ");
    copy = B;
    while (copy)
    {
        printf("[%d]->", copy->x);
        if (copy->prox == NULL)
            break;
        copy = copy->prox;
    }
    printf("\n");

    juntar(&A, &B, &D);

    printf("\nLista [D] = ");
    copy = D;
    while (copy)
    {
        printf("[%d]->", copy->x);
        if (copy->prox == NULL)
            break;
        copy = copy->prox;
    }
    printf("\n");

    ordenar(&A, &B, &Dnada);
    
    printf("\nLista [D] ordenada = ");
    copy = Dnada;
    while (copy)
    {
        printf("[%d]->", copy->x);
        if (copy->prox == NULL)
            break;
        copy = copy->prox;
    }
    printf("\n");


}