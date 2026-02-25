
#include <stdio.h>

//	Este programa tem por objetivo 
//	demonstrar como corrigir o problema de 
//	leitura de dados do tipo CHAR.
//
//	Para usar esta solu��o, copie a fun��o
//  	"flush_in" no in�cio do seu programa
//  	fonte e coloque uma chamada desta
//	fun��o ap�s cada leitura de teclado 
//	feita com SCANF




// ******************************************
// Nome: void flush_in
// Descri��o: Fun��o que "limpa" o teclado
// evitando problemas com a leitura de dados
// do tipo CHAR.
// ******************************************
void flush_in()
{
   int ch;

   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

// ******************************************
//            Programa principal
int main()
{
    char op;
    int a, b;
    char nome[50];

    printf("digite o primeiro inteiro: ");
    scanf("%d",&a);
    flush_in();		 // Limpa o teclado

    printf("digite um char: ");
    scanf("%c",&op);
    flush_in();		 // Limpa o teclado

    printf("digite o segundo inteiro: ");
    scanf("%d",&b);
    flush_in();		 // Limpa o teclado

    printf("digite um nome: ");
    scanf("%s",nome);
    flush_in();		 // Limpa o teclado

  return 1;
}
