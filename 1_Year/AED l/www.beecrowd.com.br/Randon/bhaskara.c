#include <stdio.h>
#include <math.h>

int main () {
    double a, b, c, delta;

    scanf("%lf %lf %lf", &a, &b, &c);
    delta= pow(b, 2) - 4 * a * c;
    if (delta>0 && a!=0)
    {
    delta = (-b + sqrt(delta)) / (2*a);
    printf("R1 = %.5lf\n", delta);

    delta= pow(b, 2) - 4 * a * c;
    delta = (-b - sqrt(delta)) / (2*a);
    printf("R2 = %.5lf\n", delta);

    return 0;
    } else
        printf("Impossivel calcular\n");
    
}