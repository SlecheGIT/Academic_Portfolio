#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct dupla
{
    int x; 
    struct dupla *ant;
    struct dupla *prox;
} dupla;

void suspender () {

    sleep(3);
}
void clear() { // criada para melhor visualização
    system("cls");
}

void lines() { // criada para melhor visualização
    printf("\n---------------------------\n"); // projeta o cabeçalho de resposta
}

int submenu(int var) 
{ 
    int loop = 0;
    printf("[Escolha a operacao]\n\n");
    printf(" (1) - Inserção\n");
    if (var <= 3) {
        printf(" (2) - Busca\n");
        printf(" (3) - Remoção\n");
    }
    else 
        printf(" (2) - Remoção\n");
    printf(" (0) - Sair\n -> ");
    scanf(" %d", &loop);
    printf("\n");

    return loop; 
}

// funçoes da lista duplamente encadeada {
void inserir_dupla(dupla **head) { //lista com inserção no final

    dupla *novo = malloc(sizeof(dupla));
    dupla *p;

    if (novo)
    {
        printf("Insira um novo valor: ");
        scanf(" %d", &novo->x);
        novo->prox = NULL;

        p = *head;
        while (p->prox != NULL) // avança ate encontrar o fim da lista
            p = p->prox;
        
        if (p->prox == NULL) //coloca o novo nó no apos o ultimo da lista
        {
            novo->ant = p;
            p->prox = novo;
        }
        clear();
    } else
        printf("\n [Erro ao alocar] \n\n");
}

void buscar_dupla(dupla **head) {
    
    dupla *p = *head;
    int busca, indice = 0;

    printf("Insira o valor que deseja buscar: ");
    scanf(" %d", &busca);
    clear();
    lines();

    while (busca != p->x && p->prox != NULL) //avança ate a primeira ocorrencia
    {
        p = p->prox;
        indice++;
    }
    if (busca == p->x && p != *head)
    {
        printf("O valor (%d) foi encontrado!", busca); // da inicio ao "cabeçalho"

        while (p != NULL) // verifica os outros valores até o final da lista
        { 
            if (busca == p->x)
                printf("\nposição: %d° nó", indice);

            p = p->prox;
            indice++;
        }
    }
    else 
        printf("Valor não contido na lista!");
    
    lines();
}

void remover_dupla(dupla **head) {

    dupla *p = *head;
    dupla *aux;
    int busca, indice = 0;

    printf("Insira o valor que deseja remover: ");
    scanf(" %d", &busca);
    clear();
    lines();

    while (busca != p->x && p->prox != NULL) // avança ate o nó que precisa ser removido
    {
        p = p->prox;
        indice++;
    }

    if (busca == p->x && p != *head)
    {
        if (p->prox != NULL) // se for o meio da lista ele interliga os ponteiros:
        {
            aux = p->ant; //aux retrocede o p
            aux->prox = aux->prox->prox; // o p é pulado e avança para o proximo valor
            aux = p->prox; // aux avança o p
            aux->ant = aux->ant->ant; // novamente o p é pulado mas retrocedendo
        } 
        else
        {
            aux = p->ant; //aux retrocede o p
            aux->prox = NULL; // aux se torna o final da lista
        }
        free(p); // em todos os casos o p continua sendo o valor a ser desalocado

        if ((*head)->prox != NULL) // verifica se a lista não se tornou vazia
            printf("O valor (%d) foi removido!\
                    \nposição: %d° nó", busca, indice);
        else //caso contrario notifica ao usuario
            printf("O valor (%d) foi removido!\
                    \n  -Lista esvaziada", busca);
    }
    else
        printf("Esse número não esta contido na lista!");

    lines();
}

void desalocar_dupla(dupla **head) {

    dupla *p = *head;

    while (p->prox != NULL)
    {
        p = p->prox;
        free(p->ant);
    }

    free(p);
    *head = NULL;
}

void imprimir_dupla(dupla *head)
{
    dupla *percursor = head;
    while (percursor)
    {
        printf("-> %d ", percursor->x);
        percursor = percursor->prox;
    }
    printf("\n");
}

void insertion(dupla **head)
{
    dupla *percursor = (*head)->prox->prox;
    dupla *ant = NULL, *aux = NULL, *prox = NULL;

    while (percursor != NULL)
    {
        prox = percursor;
            imprimir_dupla(*head);
        do
        {
            ant = prox->ant;
            if ((prox->x < ant->x) && (ant != *head))
            {
                aux = ant->ant;
                aux->prox = prox;
                prox->ant = aux;

                ant->prox = prox->prox;
                ant->ant = prox;
                prox->prox = ant;
                
            }
        } while ((prox->x < ant->x) && (ant != *head));
        percursor = percursor->prox;
        
    }
    
}

int main ()
{
    dupla *dupla_ini = malloc(sizeof(dupla)); 
    dupla_ini->ant = NULL; 
    dupla_ini->prox = NULL; 
    int loop;

    do {
        printf("\n  (Lista dupla)\n");
        loop = submenu(3);

        switch (loop)
        {
        case 1:
            inserir_dupla(&dupla_ini);
            break;
        
        case 2:
            // (dupla_ini->prox) verifica o proximo da cabeça para saber se a lista esta vazia
            if (dupla_ini->prox != NULL)  
                buscar_dupla(&dupla_ini);
            
            else {
                clear();
                printf(" [ Lista Vazia! ] \n\n");
            }
            break;

        case 3:
            if (dupla_ini->prox != NULL) 
            {
                remover_dupla(&dupla_ini);
            } 
            else {
                clear();
                printf(" [ Lista Vazia! ] \n\n");
            }
            break;
        case 4:
            insertion(&dupla_ini);
            break;
        case 0:
            desalocar_dupla(&dupla_ini); // a cabeça tambem é desalocada
            printf("Saindo. . .\n\n");
            break;
        
        default:
            clear();
            printf("Opção invalida!\n");
            break;
        }   
        imprimir_dupla(dupla_ini);
    } while (loop != 0);

    return EXIT_SUCCESS;
}