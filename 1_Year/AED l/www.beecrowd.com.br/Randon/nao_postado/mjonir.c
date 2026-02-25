#include <stdio.h>

int main () {
    int r, f;
    char nome[30];
    scanf("%d", &r);
    for (int i=0; i<r; i++){
        scanf("%s %d", &nome, &f);
        if (strcmp(nome,"Thor"))
            printf("N\n");
        else 
            printf("Y\n");
    }
    return 0;
}