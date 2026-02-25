#include <stdio.h>

int main()
{
    double a, b, c, calc;
    scanf("%lf %lf %lf", &a, &b, &c);

    calc = (a / 2) * c;
    printf("TRIANGULO: %.3lf\n", calc);

    calc = (c * c) * 3.14159;
    printf("CIRCULO: %.3lf\n", calc);

    calc = ((a+b) * c) / 2;
    printf("TRAPEZIO: %.3lf\n", calc);

    calc = b*b;
    printf("QUADRADO: %.3lf\n", calc);

    calc = a*b;
    printf("RETANGULO: %.3lf\n", calc);

        return 0;
}