#include <stdio.h>

int main () {
    int r, n, dois=0, tres=0, quatro=0, cinco=0;

    scanf("%d", &r);
    for (int i=0; i<r; i++)
    {
        scanf("%d", &n);
        if (n%2==0)
            dois++;
        if (n%3==0)
            tres++;
        if (n%4==0)
            quatro++;
        if (n%5==0)
            cinco++;
    }
    printf("%d Multiplo(s) de 2\n", dois);
    printf("%d Multiplo(s) de 3\n", tres);
    printf("%d Multiplo(s) de 4\n", quatro);
    printf("%d Multiplo(s) de 5\n", cinco);
    return 0;
}