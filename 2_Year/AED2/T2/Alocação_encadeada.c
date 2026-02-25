#include "gfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>


// criação das listas {
typedef struct simples // encadeamento simples, usado nas listas: simplesmente encadeada, circular, fila e pilha
{
    int x; // x = valor digitado pelo usuario
    struct simples *proximo;

} simples;

typedef struct dupla // encadeamento duplo, utilizado nas listas: duplamente encadeada
{
    struct dupla *ant;
    int x; // x = valor digitado pelo usuario
    struct dupla *prox;
} dupla;
//}


// funçoes do menu{
void suspender () {

    sleep(3);
}
void clear() { // criada para melhor visualização
    system("clear");
}

void lines() { // criada para melhor visualização
    printf("\n---------------------------\n"); // projeta o cabeçalho de resposta
}

int menu_inicial () {

    int choise;
    printf("Qual a estrutura de dados que sera utilizada?\n\n");
    printf("(1) - lista simplesmente encadeada sem nó cabeca\n      (ordenada)\n\n");
    printf("(2) - lista circular simplesmente encadeada sem nó cabeca\n      (ordenada)\n\n");
    printf("(3) - lista duplamente encadeada com nó cabeca\n      (sem ordenacao)\n\n");
    printf("(4) - Inserção e remoção em fila\n      (FIFO)\n\n");
    printf("(5) - Inserção e remoção em pilha\n      (LIFO)\n\n");
    printf("(0) - Fechar o programa\n--> ");
    scanf("%d", &choise);
    clear();

    return choise;
}

