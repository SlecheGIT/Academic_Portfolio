#include "gfx/gfx.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_no
{
    int32_t chave : 28;
    int32_t bal : 2; // retornar a 2 bits depois
    int32_t reservado : 2; /* sem uso */
    struct s_no *esq;
    struct s_no *dir;
} s_no;

struct s_arq_no
{
    int32_t chave : 28;
    int32_t bal : 2;
    uint32_t esq : 1;
    uint32_t dir : 1;
};

void clear() {
    system("clear");
}
void pausa() {
    system("read -p \"\nPressione (enter) para sair.\" .");
}

// sem utilização
int altura(s_no *raiz);
short calcular_bal(s_no *raiz);
void balancear (s_no **raiz); 
//

//insercao
s_no *novo_no(int x);
void case1(s_no **raiz); // estrutura conforme as aulas
void case2(s_no **raiz); // estrutura conforme as aulas
void ins_AVL(s_no **raiz, int x, int *verifica); // estrutura conforme as aulas

bool busca(s_no *raiz, int x);

//remocao |em ajustes| 
s_no *rotacao_esq(s_no *pai); // rotação desemvolvida indepente antes do case1 
s_no *rotacao_dir(s_no *pai); // rotação desemvolvida indepente antes do case2
s_no *remover(s_no *percursor, int x, int *verifica); //

void imprimir (s_no **percursor, int x, int y, int recursividade);
void carregar( struct s_no **percursor, FILE *arquivo );
void Salvar(s_no *percursor, FILE **arquivo); // em pré ordem, salva AVL dentro de um arquivo
void desalocar (s_no **percursor);


int main()
{
    s_no *raiz = NULL;
    int32_t x;
    int verifica;
    short choise;
    char nome[30];

    gfx_init(1280, 720, "Árvore Binária de Busca");

    do
    {
        printf("\n           | Menu |       \n");
        printf("(1) Inserção de uma chave com valor x\n");
        printf("(2) Remoção de uma chave com valor x\n");
        printf("(3) Busca por uma chave com valor x\n");
        printf("(4) Carregar arvore\n");
        printf("(5) Salvar arvore\n");
        printf("(0) Encerrar programa\n--> ");
        scanf("%hd", &choise);
        clear();

        switch (choise)
        {
        case 1:
            printf("| Inserção de uma chave com valor x |\n");
            printf("insira o novo valor: ");
            scanf(" %d", &x);
            verifica = 0;
            ins_AVL(&raiz, x, &verifica);
            printf("\nValor (%d) Inserido!\n", x);
            break;

        case 2:
            if (raiz != NULL)
            {
                printf("| remoção de uma chave com valor x | \n");
                printf("insira o valor que sera excluido: ");
                scanf(" %d", &x);
                verifica = 0;

                raiz = remover(raiz, x, &verifica);
            }
            break;

        case 3:
            if (raiz != NULL)
            {
                printf("| Busca por uma chave com valor x |\n");
                printf("insira o valor que sera buscado: ");
                scanf("%d", &x);

                if (busca(raiz, x))
                    printf("\nValor (%d) foi encontrado na arvore! \n", x);
                else
                    printf("\nNão esta contido na arvore!\n");
            }
            break;

            case 4:
                printf("| carregar arvore | \n");
                printf("insira apenas o nome do arquivo que deseja abrir (contido nesta pasta): ");
            	scanf("%s", nome);
                strcat(nome, ".bin");

                s_no *percursor = NULL;
                FILE *arquivo;
            	arquivo = fopen(nome, "rb");

            	if(arquivo == NULL)
            		printf("\nArquivo n�o encontrado!\n");

                else
                {
                    percursor = malloc(sizeof(s_no));
                    carregar(&percursor, arquivo);

                    if (raiz != NULL)
                        desalocar(&raiz);
                    raiz = percursor;
                    percursor = NULL;

                    fclose(arquivo);
                    printf("\n[Arvore carregada] arvore antiga foi sobrescrevida!\n");
                }

                nome[0] = '\0';
                break;

            case 5:
                if (raiz != NULL) {
                    printf("| salvar arvore | \n");
                    printf("insira apenas o nome do arquivo que vai salvar (nao repita outros arquivos): ");
                    scanf("%s", nome);
                    strcat(nome, ".bin");

                    FILE *arquivo;
                    arquivo = fopen(nome, "ab");
                    Salvar(raiz, &arquivo);
                    fclose(arquivo);

                    printf("\nArvore foi salva como %s!\n", nome);
                }
                else
                    printf("Arvore vazia\n");
                break;
        
        case 77:
            balancear(&raiz);
            break;
        case 0:
            if (raiz != NULL)
                printf("Desalocando arvore. . .\n");
            else
                printf("Fechando programa. . .\n");
            break;

        default:
            clear();
            printf("Opção invalida!!\n");
            break;
        }

        if (choise != 0)
        {
            imprimir(&raiz, 620, 30, 620);
            pausa();
            clear();
        }

    } while (choise);

    printf("\n");

    if (raiz != NULL)
        desalocar(&raiz);

    gfx_quit();
    return 0;
}
//------------------------------------------------------------------------------------------------------------//

