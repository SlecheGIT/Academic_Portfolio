#include <stdio.h>

int main () {
    float distancia, consumo;

    scanf("%f %f", &distancia, &consumo);
    printf("%.3f km/l", distancia/consumo);
    return 0;
}