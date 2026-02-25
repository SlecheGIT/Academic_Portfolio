#include <stdio.h>

int main()
{
    int x[10], i=0;

    while (i<10)
    {
        scanf("%d", &x[i]);
        if (x[i]<=0)
        {
            x[i]=1;
        }

        printf("X[%d] = %d\n", i, x[i]);
        i++;
    }
    return 0;
}
/*
0 | X[0] = 1
-5 | X[1] = 1
63 | X[2] = 63
0 | X[3] = 1
*/
