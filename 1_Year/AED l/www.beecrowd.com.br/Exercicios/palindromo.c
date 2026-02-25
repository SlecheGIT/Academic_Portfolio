#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Remove as ocorrências C de FRASE. Por exemplo, se FRASE tiver "-ARA-RA" e C tiver -,
//então FRASE deve ficar com "ARARA"
void Delete(char *FRASE, char C) {
    int n = strlen(FRASE);
    for (int i = 0; i < n; i++)
    {
        if (FRASE[i] == C)
        {
            for (int cont = i; cont < n; cont++)
            {
                if (cont == n-1)
                {
                    FRASE[cont] = '\0';
                }
                FRASE[cont] = FRASE[cont+1];
            }
        }
    }
}

//Retorna 1 se a informação em FRASE é um palíndromo ou 0 se não for
int IsPalindromo(char *FRASE) {
    int n = strlen(FRASE)-1;
    int cont = 0;
    for (int i = 0; i <= n; i++)
        if (FRASE[i] == FRASE[n-i])
            cont++;
    
    if (cont >= n)
        cont = 1;
    else
        cont = 0;
    return cont;
}

void Printa(int is) {
    if (is)
        printf("\nE palindromo!");
    else
        printf("\nNao e palindromo!");
}

int main() {

    char nome[] = "SOCORRAM-ME, SUBI NO ONIBUS EM MARROCOS";

    Delete(nome,' ');
    //retira espaços em brancos

    Delete( nome,',');
    //retira vírgulas

    Delete( nome,'-');
    //retira hífens

    Printa( IsPalindromo(nome));

    return 0;
}