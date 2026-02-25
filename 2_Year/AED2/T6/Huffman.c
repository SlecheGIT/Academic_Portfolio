#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>
// #include "gfx/gfx.h"
// #include <locale.h>

#define ASCII 255 // com assentuação

typedef struct arvore_arq
{
    unsigned char caracter;
    unsigned long frequencia;
    uint32_t esq : 1;
    uint32_t dir : 1;
}arvore_arq;

typedef struct arvore
{
    unsigned char caracter;
    unsigned long frequencia;
    struct arvore *dir;
    struct arvore *esq;
} arvore;

typedef struct lista
{
    struct arvore *no;
    struct lista *prox;
} lista;


unsigned char* carregar_texto(const char *nome_arquivo);
void salvar_texto(arvore **raiz, char *binarios, char* nome_arquivo);
void salvarArvore(arvore *percursor, FILE **arquivo);
void salvar_binario(arvore *ArvoreHuffman,char *Textocodificado, char *name_infile, unsigned long tam);
void carregar_arvore( arvore **percursor, FILE *arquivo );
void carregar_binario(char **Textocodificado,char *name_infile, arvore **ArvoreHuffman);
void desalocar_lista(lista **inicio);


//com base na tabela de traducao a funcao gera a criptografia do texto
void TrancreveTextoCodificado(char **tabela_de_traducao,char *TextoCodificado, unsigned char *texto)
{
    for (int i = 0; texto[i] != '\0'; i++)
        strcat(TextoCodificado, tabela_de_traducao[texto[i]]);
}

// a altura da arvore representa a letra com mais recorrencias, portanto a maior string
int calcula_altura(arvore **percursor)
{
    if (*percursor)
    {
        int esq = calcula_altura(&(*percursor)->esq);
        int dir = calcula_altura(&(*percursor)->dir);

        if (esq > dir)
            return esq+1;
        else 
            return dir+1;
    }
    else
        return -1;
}

//calcula o tamanho do texto quando for encriptado com base na multiplicação dos caracteres e ocorrencias
unsigned long calcula_texto(char **tabela_de_traducao, arvore **percursor) 
{
    if (*percursor)
    {
        unsigned long esq = calcula_texto(tabela_de_traducao, &(*percursor)->esq);
        unsigned long dir = calcula_texto(tabela_de_traducao, &(*percursor)->dir);

        if (((*percursor)->esq == NULL) && ((*percursor)->dir == NULL))
            return strlen(tabela_de_traducao[(*percursor)->caracter]) * (*percursor)->frequencia;
        
        return esq + dir;
    }
    return 0;
}

char **alloca_tabela_de_traducao(int MaiorString)
{
    char **MatrizDePosicoes;

    MatrizDePosicoes = malloc(sizeof(char*) * ASCII);

    for (int i = 0; i < ASCII; i++)
        MatrizDePosicoes[i] = calloc(MaiorString+1, sizeof(char)); 
    
    return MatrizDePosicoes;
}

//preenche a tabela com o representativo das letras na arvore
void codificador(char **tabela_de_traducao, arvore **percursor, char *caminho, int nivel)
{
    if ((*percursor)->esq == NULL && (*percursor)->dir == NULL)
    {
        caminho[nivel] = '\0';
// usa uma tabela com posiçoes para todos os caracteres acessando o numero das letras na tabela asc
        strcpy(tabela_de_traducao[(*percursor)->caracter], caminho);
    }
    else
    {
        caminho[nivel] = '0';
        codificador(tabela_de_traducao, &(*percursor)->esq, caminho, nivel+1);
        caminho[nivel] = '1';
        codificador(tabela_de_traducao, &(*percursor)->dir, caminho, nivel+1);
    }
}

//insere uma arvore em uma lista de arvores
void inserir_ordenado(lista **inicio, arvore **raiz) 
{
    lista *percursor = *inicio;
    lista *novo = malloc(sizeof(lista));
    novo->no = *raiz;

    if (*inicio == NULL)
    {
        novo->prox = NULL;
        *inicio = novo;
    }
    else
    {
        if ((*raiz)->frequencia < percursor->no->frequencia)
        {
            novo->prox = *inicio;
            *inicio = novo;
        }
        else
        {
            while (percursor->prox != NULL)
            {
                if ((*raiz)->frequencia < percursor->prox->no->frequencia)
                    break;
                
                percursor = percursor->prox;
            }
            novo->prox = percursor->prox;
            percursor->prox = novo;
        }
    }
}

// funncao pop, remove da lista e retorna o ponteiro da arvore
arvore *remove_inicio(lista **inicio)
{
    lista *remove = *inicio;
    arvore *aux = remove->no;

    *inicio = (*inicio)->prox;
    free(remove);
    remove = NULL;
    return aux; 
}