void imprimir (s_no **percursor, int x, int y, int recursividade) {
            // parametros de recursividade para saber a posição do meio da tela
    if (*percursor != NULL)
    {
        char text[20];
        s_no *p;

        if (x == 620)
            gfx_clear();

        gfx_set_color(100, 0, 0);
         //quadrado do balanço
        gfx_set_font_size(15);
        sprintf(text, "%d", (*percursor)->bal);
        gfx_rectangle(x+10, y+40, x+30, y+60);
        gfx_text(x+13, y+42, text);

        gfx_set_color(100, 100, 100);
        //quadrado da chave
        gfx_set_font_size(25);
        sprintf(text, "%d", (*percursor)->chave); // transcreve o valor para uma string
        gfx_rectangle(x, y, x+40, y+40);
        gfx_text(x+5, y+5, text);

        if ((*percursor)->esq != NULL)
        {
            p = (*percursor)->esq;
            gfx_line(x, y+40, (x - (recursividade/2))+20, y+80);
            imprimir(&p, x-(recursividade/2), y+80, recursividade/2);
        }
        if ((*percursor)->dir != NULL)
        {
            p = (*percursor)->dir;
            gfx_line(x+40, y+40, (x+(recursividade/2))+20, y+80);
            imprimir(&p, x+(recursividade/2), y+80,  recursividade/2);
        }
        
        if (x == 620)
            gfx_paint();
    }
    else {
        gfx_clear();
        printf("\nArvore vazia!\n");
        gfx_paint();
    }
}

s_no *novo_no(int x)
{
    s_no *novo = malloc(sizeof(struct s_no));

    novo->chave = x;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->bal = 0;

    return novo;
}

void case1(s_no **raiz)
{
    s_no *ptu = (*raiz)->esq;
    
    if (ptu->bal == -1)
    {
        (*raiz)->esq = ptu->dir;
        ptu->dir = *raiz;
        (*raiz)->bal = 0;
        *raiz = ptu;
    }
    else
    {
        s_no *ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = ptu;
        (*raiz)->esq = ptv->dir;
        ptv->dir = *raiz;

        if (ptv->bal == -1)
            (*raiz)->bal = 1;
        else
            (*raiz)->bal = 0;
        
        
        if (ptv->bal == 1)
            ptu->bal = -1;
        else
            ptu->bal = 0;
        
        *raiz = ptv;

    }
    (*raiz)->bal = 0;
}

void case2(s_no **raiz)
{
     s_no *ptu = (*raiz)->dir;
    
    if (ptu->bal == 1)
    {
        (*raiz)->dir = ptu->esq;
        ptu->esq = *raiz;
        (*raiz)->bal = 0;
        *raiz = ptu;
    }
    else
    {
        s_no *ptv = ptu->esq;
        ptu->esq = ptv->dir;
        ptv->dir = ptu;
        (*raiz)->dir = ptv->esq;
        ptv->esq = *raiz;

        if (ptv->bal == 1)
            (*raiz)->bal = -1;
        else
            (*raiz)->bal = 0;
        
        if (ptv->bal == -1)
            ptu->bal = 1;
        else
            ptu->bal = 0;
        
        *raiz = ptv;
    }
    (*raiz)->bal = 0;
}

void ins_AVL(s_no **raiz, int x, int *verifica) // estrutura conforme as aulas
{
    if (*raiz)
    {
        if (x != (*raiz)->chave)
        {
            if (x < (*raiz)->chave)
            {
                ins_AVL(&((*raiz)->esq), x, verifica);

                if (*verifica){
                    switch ((*raiz)->bal)
                    {
                    case 1:
                        (*raiz)->bal = 0;
                        *verifica = 0;
                        break;

                    case 0:
                        (*raiz)->bal = -1;
                        break;
                    
                    case -1:
                        case1(&(*raiz));
                        *verifica = 0;
                        break;
                    }
                }
            }
            else if (x > (*raiz)->chave)
            {
                ins_AVL(&((*raiz)->dir), x, verifica); 

                if (*verifica)
                {
                    switch ((*raiz)->bal)
                    {
                    case -1:
                        (*raiz)->bal = 0;
                        *verifica = 0;
                        break;

                    case 0:
                        (*raiz)->bal = 1;
                        break;
                    
                    case 1:
                        case2(&(*raiz));
                        *verifica = 0;
                        break;
                    }
                }
            }
        }
        else {
            printf("\nValor ja contido na arvore!\n");
            return;
        }
    }
    else
    {
        *raiz = novo_no(x);
        *verifica = 1;
    }
}


