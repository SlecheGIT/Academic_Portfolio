#include <stdio.h>
#include <stdlib.h>

void sequencia (int vet[], int elementos, int i) {
    int aux = 0;
    while(i <= elementos)
    {
        aux = vet[i];
        vet[i] = vet[((elementos*2)-1)-i];
        vet[((elementos*2)-1)-i] = aux;
        printf("\n\n(%d troca com %d\n\n",vet[i], vet[((elementos*2)-1)-i]);
        sequencia (vet, elementos, ++i); 
    }
    
}

int main () {
    int elementos, i;
    printf("numero de elementos --> ");
    scanf("%d", &elementos);

    int vet[elementos+1];
    
    for ( i = 0; i < elementos; i++)
        printf("\n%d --> ", i+1),scanf("%d", &vet[i]);

    elementos/= 2, i=0;
    sequencia(vet, elementos, i);
    printf("\n\naqui %d %d %d %d",vet[0], vet[1], vet[2], vet[3]);
    
    return 0;
}