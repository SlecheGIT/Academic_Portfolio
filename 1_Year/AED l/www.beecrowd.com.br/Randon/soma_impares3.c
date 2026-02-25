#include <stdio.h>

int main () {
    int r, i=0, s, f, media=0, aux=0;

    scanf("%d", &r);
    while (i<r)
    {
        scanf("%d %d", &s, &f);
        if (s>f) 
        {
            aux=s;
            s=f;
            f=aux;
        }
        s++;
        while (s<f)
        {
            if (s%2!=0)
                media+=s;
            s++;
        }
        printf("%d\n", media);
        media=0;
        i++;
    }
    
    return 0;
}