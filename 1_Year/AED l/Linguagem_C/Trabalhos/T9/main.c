#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// funcoes {
void one ();

void two ();

void tree ();

void four ();

void five ( );
//}

int main ()
{
    int menu = 0;
    do {
        system("cls");
        printf("1-Decifra arquivo\
            \n2-Grava numero linha em arquivo\
            \n3-Quantas linhas o arquivo tem\
            \n4-Qual a maior linha\
            \n5-Pesquisar uma palavra\
            \n0-Encerrar \n\nQual opcao:  ");
        scanf("%d", &menu);
        fflush(stdin);

        switch (menu)
        {
        case 1:
            system("cls");
            one();
            system("pause");
            break;

        case 2:
            system("cls");
            two();
            system("pause");
            break;

        case 3:
            system("cls");
            tree();
            system("pause");
            break;

        case 4:
            system("cls");
            four();
            system("pause");
            break;

        case 5:
            five();
            break;

        case 0:
            printf("Encerrando o programa...\n");
            return 0;

        default:
            printf("opcao invalida! \n\n");
            system("pause");
            break;
        }
    } while (1);
}

void one () {
    char code[98230];
    char text[21550];
    int cont = 0;
    char asc[4];
    FILE *arquivo;
    arquivo = fopen("readme.code.txt", "r+");
    
    if (arquivo == NULL){
        printf("\nArquivo nao pode ser aberto!\n");
        system("pause");
        exit(0);
    }
    fscanf(arquivo, "%s", code);
    fclose(arquivo);
    
    for (long int loop = 0; loop < 98225; loop++)
    {
        if (code[loop] == '[')
        {
            loop++;
            memset(asc, '\0', sizeof(asc));
            for (int i = 0; code[loop] != ']'; loop++, i++)
                asc[i] = code[loop];
            text[cont] = atoi(asc); 
            cont++;
        }
    }
    arquivo = fopen ("readme.decifra.txt", "w");
    fprintf(arquivo, text);
    fclose(arquivo);
    printf("   Arquivo decifrado...\nreadme.decifra.txt foi criado!\n\n");
}

void two ()
{
    char linha[200];
    int num_linha = 1;
    
    FILE *arquivo = fopen("readme.decifra.txt", "r" );
    if (arquivo==NULL){
        printf("readme.decifra.txt nao foi encontrado\n      Arquivo nao decifrado\n\n");
        return;
    }

    FILE *arq_linhas = fopen ("readme.nlines.txt", "w");
    while(fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        fprintf(arq_linhas, " [linha:%d] %s ", num_linha, linha);
        num_linha++;
    }
    fclose(arquivo);
    fclose(arq_linhas);
    printf("   Arquivo Gerado...\nreadme.nlines.txt foi criado!\n\n");
}

void tree (){
    char linha[200];
    int num_linhas=0;
    FILE *arquivo;
    arquivo = fopen ("readme.decifra.txt", "r");

     if (arquivo == NULL){
        printf("readme.decifra.txt nao foi encontrado\n      Arquivo nao decifrado\n\n");
        return;
    }

    while(fgets(linha, sizeof(linha), arquivo)!= NULL)
        num_linhas++;

    fclose(arquivo);
    
    printf("O arquivo %s tem (%d) linhas.\n\n", arquivo,num_linhas);
}
    
void four ()
{
    char linha[1000];
    int num_linha = 1;
    int maior_caracter = 0;
    int num_caracter;
    int maior_linha=0;

    FILE *arquivo;
    arquivo = fopen ("readme.decifra.txt", "r");
    
    if (arquivo==NULL){
        printf("readme.decifra.txt nao foi encontrado\n      Arquivo nao decifrado\n\n");
        system("pause");
        return;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) 
    {
        num_caracter = strlen(linha);

        if (num_caracter > maior_caracter){
            maior_caracter = num_caracter;
            maior_linha = num_linha;
        }
        num_linha++;
    }
    fclose(arquivo);
    printf("A linha [%d] e a maior com (%d) caracteres.\n\n", maior_linha, maior_caracter);
}

void five ( ){
    char linha[200];
    char palavra[60];
    int num_linha = 0;
    int ocorrencia = 0;
    bool retry = false;

    FILE *arquivo = fopen("readme.decifra.txt", "r" );
    if (arquivo==NULL){
        printf("readme.decifra.txt nao foi encontrado\n      Arquivo nao decifrado\n\n");
        return;
    }
    printf("\nQual palavra pesquisar: ");
    scanf("%s", palavra);
    fflush(stdin);
    int words = strlen(palavra);

    FILE *arq_linhas = fopen ("readme.nlines.txt", "w");
    while(fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        int cont = 0;
        num_linha++;
        for (int i = 0; i < strlen(linha); i++)
        {
            if ((palavra[cont] == linha[i]) && (!isalpha(linha[i-1-cont])))
                cont++;
            else
                cont = 0;
            if ((cont == words) && (!isalpha(linha[i+1]))){
                if (ocorrencia == 0)
                    printf("\nAs linhas em que a palavra  \"%s\" ocorre:\n\n", palavra);
                ocorrencia++;
                if (retry == false)
                {
                    printf("[linha:%d] %s", num_linha, linha);
                    retry = true;
                }
            }
        }
        retry = false;
    }
    fclose(arquivo);
    fclose(arq_linhas);
    if (ocorrencia == 0)
        printf("\nA palavra \"%s\" nao foi encontrada!\n", palavra);
    else   
        printf("\ne tem %d ocorrencias.\n", ocorrencia);
    printf("\nTecle algo para continuar!");
    getchar();
    
}