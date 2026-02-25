#include "gfx/gfx.h"
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
//finish
typedef struct arvore {
    int val;
    struct arvore *left;
    struct arvore *right;
}arvore;

struct s_arq_no
{
    int32_t chave:30;
    uint32_t esq:1;
    uint32_t dir:1;
};

void clear () {
    system("clear");
}

void menor(arvore **percursor) {

    if ((*percursor)->left != NULL)
        menor(&((*percursor)->left));
    else
        printf("\nmenor valor: %d\n", (*percursor)->val);
    
}

void maior (arvore **percursor) {

    if ((*percursor)->right != NULL)
        maior(&((*percursor)->right));
    else
        printf("\nmaior valor: %d\n", (*percursor)->val);
}

bool busca2 (arvore *percursor, int x, bool signal) {

    if (percursor->val == x )
        signal = true;
    else 
    {
        if(x < percursor->val)
        {
            if (percursor->left != NULL)
                signal = busca2(percursor->left, x, signal);
        }
        else
        {
            if(x > percursor->val)
                if (percursor->right != NULL)
                    signal = busca2(percursor->right, x, signal);
        }
    }
    return signal;
}

int sucessor(arvore *percursor, int x, int status) {

    if (percursor != NULL)
    {
        if (x < percursor->val)    
            status = sucessor(percursor->left, x, status);
        else
        if (x > percursor->val)
            status = sucessor(percursor->right, x, status);
        else
        if (x == percursor->val)
        {
            if (percursor->right != NULL){

                percursor = percursor->right;
                while (percursor->left != NULL)
                    percursor = percursor->left;
                printf("\nsucessor: %d\n", percursor->val);
            }
            else 
                status = 1;
        }

        if ((status == 1) && (percursor->val != x)){
            if (percursor->val > x)
            {
                printf("\nsucessor: %d\n", percursor->val);
                status = 0;
            }
        }
        return status;
    }
    else
        return '0';
}

int predecessor(arvore *percursor, int x, int status) {

    if (percursor != NULL)
    {
        if (x < percursor->val)    
            status = predecessor(percursor->left, x, status);
        else
        if (x > percursor->val)
            status = predecessor(percursor->right, x, status);
        else
        if (x == percursor->val)
        {
            if (percursor->left != NULL){

                percursor = percursor->left;
                while (percursor->right != NULL)
                    percursor = percursor->right;
                
                printf("\npredecessor: %d\n", percursor->val);
            }
            else 
                status = 1;
        }

        if ((status == 1) && (percursor->val != x)){
            if (percursor->val < x)
            {
                printf("\npredecessor: %d\n", percursor->val);
                status = 0;
            }
        }
        return status;
    }
    else
        return '0';
    
    return status;
}

void inserir (arvore **percursor, int x) {

    if (*percursor == NULL)
    {
        *percursor = malloc(sizeof(arvore));
        (*percursor)->left = NULL;
        (*percursor)->right = NULL;
        (*percursor)->val = x;
    }
    else
    {
        if (x < (*percursor)->val)
            inserir (&((*percursor)->left), x);
        else
        if (x > (*percursor)->val)
            inserir (&((*percursor)->right), x);
        else
        if (x == (*percursor)->val)
            printf("\n  [Erro ao alocar]\nvalor ja esta contido na arvore!\n");
    }
}

arvore *remover (arvore *percursor, int x) {

    if (percursor != NULL) 
    {
        if (percursor->val == x)
        {
            if ((percursor->left == NULL) && (percursor->right == NULL))
            {
                free(percursor);
                return NULL;
            }
            else
            {
                arvore *aux = percursor;
                if ((percursor->left != NULL) && (percursor->right != NULL))
                {
                    aux = aux->right;
                    int chave = percursor->val;
                    while (aux->left != NULL)
                        aux = aux->left;

                    percursor->val = aux->val;
                    aux->val = chave;
                    percursor->right = remover(percursor->right, chave);

                    return percursor;
                }
                else
                {
                    if (percursor->left != NULL)
                        percursor = percursor->left;
                    else
                        percursor = percursor->right;
                    free(aux);
                    return percursor;
                }
            }
        } else {
            if (x < (percursor)->val)
                percursor->left = remover(percursor->left, x);
            else
                percursor->right = remover(percursor->right, x);

            return percursor;
        }
    } 
    else 
    {
        printf("\nvalor nao encontrado\n");
        return NULL;
    }
}

void imprimir (arvore **percursor, int x, int y, int recursividade) {

    if (*percursor != NULL)
    {
        char text[20];
        arvore *p;

        if (x == 620)
            gfx_clear();

        sprintf(text, "%d", (*percursor)->val); // transcreve o valor para uma string

        gfx_rectangle(x, y, x+40, y+40);
        gfx_text(x+5, y+5, text);
        
        if ((*percursor)->left != NULL){
            p = (*percursor)->left;
            gfx_line(x, y+40, (x - (recursividade/2))+20, y+80);
            imprimir(&p, x-(recursividade/2), y+80, recursividade/2);
        }
        if ((*percursor)->right != NULL){
            p = (*percursor)->right;
            gfx_line(x+40, y+40, (x+(recursividade/2))+20, y+80);
            imprimir(&p, x+(recursividade/2), y+80,  recursividade/2);
        }
        
        if (x == 620)
            gfx_paint();
    }
    else {
        gfx_clear();
        printf("\nLista vazia!\n");
        gfx_paint();
    }
}

void desalocar (arvore **percursor) {

    if ((*percursor)->left != NULL)
        desalocar(&((*percursor)->left));

    if ((*percursor)->right != NULL)
        desalocar(&((*percursor)->right));
    
    free(*percursor);
    *percursor = NULL;
}

