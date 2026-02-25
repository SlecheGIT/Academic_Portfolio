#include <stdio.h>

int main () {
    int i=0, r=1, quant, ant=0, n, iv=0;

    while(scanf("%d", &quant) != EOF){
        int vet[quant];
        while (i<quant)
        {
            scanf("%d", &n);
            if (ant==n)
            {
                vet[iv]=ant;
                iv++;
            }
            ant+=n;
            i++;
        }
        i=0;
        if (iv==0){
            printf("Instancia %d\n", r);
            printf("nao achei\n");
            printf("\n");
        }
        else {
            printf("Instancia %d\n", r);
            while (i<iv) {
                printf("%d\n", vet[i]);
                i++;
            }
            printf("\n");
        }
        r++;
        i=0;
        iv=0;    
        ant=0;
    } 

    return 0;
}