int submenu(int var) { // var = variação, se var <= 3 então são as 3 listas inicias

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
//}


// funçoes da lista simplesmente encadeada {
void inserir_simples(simples **inicio) {

    simples *novo = malloc(sizeof(simples));
    simples *anterior; // variavel auxiliar 
    simples *p; // variavel para percorrer a lista

    if (novo)
    {
        printf("Insira um novo valor: ");
        scanf(" %d", &novo->x);

        if (*inicio == NULL) // verifica se é o primeiro nó
        {
            novo->proximo = NULL;
            *inicio = novo;

        } else {

            p = *inicio;
            if (novo->x <= p->x) // se x for menor que o inicio ele se torna o inicio
            {
                novo->proximo = p;
                *inicio = novo;

            } else { // senão avança ate que x seja menor que o nó verificado ou que esteja no fim da lista
                
                while ((novo->x > p->x) && (p->proximo != NULL))
                {
                    anterior = p;
                    p = p->proximo;
                }

                if (novo->x <= p->x) { // o novo valor entra quando ele for menor que alguem

                    novo->proximo = p;
                    anterior->proximo = novo;

                } else if ((p->proximo == NULL)) { // se for o maior ele entra no final da fila

                    novo->proximo = NULL;
                    p->proximo = novo;
                    
                } 
            }
        }
        clear();
    } else
        printf("\n [Erro ao alocar] \n\n");
}

void buscar_simples(simples **inicio) {

    simples *p = *inicio;
    int busca, indice = 1; 

    
    printf("Insira o valor que deseja buscar: ");
    scanf(" %d", &busca);
    clear();
    lines();

    while (busca != p->x && p->proximo != NULL) { // percorre a lista até encontrar o valor ou nulo

        p = p->proximo;
        indice++;
    }
    
    if (busca == p->x )
    {
        printf("O valor (%d) foi encontrado!", p->x);

        while (busca == p->x) // verifica os proximos valores ate encontrar um diferente para casos de repetição
        {
            printf("\nposição: %d° nó", indice);
            indice++;
            if (p->proximo != NULL)
                p = p->proximo;
            else
                break;
        }
    }
    else
        printf("Valor não contido na lista!");

    lines();
}

void remover_simples(simples **inicio) {

    simples *p = *inicio;
    simples *anterior; // variavel auxiliar para remoção
    int busca, indice = 1; 
    
    printf("Insira o valor que deseja remover: ");
    scanf(" %d", &busca);
    clear();
    lines();

    // o metodo da remoção se altera dependendo do valor estar no começo, meio ou fim

    if (busca == p->x) // começo: 
    {   
        if (p->proximo != NULL) // caso a lista continue altera o primeiro nó
        {
            *inicio = p->proximo;
            free(p);
            printf("O valor (%d) foi removido!\n", busca);
            printf("posição: %d° nó", indice);
        }
        else 
        {   // esvazia a lista se ela apenas conter 1 elemento
            *inicio = NULL;
            free(p);
            printf("O valor (%d) foi removido!\n", busca);
            printf("  -Lista esvaziada");
        }
    }
    else //meio:
    {
        while ((busca != p->x) && (p->proximo != NULL)) { // percorre ate encontrar o valor ou o fim

            anterior = p;
            p = p->proximo;
            indice++;
        }
        
        if ((busca == p->x)) 
        {
            if (p->proximo != NULL)
                anterior->proximo = p->proximo; // pula o nó que sera excluido
            else //fim:
                anterior->proximo = NULL; // determina o fim da lista

            free(p); // p sempre fica com o nó que sera removido
            printf("O valor (%d) foi removido!\n", busca);
            printf("posição: %d° nó", indice);
        }
        else 
            printf("Valor não contido na lista!");
    }
    lines();
}

void imprimir_simples(simples **inicio) {

    simples *p = *inicio;
    int x1 = 20 ,y1 = 20, x2 = 100, y2 = 60;
    int y_seta = 40; // o eixo y da seta permanece em valor constante
    char text[20];
    
    gfx_init(1220, 80, "Lista simplesmente encadeada"); // tamanho do terminal externo 
    //(cabendo 12 nós)
    //(4 caracteres cada nó)
    gfx_set_font_size(25); // tamanho da fonte

    do {

        sprintf(text, "%d", p->x); // transcreve o valor para uma string
        gfx_text( x1+10, 25 , text); // escreve a string na tela (cabendo no maximo 4 caracteres corretamente)

        gfx_rectangle(x1, y1, x2, y2); // gera o retangulo do nó
        gfx_line(x2-5, y1, x2-5, y2); // gera os quadradinhos para representar a seta para o proximo endereço


        gfx_line(x1-15, y_seta, x1-5, y_seta); // gera as 3 linhas que compoem uma seta 
        gfx_line(x1-8, y_seta+3, x1-5, y_seta); 
        gfx_line(x1-8, y_seta-3, x1-5, y_seta); //calculo de coordenadas realizado com o geogebra ;)

        x1 += 100; 
        x2 += 100; 
        // 100 = espaço necessario para distanciar o proximo quadrado

        p = p->proximo;

    } while (p != NULL);
    gfx_paint();
    suspender();
    // gfx_quit();
}

void desalocar_simples(simples **inicio) {

    simples *p = *inicio;
    simples *remove;

    while (p->proximo != NULL)
    {
        remove = p;
        p = p->proximo;
        free(remove);
    }

    free(p);
    *inicio = NULL;  
}
//}


// funçoes da lista circular {
void inserir_circular(simples **inicio) {

    simples *novo = malloc(sizeof(simples));
    simples *anterior;
    simples *p;

    if (novo)
    {
        printf("Insira um novo valor: ");
        scanf(" %d", &novo->x);
        
        if (*inicio == NULL) //inicializa a lista
        {
            *inicio = novo;
            novo->proximo = *inicio;

        } 
        else 
        {
            p = *inicio;
            if (novo->x <= p->x) { // se novo for menor que o primeiro nó, ele se torna o primeiro

                novo->proximo = p;
                while (p->proximo != *inicio) // avança ate o ultimo
                    p = p->proximo;
                *inicio = novo; // ajusta quem é o primeiro nó
                p->proximo = *inicio;

            } 
            else {
                
                while ((novo->x > p->x) && (p->proximo != *inicio)) //senão avança ate que novo seja menor ou o ultimo nó
                    anterior = p, p = p->proximo;
                
                if (novo->x <= p->x) // se ele for menor que algum elemento, entra atrás dele
                {
                    novo->proximo = p;
                    anterior->proximo = novo;
                }
                else if ((p->proximo == *inicio)) // senão vira o fim da lista
                {
                    novo->proximo = *inicio;
                    p->proximo = novo;
                } 
            }
        }
        clear();
    } else
        printf("\n [Erro ao alocar] \n\n");
}

void buscar_circular(simples **inicio) {
    
    simples *p = *inicio;
    int busca, indice = 1; 

    printf("Insira o valor que deseja buscar: ");
    scanf(" %d", &busca);
    clear();
    lines();

    while (busca != p->x && p->proximo != *inicio) // avança ate encontrar
    {
        p = p->proximo;
        indice++;
    }

    if (busca == p->x )
    {
        printf("O valor (%d) foi encontrado!", p->x);

        while (busca == p->x) // verifica os proximos valores ate encontrar um diferente para casos de repetição
        {
            printf("\nposição: %d° nó", indice);
            indice++;
            if (p->proximo != *inicio) // enquanto for igual avança a lista
                p = p->proximo;
            else    
                break; //se retornar ao começo  encerra o loop
        }
    }
    else
        printf("Esse número não esta contido na lista!");
    lines();
}

void remover_circular(simples **inicio) {

    simples *p = *inicio;
    simples *remove = p;
    int busca, indice = 1; 

    printf("Insira o valor que deseja remover: ");
    scanf(" %d", &busca);
    clear();
    lines();

    if (busca == p->x) // em caso do primeiro ja for o que sera excluido
    {
        if (p->proximo != *inicio) // verificar se a lista não tem apenas um nó
        {
            while (p->proximo != *inicio)
                p = p->proximo;
            
            *inicio = (*inicio)->proximo;
            p->proximo = *inicio;
            
            printf("O valor %d foi removido!\n", busca);
            printf("posição: %d° nó ", 1);
        } 
        else //se a lista tiver um nó, esvaziar novamente
        {
            *inicio = NULL;
            printf("O valor (%d) foi removido!\n", busca);
            printf("  -Lista esvaziada");
        }
        free(remove); // o nó que sera removido sempre é o remove
    }
    else
    {
        while (busca != remove->x && remove->proximo != *inicio)
        {
            p = remove; // p usado como anterior
            remove = remove->proximo;
            indice++;
        }

        if (busca == remove->x )
        {
            if (remove->proximo != *inicio)
                p->proximo = remove->proximo; // pula o nó que sera apagado
            else
                p->proximo = *inicio; // reajusta o fim da lista
            
            printf("O valor (%d) foi removido!\n", busca);
            printf("posição: %d° nó", indice);

            free(remove); // o nó que sera removido sempre é o remove
        }
        else
            printf("Esse valor não esta contido na lista!");
    }
    lines();
}

void imprimir_circular(simples **inicio) {

    simples *p = *inicio;
    int x1 = 20 ,y1 = 20, x2 = 100, y2 = 60;
    int y_seta = 40; // o eixo y da seta permanece em valor constante
    char text[20];
    
    gfx_init(1220, 80, "Lista circular simplesmente encadeada"); // tamanho do terminal externo 
    //(cabendo 12 nós)
    //(4 caracteres cada nó)
    gfx_set_font_size(25); // tamanho da fonte

    do {

        sprintf(text, "%d", p->x); // transcreve o valor para uma string
        gfx_text( x1+10, 25 , text); // escreve a string na tela (cabendo no maximo 4 caracteres corretamente)

        gfx_rectangle(x1, y1, x2, y2); // gera o retangulo do nó
        gfx_line(x2-5, y1, x2-5, y2); // gera os quadradinhos para representar a seta para o proximo endereço


        gfx_line(x1-15, y_seta, x1-5, y_seta); // gera as linhas das setas 
        gfx_line(x1-8, y_seta+3, x1-5, y_seta); 
        gfx_line(x1-8, y_seta-3, x1-5, y_seta);

        x1 += 100; 
        x2 += 100; 
        // 100 = espaço necessario para distanciar o proximo quadrado

        p = p->proximo;

    } while (p != *inicio);

    gfx_line(x1-15, y_seta, x1-5, y_seta); 
    gfx_line(x1-8, y_seta-3, x1-5, y_seta); 
    gfx_line(x1-8, y_seta+3, x1-5, y_seta); 

    gfx_rectangle(x1, y1, x2, y2); // gera o ultimo quadrado que volta para o inicio

    sprintf(text, "%d", p->x);
    gfx_text( x1+10, 25 , text); 

    gfx_set_font_size(15); // regula a fonte
    gfx_text( x1+25, 2 , "Inicio"); 

    gfx_paint();
    suspender();
    gfx_quit();
}

void desalocar_circular(simples **inicio) {

    simples *p = (*inicio)->proximo;
    simples *remove;

    while (p->proximo != *inicio)
    {
        remove = p;
        p = p->proximo;
        free(remove);
    }

    free(p);
    free(*inicio);
    *inicio = NULL;  
}
//}


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

void imprimir_dupla(dupla **head) { // função usada para imprimir a lista simples e a fila

    dupla *p = *head;
    int x1 = 20 ,y1 = 20, x2 = 100, y2 = 60;
    int y1_seta = 30;
    int y2_seta = 50;
    char text[20];
    
    gfx_init(1220, 80, "Lista Duplamente encadeada");
    gfx_set_font_size(25);

    do {
        gfx_line(x1+5, y1, x1+5, y2);
        gfx_rectangle(x1, y1, x2, y2);
        gfx_line(x2-5, y1, x2-5, y2);

        if (p != *head) 
        {
            sprintf(text, "%d", p->x);
            gfx_text( x1+10, 25 , text);

            gfx_line(x1-5, y1_seta, x1-15, y1_seta);
            gfx_line(x1-5, y1_seta, x1-8, y1_seta-3);
            gfx_line(x1-5, y1_seta, x1-8, y1_seta+3);
            
            
            gfx_line(x1-5, y2_seta, x1-15, y2_seta);
            gfx_line(x1-12, y2_seta-3, x1-15, y2_seta);
            gfx_line(x1-12, y2_seta+3, x1-15, y2_seta);    
        }
        else 
        {
            gfx_text( x1+10, 25 , "head");

            gfx_line(x1-15, y1_seta+10, x1-5, y1_seta+10);
            gfx_line(x1-8, y1_seta+13, x1-5, y1_seta+10);
            gfx_line(x1-8, y1_seta+7, x1-5, y1_seta+10);
        }
        x1 += 100;
        x2 += 100;
        p = p->prox;

    } while (p != NULL);
    gfx_paint();
    suspender();
    gfx_quit();
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
//}


// funçoes da lista fila e pilha {
void inserir_fila(simples **inicio) { //entra no começo e sai no final

    simples *novo = malloc(sizeof(simples));

    if (novo)
    {
        printf("insira um novo valor: ");
        scanf(" %d", &novo->x);

        if (*inicio == NULL) // inicializa o primeiro nó
        {
            novo->proximo = NULL;
            *inicio = novo;
        }
        else // adiciona os novos no inicio da fila
        {
            novo->proximo = *inicio;
            *inicio = novo;
        }
        clear();
    } else
        printf("\n [Erro ao alocar] \n\n");
}

void inserir_pilha(simples **inicio) { // entra no fim e sai no final
    
    simples *novo = malloc(sizeof(simples));
    simples *p;

    if (novo)
    {
        printf("Insira um novo valor: ");
        scanf(" %d", &novo->x);
        novo->proximo = NULL;

        if (*inicio == NULL) // inicializa a primeira ocorrencia
            *inicio = novo;
        
        else {

            p = *inicio;
            while (p->proximo != NULL) // avança ate o ultimo nó
                p = p->proximo;
            
            if (p->proximo == NULL)
                p->proximo = novo; //insere no final
        }
        clear();
    } else
        printf("\n [Erro ao alocar] \n\n");
}

void imprimir_fila(simples **inicio) {

    simples *p = *inicio;
    int x1 = 20 ,y1 = 20, x2 = 100, y2 = 60;
    int y_seta = 40; // o eixo y da seta permanece em valor constante
    char text[20];

    gfx_init(1220, 80, "Fila (FIFO)"); // tamanho do terminal externo 
    //(cabendo 12 nós)
    //(4 caracteres cada nó)
    gfx_set_font_size(25); // tamanho da fonte

    do {

        sprintf(text, "%d", p->x); // transcreve o valor para uma string
        gfx_text( x1+10, 25 , text); // escreve a string na tela (cabendo no maximo 4 caracteres corretamente)

        gfx_rectangle(x1, y1, x2, y2); // gera o retangulo do nó
        gfx_line(x2-5, y1, x2-5, y2); // gera os quadradinhos para representar a seta para o proximo endereço


        gfx_line(x1-15, y_seta, x1-5, y_seta); // gera as 3 linhas que compoem uma seta 
        gfx_line(x1-8, y_seta-3, x1-5, y_seta); 
        gfx_line(x1-8, y_seta+3, x1-5, y_seta); 

        x1 += 100; 
        x2 += 100; 
        // 100 = espaço necessario para distanciar o proximo quadrado

        p = p->proximo;

    } while (p != NULL);

    // gerar seta final por ser uma fila para mostrar a direção de saida
    gfx_line(x1-15, y_seta, x1-5, y_seta);
    gfx_line(x1-8, y_seta-3, x1-5, y_seta); 
    gfx_line(x1-8, y_seta+3, x1-5, y_seta); 

    gfx_paint();
    suspender();
    gfx_quit();
}

void imprimir_pilha(simples **inicio) {

    simples *p = *inicio;
    int x1 = 30 ,y1 = 620, x2 = 110, y2 = 660;
    int x_seta = 70; // o eixo y da seta permanece em valor constante
    char text[20];

    gfx_init(140, 680, "Pilha"); // tamanho do terminal externo 
    //(o terminal cabe 11 nós)
    //(pode armazenar ate 6 caracteres corretamente)
    gfx_set_font_size(25); // tamanho da fonte

    do {
        sprintf(text, "%d", p->x); // transcreve o valor para uma string
        gfx_text( x1+5, y1+8 , text); // escreve a string na tela (cabendo no maximo 4 caracteres corretamente)

        gfx_rectangle(x1, y1, x2, y2); // gera o retangulo do nó
        gfx_line(x1, y1+5, x2, y1+5); // gera os quadradinhos para representar a seta para o proximo endereço

        gfx_line(x_seta, y2+15, x_seta, y2+5); // gera as 3 linhas que compoem uma seta 
        gfx_line(x_seta, y2+15, x_seta+3, y2+12); 
        gfx_line(x_seta, y2+15, x_seta-3, y2+12); // eixos invertidos das impressoes normais

        y1 -= 60; 
        y2 -= 60; 
        // 60 = espaço necessario para distanciar o proximo quadrado

        p = p->proximo;

    } while (p != NULL);

    gfx_paint();
    suspender();
    gfx_quit();
}

void remover_fila_ou_pilha(simples **inicio, char tipo) { // tanto a fila quanto a pilha saem pelo fim

    simples *p = *inicio;
    simples *anterior;
    clear();
    lines();

    if ((*inicio)->proximo != NULL) // verifica se tem mais de 1 argumento na lista
    {
        while (p->proximo != NULL) // avança ate o fim
        {
            anterior = p;
            p = p->proximo;
        }
        anterior->proximo = NULL; // retira o ultimo argumento

        if (tipo == 'f')
            printf("Valor (%d) foi removido da fila!", p->x);

        else if (tipo == 'p')
            printf("Valor (%d) foi removido da pilha!", p->x);
    }
    else //se restar apenas 1 argumento limpar o ponteiro
    {
        *inicio = NULL;
        if (tipo == 'f'){
            printf("Valor (%d) foi removido da fila!\n", p->x);
            printf("  -Fila esvaziada");
        }
        else if (tipo == 'p'){
            printf("Valor (%d) foi removido da pilha!\n", p->x);
            printf("  -Pilha esvaziada");
        }
    }
    
    free(p); // p ficou com o endereço que foi retirado e foi desalocado
    lines();
}
//}


int main () {

    setlocale(LC_ALL, "Portuguese_Brazil");
    simples *simples_ini = NULL; // variavel usada nas listas simplesmente encadeada, fila e pilha
    simples *circular_ini = NULL; // variavel usada na lista circular
    dupla *dupla_ini = malloc(sizeof(dupla)); //variavel usada na duplamente encadeada
    dupla_ini->ant = NULL; 
    dupla_ini->prox = NULL; //sinalizando a cabeça como vazia
    int choise = menu_inicial();
    int loop;

    //          todos os casos funcionam de maneira semelhante 
    // comentarei o primeiro com mais detalhes e a diferença dos demais!

    switch (choise) 
    {
    case 1: /*--------------------------------------------*/
        do
        {
            printf("\n  (Lista simples)\n");
            loop = submenu(1); // recebe a escolha do usuario

            switch (loop)
            {
            case 1:
                inserir_simples(&simples_ini);
                if (simples_ini != NULL) // não imprimi caso a inserção de algum erro
                    imprimir_simples(&simples_ini);
                break;

            case 2:
                if (simples_ini != NULL) // verifica se a lista é vazia antes de chamar a função
                    buscar_simples(&simples_ini);

                else {
                    clear();
                    printf(" [ Lista Vazia! ] \n\n");
                }
                break;

            case 3:
                if (simples_ini != NULL) // verifica se a lista é vazia antes de chamar a função
                {
                    remover_simples(&simples_ini);
                    if (simples_ini != NULL) // a mesma verificação pois a lista pode esvaziar ao remover
                        imprimir_simples(&simples_ini);
                }
                else {
                    clear();
                    printf(" [ Lista Vazia! ] \n\n");
                }
                break;

            case 0:
                if (simples_ini != NULL) // se a lista não for vazia ele desaloca os nó(s) restantes
                    desalocar_simples(&simples_ini);
                printf("Saindo. . .\n\n");
                break;
            
            default:
                clear();
                printf("Opção invalida!\n");
                break;
            }
        } while (loop != 0);
        break;

    case 2: /*--------------------------------------------*/
        do
        {
            printf("\n  (Lista circular)\n");
            loop = submenu(2);

            switch (loop)
            {
            case 1:
                inserir_circular(&circular_ini);
                if (circular_ini != NULL) // em caso de erro de alocação
                    imprimir_circular(&circular_ini);
                break;

            case 2:
                if (circular_ini != NULL) 
                    buscar_circular(&circular_ini);
                else {
                    clear();
                    printf(" [ Lista Vazia! ] \n\n");
                }
                break;

            case 3:
                if (circular_ini != NULL) 
                {
                    remover_circular(&circular_ini);
                    if (circular_ini != NULL)  // caso o usuario esvazie a lista
                        imprimir_circular(&circular_ini);
                } 
                else {
                    clear();
                    printf(" [ Lista Vazia! ] \n\n");
                }
                break;

            case 0:
                printf("Saindo. . .\n\n");
                break;
            
            default:
                clear();
                printf("Opção invalida!\n");
                break;
            }   
        } while (loop != 0);
        
        break;

    case 3: /*--------------------------------------------*/
        do
        {
            printf("\n  (Lista dupla)\n");
            loop = submenu(3);

            switch (loop)
            {
            case 1:
                inserir_dupla(&dupla_ini);
                if (dupla_ini->prox != NULL) // em caso de erro de alocação
                    imprimir_dupla(&dupla_ini);
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
                    if (dupla_ini->prox != NULL) // em caso de lista esvaziada pelo usuario
                        imprimir_dupla(&dupla_ini);
                } 
                else {
                    clear();
                    printf(" [ Lista Vazia! ] \n\n");
                }
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
        } while (loop != 0);

        break;

    case 4: /*--------------------------------------------*/
        do
        {
            printf("\n (Lista em Fila)\n\n");
            loop = submenu(4);

            switch (loop)
            {
            case 1:
                inserir_fila(&simples_ini);
                if (simples_ini != NULL) // em caso de erro de alocação
                    imprimir_fila(&simples_ini);
                break;

            case 2:
                if (simples_ini != NULL) 
                {
                    remover_fila_ou_pilha(&simples_ini, 'f');
                    if (simples_ini != NULL) //caso a lista seja esvaziada pelo usuario
                        imprimir_fila(&simples_ini);
                }
                else {
                    clear();
                    printf(" [ Lista Vazia! ] \n\n");
                }
                break;

            case 0:
                if (simples_ini != NULL)
                    desalocar_simples(&simples_ini); // as listas funcionam de mesmo modo, então usarei a mesmo função
                printf("Saindo...\n\n");
                break;
            
            default:
                clear();
                printf("Opção invalida!\n");
                break;
            }
        } while (loop != 0);
        break;

    case 5: /*--------------------------------------------*/
        do
        {
            printf("\n (Lista em Pilha)\n");
            loop = submenu(5);

            switch (loop)
            {
            case 1:
                inserir_pilha(&simples_ini);
                if (simples_ini != NULL)
                        imprimir_pilha(&simples_ini);
                break;

            case 2:
                if (simples_ini != NULL) 
                {
                    remover_fila_ou_pilha(&simples_ini, 'p');
                    if (simples_ini != NULL)
                        imprimir_pilha(&simples_ini);
                } 
                else {
                    clear();
                    printf(" [ Lista Vazia! ] \n\n");
                }
                break;

            case 0:
                if (simples_ini != NULL)
                    desalocar_simples(&simples_ini);
                printf("Saindo. . .\n\n");
                break;
            
            default:
                clear();
                printf("Opção invalida!\n");
                break;
            }
        } while (loop != 0);
        break;
    
    case 0:
        printf("\n\nfinalizando programa. . .\n");
    break;
    
    default:
        clear();
        printf("Entrada invalida!\n\n");
        break;
    }
    return 0;
}