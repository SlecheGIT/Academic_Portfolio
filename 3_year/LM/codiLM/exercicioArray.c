#include <stdio.h>
#include <stdlib.h>


int main() {
    // Ex 13 maio    
    // Prova : Array alocado em pilha e alocação dinâmica -- Fazer em Mips

    int v1[10], v2[10], i;

    for (i = 0; i < 10; ++i) {
        scanf("%d", v2[i]);
    }

    for (i = 0; i < 10; ++i) {
        v2[i] = v1[9 - i]; // Inverter o array
    }

    for (i = 1; i < 10; ++i) {
        v1[i] = v1[i] + v1[i - 1]; // v1[i] <- SOMATÓRIA v1[i]
    }

    for (i = 0; i < 10; ++i) {
        printf("%d ", v1[i]);
    }

    for (i = 0; i < 10; ++i) {
        printf("%d ", v2[i]);
    }

    return 0;
}