//remove duas arvores da lista e as junta ordenando a novamente na lista
void fusao(lista **inicio)
{
    if ((*inicio)->prox)
    {
        arvore *fusao = malloc(sizeof(arvore));
        arvore *left = remove_inicio(&(*inicio));
        arvore *right = remove_inicio(&(*inicio));

        fusao->frequencia = left->frequencia + right->frequencia;
        fusao->caracter = '*';
        fusao->esq = left;
        fusao->dir = right;

        inserir_ordenado(&(*inicio), &fusao);
    }
}

//apenas administra quantas vezes sera feita a fusao ate o fim da lista
arvore *Construir_ArvoreHuffman(lista **tabela) 
{
    while ((*tabela)->prox != NULL)
        fusao(&(*tabela));
    return (*tabela)->no;
}

//busca se existe aquele caracter na lista
// caso exista soma 1 na frequencia
bool Buscar_Recorrencia(lista **tabela, unsigned char c)
{
    lista *percursor = *tabela;
    bool find = false;

    while (percursor && (find == false))
    {
        if (percursor->no->caracter == c)
        {
            percursor->no->frequencia++;
            find = true;

            arvore *aux;

            while (percursor->prox)
            {
                if (percursor->no->frequencia > percursor->prox->no->frequencia)
                { 
                    //avanca para ordenar aquela frequencia no lugar desejado da lista
                    aux = percursor->no;
                    percursor->no = percursor->prox->no;
                    percursor->prox->no = aux;
                    percursor = percursor->prox;
                }
                else
                    break;
            }
        }
        else
            percursor = percursor->prox;
    }
    return find;
}

//insere os caracteres em uma "tabela" de frequencia, uma lista de arvores binarias
void tabela_frequencia(lista **tabela, unsigned char c)// inserção ordenada por frequencia
{ 
    arvore *nova_raiz = malloc(sizeof(arvore));
    lista *novo_no = malloc(sizeof(lista));

    nova_raiz->caracter = c;
    nova_raiz->frequencia = 1;
    nova_raiz->esq = NULL;
    nova_raiz->dir = NULL;

    if (*tabela)
    {
        // caso nao exista o caracter na lista, criara uma nova arvore com ele
        if (!Buscar_Recorrencia(&(*tabela), c)) 
        { 
            novo_no->no = nova_raiz;
            novo_no->prox = *tabela;
            *tabela = novo_no;
        }
    }
    else
    {
        novo_no->no = nova_raiz;
        novo_no->prox = NULL;
        *tabela = novo_no;
    }
}

int main(int argc, char *argv[])
{
    // gfx_init(1280, 720, "Árvore Binária de Busca");
    // setlocale(LC_ALL, "Portuguese");

    arvore *ArvoreHuffman = NULL;
    lista *tabela_de_frequencia = NULL; // armazena as frequencias de cada caracter em arvores
    FILE *teste_arquivo;

    int altura;
    unsigned long tamanho_do_texto;
    char **tabela_de_traducao = NULL;
    char *TextoCodificado = NULL;
    unsigned char *texto = NULL;
    char *caminho = NULL;
    char choise;

    //----------- teste de argumentos -----------
    if (argc != 3)
    {
        perror("Falta argumentos na chamada!");
        return 1;
    }
    else
    {
        if ((argv[1][0] != 'c') && (argv[1][0] != 'd'))
        {
            perror("\nArgumentos na chamada incorreto!\n");
            return 1;
        }
        else
            choise = argv[1][0];
        
        teste_arquivo = fopen(argv[2], "r");
        if (!teste_arquivo)
        {
            perror("Arquivo nao encontrado");
            return 1;
        }
        fclose(teste_arquivo);
    }
    

    switch (choise)
    {
    case 'c':
        //-------------- colocar texto na string --------------
        texto = carregar_texto(argv[2]);

        //-------------- calcular tabela de frequencia ---------------------
        for (int i = 0; texto[i] != '\0' ; i++)
            tabela_frequencia(&tabela_de_frequencia, texto[i]);

        //-------------- montar arvore --------------
        ArvoreHuffman = Construir_ArvoreHuffman(&tabela_de_frequencia);

        //-------------- gerar matriz com elementos codificados ------------
        altura = calcula_altura(&ArvoreHuffman);
        caminho = calloc(sizeof(char), altura); // caminho vai conter o tamanho da maior string da arvore

        tabela_de_traducao = alloca_tabela_de_traducao(altura);
        codificador(tabela_de_traducao, &ArvoreHuffman, caminho, 0);

        //-------------- gerar arquivo binario -----------------------------
        tamanho_do_texto = calcula_texto(tabela_de_traducao, &ArvoreHuffman); //calcula baseado na frequencia e caracteres
        TextoCodificado = calloc(tamanho_do_texto+1, sizeof(char));

        TrancreveTextoCodificado(tabela_de_traducao, TextoCodificado, texto);
        
        salvar_binario(ArvoreHuffman,TextoCodificado, argv[2], tamanho_do_texto);

        break;
    
    case 'd':
        //-------------- carregar arquivo binario -----------------------------
        ArvoreHuffman = malloc(sizeof(arvore));
        carregar_binario(&TextoCodificado, argv[2], &ArvoreHuffman);

        // inserindo em uma lista para poder alocar com a mesma funcao
        inserir_ordenado(&tabela_de_frequencia, &ArvoreHuffman); 

        //-------------- salvar Texto codificado -----------------------------
        salvar_texto(&ArvoreHuffman, TextoCodificado, argv[2]);

        break;
    }
    // imprimir(&ArvoreHuffman, 620, 30, 620);
    // system("read -p \"\nPressione (enter) para sair.\" .");
    desalocar_lista(&tabela_de_frequencia); // arvore continua dentro da lista
}

