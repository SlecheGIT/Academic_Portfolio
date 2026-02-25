#include <stdio.h>
#include <math.h>

int main()
{
    double n = 3.14159, raio, resul;

    scanf("%lf", &raio);
    resul = n * (pow(raio, 2));

    printf("A=%.4lf", resul);

    return 0;
}