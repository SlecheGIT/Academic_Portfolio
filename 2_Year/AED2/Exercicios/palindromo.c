#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista
{
    
	struct lista *ant; // n ta funcionando 
	char c;
	struct lista *prox;
}lista;

void inserir(struct lista **atual, int x){
	struct lista *novo = malloc(sizeof(struct lista));
	struct lista *aux;

	if(novo)
	{
		novo->c = x;
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

bool palindromo(lista **inicio, lista **final) {

    lista *ini = *inicio, *fim = *final;
    bool teste = false;

        printf("%c", (*final)->c);
        printf("aquii");
    if (ini->c == fim->c) 
    {

        teste = true;
        if ((ini->prox != fim) && (ini != fim))
        {
            teste = palindromo(&ini->prox, &fim->ant);
        }
    }
        return teste;
    
}
int main (){

    struct lista *L = NULL;
    struct lista *p = NULL;
    bool teste = false;
    
    inserir(&L, 'n');
	inserir(&L, 'a');
	inserir(&L, 'a');
	inserir(&L, 'n');
	// inserir(&L, 0);

	p = L;
    while( p )
	{
		printf("[%c]->", p->c);
		if (p->prox==NULL)
			break;
		p = p->prox;
	}	
	printf("\n");
	printf("\n");

    p = L->ant;

    teste = palindromo(&L, &p);
    if (teste)
    {
        printf("true");
    } else
        printf("false");
    
    return 0;
}