#include <stdio.h>
#include <string.h>

int main()
{
    int i, cont;
    char name[10100];
    scanf("%d", &i);
    while(i--)
    {
        scanf("%s", name);
        cont = strlen(name);
        printf("%.2lf\n", cont*.01);
    }
    return 0;
}