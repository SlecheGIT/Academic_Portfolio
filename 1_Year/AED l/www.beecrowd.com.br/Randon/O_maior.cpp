#include <stdio.h>

int main (){
    int n[3], maior=0, i=0;

    scanf("%d %d %d", &n[0], &n[1], &n[2]);

    while (i<3)
    {
        if (n[i]>maior)
            maior=n[i];

        i++;
    }
    printf("%d eh o maior\n", maior);

    return 0;
}