//-------------------------------------------------------------------------------------------------


unsigned char* carregar_texto(const char *nome_arquivo)
{ 
    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    struct stat tamanho_do_texto;
    if (stat(nome_arquivo, &tamanho_do_texto) == -1) {
        perror("Erro ao obter informações do arquivo");
        return NULL;
    }
    //calcula o tamanho do texto baseado no tamanho do arquivo e aloca esse tamanho para o vetor
    unsigned char *texto =  malloc((tamanho_do_texto.st_size + 1) * sizeof(unsigned char));
    if (texto == NULL) {
        perror("Erro ao alocar memória");
        fclose(file);
        return NULL;
    }

    fread(texto, sizeof(unsigned char), tamanho_do_texto.st_size, file);
    texto[tamanho_do_texto.st_size] = '\0'; 
    fclose(file);

    return texto;
}

void salvar_texto(arvore **raiz, char *binarios, char* nome_arquivo)
{
    int i=0;

    arvore *percursor = *raiz;
    strcat(nome_arquivo, ".dcmp");
    FILE *Texto = fopen(nome_arquivo, "w");

    while (binarios[i] != '\0') // percorre a arvore ate o termino do codigo criptografado
    {
        if (binarios[i] == '0')
            percursor = percursor->esq;
        else
            percursor = percursor->dir;

        //sempre que estiver em uma folha escreve a letra correspondente no arquivo
        if ((percursor->esq == NULL) && (percursor->dir == NULL))
        {
            fputc(percursor->caracter, Texto);
            //reinicia o percurso
            percursor = *raiz;
        }
        i++;
    }
    fclose(Texto);
}

//salva a struct da arvore binaria na lista
void salvarArvore(arvore *percursor, FILE **arquivo)
{
    arvore_arq noh;

	noh.caracter = percursor->caracter;
	noh.frequencia = percursor->frequencia;

	if(percursor->esq) noh.esq = 1;
	else noh.esq = 0;

	if(percursor->dir) noh.dir = 1;
	else noh.dir = 0;

	fwrite(&noh, sizeof(arvore_arq), 1, *arquivo);

	if(percursor->esq)
		salvarArvore( percursor->esq, &(*arquivo) );
	if(percursor->dir)
		salvarArvore( percursor->dir, &(*arquivo) );
}

//insere em um arquivo binario as seguintes informacoes:
    // tamanho do texto codificado + textocodificado + arvore huffman
void salvar_binario(arvore *ArvoreHuffman,char *Textocodificado, char *name_infile, unsigned long tam)
{
    char *name_outfile = calloc(strlen(name_infile) +5, sizeof(char) );
    strcat(name_outfile, name_infile);
    strcat(name_outfile, ".cmp");
    FILE *arq = fopen(name_outfile, "wb");
    if (!arq)
    {
        perror("arquivo nao pode ser aberto");
        return;
    }
    
    unsigned long i = 0;
    int deslocamento = 7;
    char mask, byte = 0;

    //insere o tamanho para o caso dos bits não formarem um byte
    fwrite(&tam, sizeof(unsigned long), 1, arq);

    while (Textocodificado[i] != '\0')
    {
        mask = 1; // mascara de deslocamento, corresponde ao binario 00000001
        if (Textocodificado[i] == '1')
        {
            mask = mask << deslocamento; // 00000001 << 7 = 10000000
            byte = byte | mask; // vai mesclar o bit 1 caso exista naquela posicao
            //exemplo da altecao como em uma tabela verdade:
            // mask : 00100000 
            // byte : 10000000
  // byte "ou" mask : 10100000 
        }
        --deslocamento;
        if (deslocamento < 0)
        {
            fwrite(&byte, sizeof(char), 1, arq); // escreve aquele byte
            deslocamento = 7; // reinicia o deslocamento
            byte = 0; // reinicia o byte
        }
        ++i;
    }
    if (deslocamento != 7) // caso sobre bits tambem serao inseridos
        fwrite(&byte, sizeof(char), 1, arq);

    // salva a arvore após o texto encriptado
    salvarArvore(ArvoreHuffman, &arq);
    
    fclose(arq);
}

