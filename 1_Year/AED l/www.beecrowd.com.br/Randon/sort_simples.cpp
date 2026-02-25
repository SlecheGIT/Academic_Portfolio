#include <stdio.h>

int main()
{
    int a, b, c, aux;
    int x, y, z;

    scanf("%d %d %d", &a, &b, &c);
    x=a;
    y=b;
    z=c;

    if (c < b) {
        aux = b;
        b = c;
        c = aux;
    }

    if (b < a) {
        aux = a;
        a = b;
        b = aux;
    }
    
     if (c < b) {
        aux = b;
        b = c;
        c = aux;
    }

    printf("%d\n%d\n%d\n\n%d\n%d\n%d\n",a,b,c,x,y,z);

    return 0;
}