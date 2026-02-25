#include <stdio.h>

int main () {
    double a, b, c, a2, b2, c2;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (c>b) {
        a2 = b;
        b = c;
        c = a2;
    } if (b>a)
    {
        a2 = a;
        a = b;
        b = a2;
    } if (c>b) {
        a2 = b;
        b = c;
        c = a2;
    }
    a2=a*a;
    b2=b*b;
    c2=c*c;

    if (a>=(b+c)) {
        printf("NAO FORMA TRIANGULO\n");
        return 0;
    }
    if (a2==(b2+c2))
        printf("TRIANGULO RETANGULO\n");
    if (a2>(b2+c2))
        printf("TRIANGULO OBTUSANGULO\n");
    if (a2<(b2+c2))
        printf("TRIANGULO ACUTANGULO\n");
    if (a==b && b==c)
        printf("TRIANGULO EQUILATERO\n");
    else if (a==b || b==c || a==c)
        printf("TRIANGULO ISOSCELES\n");
    
    return 0;
}