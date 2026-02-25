#include <stdio.h>
 
int main() 
{
    float s2[3], s1[3], b2[3], b1[3], a2[3], a1[3], s[] = {0, 0}, b[] = {0, 0}, a[] = {0, 0};
    int i=0, r;
    char name[20];

    scanf("%d",&r);
    while (i<r)
    {
        scanf("%s", &name);//????????????
        scanf("%f %f %f", &s1[i], &b1[i], &a1[i]);
        scanf("%f %f %f", &s2[i], &b2[i], &a2[i]);

        s[0]= s[0]+s1[i];
        s[1]= s[1]+s2[i];
        b[0]= b[0]+b1[i];
        b[1]= b[1]+b2[i];
        a[0]= a[0]+a1[i];
        a[1]= a[1]+a2[i];
        i++;
    }
    printf("Pontos de Saque: %.2f %%.\n", (s[1] / s[0])*100.0);
    printf("Pontos de Bloqueio: %.2f %%.\n", (b[1] /b[0])*100.0);
    printf("Pontos de Ataque: %.2f %%.\n", (a[1] / a[0])*100.0);
    
    return 0;
}