#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ( ) {
    char palavra[20];

    scanf("%10[^\n]", palavra); // nao utilizar & em string
    // %10 - limita o scanf a apenas 10 caracteres | o vermelho nao esta errado
    // [^\n] - impede que o scanf acabe no espaço
    printf("%s", palavra);
    return 0;
}