void salvar(arvore *raiz, FILE **arquivo) {
    
	struct s_arq_no arq;

    arq.chave = raiz->val;

	if(raiz->left != NULL) 
        arq.esq = 1;
	else
        arq.esq = 0;

	if(raiz->right != NULL) 
        arq.dir = 1;
	else 
        arq.dir = 0;

	fwrite(&arq, sizeof(struct s_arq_no), 1, *arquivo);

	if(raiz->left != NULL)
		salvar(raiz->left, &(*arquivo));
	if(raiz->right != NULL)
		salvar(raiz->right, &(*arquivo));
}

void carregar(arvore **raiz, FILE *arquivo){
    
	struct s_arq_no *arq = malloc(sizeof(struct s_arq_no));
	arvore *percursor;

	if(fread(arq, sizeof(struct s_arq_no), 1, arquivo) != 0)
    {
		(*raiz)->val = arq->chave;
		arvore *NovaFolha;
		if(arq->esq != 0)
        {
            NovaFolha = NULL;
			NovaFolha = malloc(sizeof(arvore));
			
			percursor = NovaFolha;
			(*raiz)->left = percursor;
			carregar(&percursor, arquivo);
		}
		else
			(*raiz)->left = NULL;

		if(arq->dir != 0)
        {
			NovaFolha = NULL;
			NovaFolha = malloc(sizeof(arvore));
			
			percursor = NovaFolha;
			(*raiz)->right = percursor;
			carregar( &percursor, arquivo);
		}
		else
			(*raiz)->right = NULL;
	}
	else
		*raiz = NULL;
}

int main () {
    arvore *raiz = NULL;
    int choise, x, prox;
    int anterior = 0;
    char nome[30];

	gfx_init(1280, 720, "Árvore Binária de Busca");
    gfx_set_font_size(25);
    
    do {
        printf("\n(1) Busca pela maior e menor chave na árvore\n");
        printf("(2) Busca por uma chave com valor x\n");
        printf("(3) Busca pelo sucessor e predecessor de uma chave com valor x\n");
        printf("(4) Inserção de uma chave com valor x\n");
        printf("(5) remoção de uma chave com valor x\n");
        printf("(6) carregar arvore\n");
        printf("(7) salvar arvore\n");
        printf("(0) encerrar programa\n--> ");
        scanf("%d", &choise);
        clear();

        switch (choise)
        {
        case 1:
            if (raiz != NULL) {
                printf("| Busca pela maior e menor chave na árvore |\n");
                menor(&raiz);
                maior(&raiz);
            } else
                printf("Arvore vazia\n");
            
            break;
        
        case 2:
            if (raiz != NULL) {
                printf("| Busca por uma chave com valor x |\n");
                printf("insira o valor que sera buscado: ");
                scanf("%d", &x);

                if (busca2(raiz, x, false))
                    printf("\nvalor %d foi encontrado na arvore! \n", x);
                else
                    printf("\nNão esta contido na arvore!\n");


            } else
                printf("Arvore vazia\n");
            break;
        
        case 3:
            if (raiz != NULL) {
                printf("| Busca pelo sucessor e predecessor de uma chave com valor |\n");
                printf("insira o valor que sera buscado: ");
                scanf(" %d", &x);
                prox = sucessor(raiz, x, 0);
                if (prox == 1)
                    printf("\nsucessor não encontado!\n");
            
                anterior = predecessor(raiz, x, 0);
                if (anterior == 1)
                    printf("\npredecessor não encontado!\n");
            } else
                printf("Arvore vazia\n");
            break;
        
        case 4:
            printf("| Inserção de uma chave com valor x |\n");
            printf("insira o novo valor: ");
            scanf(" %d", &x);
            inserir(&raiz, x);
            // imprimir(&raiz, 620, 30, 620);
            break;
        
        case 5:
            if (raiz != NULL) {
                printf("| remoção de uma chave com valor x | \n");
                printf("insira o valor que sera excluido: ");
                scanf(" %d", &x);
                raiz = remover(raiz, x);
                // imprimir(&raiz, 620, 30, 620);
            }
            else
                printf("Arvore vazia\n");
            break;
        
        case 6:
            printf("| carregar arvore | \n");
            printf("insira apenas o nome do arquivo que deseja abrir (contido nesta pasta): ");
			scanf("%s", nome);
            strcat(nome, ".bin");

            arvore *percursor = NULL;
            FILE *arquivo;
			arquivo = fopen(nome, "rb"); 

			if(arquivo == NULL)
				printf("\nArquivo não encontrado!\n");
			
            else
            {
                percursor = malloc(sizeof(arvore));
                carregar(&percursor, arquivo);

                if (raiz != NULL)
                    desalocar(&raiz);
                raiz = percursor;
                percursor = NULL;

                fclose(arquivo);
		        printf("\n[Arvore carregada] arvore antiga foi sobrescrevida!\n");
                // imprimir(&raiz, 620, 30, 620);
            }

            nome[0] = '\0';
            break;

        case 7:
            if (raiz != NULL) {
                printf("| salvar arvore | \n");
                printf("insira apenas o nome do arquivo que vai salvar (nao repita outros arquivos): ");
                scanf("%s", nome);
                strcat(nome, ".bin");

                FILE *arquivo;
		        arquivo = fopen(nome, "ab");
                salvar(raiz, &arquivo);
                fclose(arquivo);

                printf("\nArvore foi salva como %s!\n", nome);

            }
            else
                printf("Arvore vazia\n");
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
            system("read -p \"\nPressione (enter) para sair.\" .");
            clear();
        }
    } while (choise);
    
    printf("\n");
    
    if (raiz != NULL)
        desalocar(&raiz);

    gfx_quit();
}