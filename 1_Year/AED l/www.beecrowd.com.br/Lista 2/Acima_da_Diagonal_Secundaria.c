#include <stdio.h>

int main () {
    float m[12][12], resul;
    int l, c, i=0, cs=1;
    char sm;

    scanf("%c", &sm);

    for (l=0; l<12; l++)
    {
        for (c=0; c<12; c++)
            scanf("%f", &m[l][c]);
    }

    for (l=0; l<12; l++)
    {
        c=cs;
        cs++;
        while (c<12)
        {
            resul+=m[l][c];
            i++;
            c++;
        }
    }  
        
    if (sm=='M') 
        printf("%.1f\n", resul/i);

    else if (sm=='S')
        printf("%.1f\n", resul);

    return 0;
}