s_no *rotacao_esq(s_no *pai)
{    

    //mudei aqui
    if (pai == NULL || pai->dir == NULL) {
            return pai; // Nenhuma rotação pode ser feita
        }
    //
    s_no *aux1 = pai->dir;

    if ((aux1->bal == 1)) // rotação simples
    {
        pai->dir = aux1->esq;
        aux1->esq = pai;
        // pai->bal = calcular_bal(pai); // tentar tirar
        // pai->bal = 0;
        aux1->bal = 0;
    }
    else //rotação dupla
    {   
        //mudei aqui
        s_no *aux2 = aux1->esq; // O filho esquerdo de 'aux1'

        if (aux2 == NULL) {
                // Não é possível realizar a rotação dupla se 'aux2' é nulo
                return pai;
            }
        //
        //primeira rotacao
        // s_no *aux2 = aux1->esq; sumi com esse 
        aux1->esq = aux2->dir;
        aux2->dir = aux1;

        //balanceamento
        // short bal_reserva = aux2->bal;
        // aux2->bal = aux1->bal * -1;
        // aux1->bal = bal_reserva * -1;

        if (aux2->bal == 1)
            aux1->bal = 0;
        else
            aux1->bal = 1;

        //segunda rotacao
        pai->dir = aux2->esq;
        aux2->esq = pai;

        if (aux2->bal == 1){
            pai->bal = 0;
            aux2->bal = 0;
        }
        else
        {
            pai->bal = 0;
            aux2->bal = 1;
        }

        aux1 = aux2;
    }
    return aux1;
}

s_no *rotacao_dir(s_no *pai)
{
    s_no *aux1 = pai->esq;

    if (aux1->bal == -1) // rotação simples
    {
        pai->esq = aux1->dir;
        aux1->dir = pai;
        // pai->bal = calcular_bal(pai); // tentar tirar
        // pai->bal = 0;
        aux1->bal = 0;
    }
    else //rotação dupla
    {
        //primeira rotacao
        s_no *aux2 = aux1->dir;
        aux1->dir = aux2->esq;
        aux2->esq = aux1;

        //balanceamento
        // short bal_reserva = aux2->bal;
        // aux2->bal = aux1->bal * -1;
        // aux1->bal = bal_reserva * -1;
        if (aux2->bal == 1)
            aux1->bal = 0;
        else
            aux1->bal = 1;

        //segunda rotacao
        pai->esq = aux2->dir;
        aux2->dir = pai;

        if (aux2->bal == -1)
        {
            pai->bal = 0;
            aux2->bal = 0;
        }
        else
        {
            pai->bal = 0;
            aux2->bal = -1;
        }
        aux1 = aux2;
    }
    return aux1;
}

s_no *remover(s_no *percursor, int x, int *verifica)
{
    if (percursor != NULL)
    {
        if (percursor->chave == x) 
        {
            if (percursor->esq == NULL && percursor->dir == NULL) // remoção com nenhum filho
            {
                free(percursor);
                printf("\nnoh (%d) removida! \n", x);
                *verifica = 1;
                return NULL;
            }
            else {
                s_no *aux;
                if (percursor->esq != NULL && percursor->dir != NULL) // remoção com 2 filhos
                { 
                    if (altura(percursor->esq) > altura(percursor->dir))
                    {
                        aux = percursor->esq;
                        while (aux->dir != NULL)
                            aux = aux->dir;
                    }
                    else
                    {
                        aux = percursor->dir;
                        while (aux->esq != NULL)
                            aux = aux->esq;
                    }
                    
                    percursor->chave = aux->chave;
                    aux->chave = x;

                    if (altura(percursor->esq) > altura(percursor->dir))
                        percursor->esq = remover(percursor->esq, x, verifica);
                    else
                        percursor->dir = remover(percursor->dir, x, verifica);
                }
                else { // remocao com apenas 1 filho
                    if (percursor->esq != NULL)
                        aux = percursor->esq;
                    else
                    if (percursor->dir != NULL)
                        aux = percursor->dir;
                    free(percursor);
                    printf("\nnoh (%d) removida! \n", x);
                    *verifica = 1;
                    return aux;
                }   
            }
        }
        else
        {
            if (x < percursor->chave)
                percursor->esq = remover(percursor->esq, x, verifica);
            else
                percursor->dir = remover(percursor->dir, x, verifica);
        }
        
        if (*verifica != 0)
        {
            if (percursor->bal == 0)
            {
                if (percursor->esq == NULL)
                    percursor->bal = 1;
                else 
                if (percursor->dir == NULL)
                    percursor->bal = -1;
                else
                {
                    if (altura(percursor->esq) < altura(percursor->dir))
                        percursor->bal = 1;
                    else
                        percursor->bal = -1;
                }
                *verifica = 0;
            }
            else
            {
                if (percursor->bal == 1)
                {
                        printf("\nteste:%d\n", percursor->chave);
                                            
                    if (x > percursor->chave)
                        percursor->bal = 0;
                    else
                    { 
                        //rotação esquerda
                        if (percursor->dir != NULL)
                            percursor = rotacao_esq(percursor);
                        else
                            percursor->bal = 0;
                    }
                }
                else
                if (percursor->bal == -1)
                {
                    if (x < percursor->chave)
                        percursor->bal = 0;
                    else
                    { 
                        //rotação direita
                         if (percursor->esq != NULL)
                            percursor = rotacao_dir(percursor);
                        else
                            percursor->bal = 0;
                    }
                }
                *verifica = 0;
            }
        }
        return percursor;
    } 
    else
    {
        printf("\nValor nao encontrado!\n");
        return NULL;
    }

}

