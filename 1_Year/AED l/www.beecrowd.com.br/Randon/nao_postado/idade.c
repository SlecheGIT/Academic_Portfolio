#include <stdio.h>

int main () {
    float idade, cont=0, media;

    while (1){
        scanf("%f", &idade);
        if (idade<0)
            break;
        else
        media+= idade;
        cont++;
    }
    printf("%.2f\n", media / cont);
    return 0;
}