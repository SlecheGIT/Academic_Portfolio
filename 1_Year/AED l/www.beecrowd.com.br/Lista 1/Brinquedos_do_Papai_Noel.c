#include <stdio.h>

int main (){
 int i=1, f, car=0, bone=0;
 char s;
 char nome[10];

    scanf("%i", &f);

     while (i<=f){   
      scanf("%s %c", &nome, &s); 

        if (s=='M') {
          ++car;
        } 
        if (s=='F') {
          ++bone;
        }

     i=i+1;
     }
    printf("%d carrinhos\n", car);
    printf("%d bonecas\n", bone);

/*
5
Milena F
Joao M
Rafaela F
Renata F
Felipe M
___________
2 carrinhos
3 bonecas
*/
    return 0;
}