void carregar_arvore( arvore **percursor, FILE *arquivo )
{
	arvore_arq *AVL_arq = malloc(sizeof(arvore_arq));

	if(fread(AVL_arq, sizeof(arvore_arq), 1, arquivo))
    {
		(*percursor)->caracter = AVL_arq->caracter;
		(*percursor)->frequencia = AVL_arq->frequencia;
		arvore *NovaFolha;

		if(AVL_arq->esq)
        {
            NovaFolha = NULL;
			NovaFolha = malloc(sizeof(arvore));
	        arvore *aux;
			
			(*percursor)->esq = NovaFolha;
			aux = (*percursor)->esq;
			carregar_arvore(&aux, arquivo);
		}
		else
			(*percursor)->esq = NULL;

		if(AVL_arq->dir)
        {
            NovaFolha = NULL;
			NovaFolha = malloc(sizeof(arvore));
	        arvore *aux;
			
			(*percursor)->dir = NovaFolha;
			aux = (*percursor)->dir;
			carregar_arvore(&aux, arquivo);
		}
		else
			(*percursor)->dir = NULL;
	}
	else
		*percursor = NULL;
}

void carregar_binario(char **Textocodificado,char *name_infile, arvore **ArvoreHuffman)
{
    unsigned long tam = 0, i = 0;
    int deslocamento = -1;
    char byte = 0, mask = 0;
    FILE *arq = fopen(name_infile, "rb");

    //a primeira informação vai ser o tamanho e delimitador do loop
    fread(&tam, sizeof(unsigned long), 1, arq);
    // aloca com base no tamanho do codigo encriptado
    (*Textocodificado) = calloc(tam+1, sizeof(char)); 

    while (i < tam)
    {
        if (deslocamento < 0)
        {
            fread(&byte, sizeof(char), 1, arq);
            deslocamento = 7;
        }
        mask = (1 << deslocamento);
        //caso o bit naquela posição deslocada for 1 entao ele vai retornar qualquer valor de -127 a 127 exceto o 0
        //caso contrario todas as posições resultantes serão 0 tambem
        if (byte & mask) 
            (*Textocodificado)[i] = '1';
        else
            (*Textocodificado)[i] = '0';

        deslocamento--;
        i++;
    }
    (*Textocodificado)[tam] = '\0'; //insere o final da string

    carregar_arvore(&(*ArvoreHuffman), arq); // carrega a arvore de onde o texto parou
    fclose(arq);
}

void desaloca_arvore(arvore **percursor) 
{
    if ((*percursor)->esq != NULL)
        desaloca_arvore(&((*percursor)->esq));

    if ((*percursor)->dir != NULL)
        desaloca_arvore(&((*percursor)->dir));
    
    free(*percursor);
    *percursor = NULL;
}

void desalocar_lista(lista **inicio)
{
    lista *p = *inicio;
    lista *remove;

    while (p != NULL)
    {
        remove = p;
        p = p->prox;
        desaloca_arvore(&(remove->no));
        free(remove);
    }

    *inicio = NULL;
}

/*
void imprimir (arvore **percursor, int x, int y, int recursividade) {
            // parametros de recursividade para saber a posição do meio da tela
    if (*percursor != NULL)
    {
        char text[20];
        arvore *p;

        if (x == 620)
            gfx_clear();

        gfx_set_color(100, 0, 0);
         //quadrado do balanço
        gfx_set_font_size(15);
        sprintf(text, "%d", (*percursor)->frequencia);
        gfx_rectangle(x+10, y+40, x+30, y+60);
        gfx_text(x+13, y+42, text);

        gfx_set_color(100, 100, 100);
        //quadrado da chave
        gfx_set_font_size(25);
        text[0] = (*percursor)->caracter;
        text[1] = '\0';
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


void imprimir_Texto_codificados(char **tabela_de_traducao)
{
    for (int i = 0; i < ASCII; i++)
    {
        if (tabela_de_traducao[i][0] != '\0')
            printf("\n[%c] = %s", (char)i, tabela_de_traducao[i]);
    }
    printf("\n\n\n");
    
}
*/