bool busca(s_no *raiz, int x)
{
    if (raiz != NULL)
    {
        if (x != raiz->chave)
        {
            if (x < raiz->chave)
            {
                if (busca(raiz->esq, x))
                    return true; 
            }
            else
            {
                if (busca(raiz->dir, x))
                    return true; 
            }
            return false;
        }
        else
            return true;
    }
    else
        return false;
    
    
}

void carregar( struct s_no **percursor, FILE *arquivo ){
	struct s_arq_no *AVL_arq = malloc(sizeof(struct s_arq_no));

	if(fread(AVL_arq, sizeof(struct s_arq_no), 1, arquivo)){
		(*percursor)->chave = AVL_arq->chave;
		(*percursor)->bal = AVL_arq->bal;
		
		s_no *NovaFolha;

		if(AVL_arq->esq)
        {
            NovaFolha = NULL;
			NovaFolha = malloc(sizeof(struct s_no));
	        s_no *aux;
			
			(*percursor)->esq = NovaFolha;
			aux = (*percursor)->esq;
			carregar(&aux, arquivo);
		}
		else
			(*percursor)->esq = NULL;

		if(AVL_arq->dir)
        {
            NovaFolha = NULL;
			NovaFolha = malloc(sizeof(struct s_no));
	        s_no *aux;
			
			(*percursor)->dir = NovaFolha;
			aux = (*percursor)->dir;
			carregar(&aux, arquivo);
		}
		else
			(*percursor)->dir = NULL;
	}
	else
		*percursor = NULL;
}

//Salva em arquivo a árvore em pré-ordem.
void Salvar(s_no *percursor, FILE **arquivo) // em pré ordem, salva AVL dentro de um arquivo
{
	struct s_arq_no AVL_arq;

	AVL_arq.chave = percursor->chave;
	AVL_arq.bal = percursor->bal;

	if(percursor->esq) AVL_arq.esq = 1;
	else AVL_arq.esq = 0;

	if(percursor->dir) AVL_arq.dir = 1;
	else AVL_arq.dir = 0;

	fwrite(&AVL_arq, sizeof(struct s_arq_no), 1, *arquivo);

	if(percursor->esq)
		Salvar( percursor->esq, &(*arquivo) );
	if(percursor->dir)
		Salvar( percursor->dir, &(*arquivo) );
}

void desalocar (s_no **percursor) 
{
    if ((*percursor)->esq != NULL)
        desalocar(&((*percursor)->esq));

    if ((*percursor)->dir != NULL)
        desalocar(&((*percursor)->dir));
    
    free(*percursor);
    *percursor = NULL;
}


int altura(s_no *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        int esquerda = altura((raiz)->esq);
        int direita = altura((raiz)->dir);

        if (esquerda >= direita)
            return esquerda + 1;
        else
            return direita + 1;
    }
}

short calcular_bal(s_no *raiz)
{
    return ( altura(raiz->esq) - altura(raiz->dir));
}

void balancear (s_no **raiz) {

    if ((*raiz)->esq != NULL)
        balancear(&((*raiz)->esq));
    
    if ((*raiz)->dir != NULL)
        balancear(&((*raiz)->dir));
    
    (*raiz)->bal = calcular_bal(*raiz);
}