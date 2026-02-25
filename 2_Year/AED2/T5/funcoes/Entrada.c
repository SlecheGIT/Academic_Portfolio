#include <stdio.h>

int main (int argc, char *argv[])
{
    if( argc != 4 ){
        printf("\nQuantidade de entradas invalida!\n");
        return 0;
    }

    FILE *filein = fopen(argv[2], "rb");
    FILE *fileout = fopen(argv[3], "rb");

    if (!filein)
    {
        printf("\nArquivo inserido nao existe!\n");
        return 0;
    }
    
    return 0;
}