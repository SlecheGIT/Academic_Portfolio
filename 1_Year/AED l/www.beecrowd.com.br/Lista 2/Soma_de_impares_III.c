#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z, i, iy=0, r, soma=0;

    scanf("%d",&r);
    for (i=1 ;i<=r ;i++)
    {
        scanf("%d %d", &x, &y);
        z=x;
        while (iy<y)
        {
            if (z%2!=0)
            {
                soma=soma+z;
                iy++;;
            }
            z++;
        }
        printf("%d\n",soma);
        soma=0;
        iy=0;
    }

    return 0;
}
/*
2 - repetir programa
4 3 = 21
11 2 = 24
*/
