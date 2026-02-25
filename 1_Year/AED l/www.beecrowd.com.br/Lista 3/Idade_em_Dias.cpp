#include <stdio.h>

int main ()
{
    int anos, messes, dias, n;

    scanf("%d", &n);
    anos=n/365;
    messes=(n%365)/30;
    dias=(n%365)%30;

    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", messes);
    printf("%d dia(s)\n", dias);
    return 0;
}