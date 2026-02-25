#include <stdio.h>
#include <string.h>
int main()
{
    int n, abas;
    char temp[10];
    scanf("%d %d", &n, &abas);
    int cnt = n;
    while(abas--)
    {
        scanf("%s", temp);
        if(temp[0] == 'f') cnt++;
        else cnt--;
    }
    printf("%d\n", cnt);
    return 0;
}