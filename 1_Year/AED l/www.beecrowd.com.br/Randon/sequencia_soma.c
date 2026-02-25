#include <stdio.h>

int main () {
    int i=0, s=1, f=1, media=0, aux;

    while (s>0 || f>0)
    {
        scanf("%d %d", &s, &f);
        if (s>0 && f>0)
        {
            if (s>f) 
            {
                aux=s;
                s=f;
                f=aux;
            }
            while (s<=f)
            {
                printf("%d ", s);
                media+=s;
                s++;
            }
            printf("Sum=%d\n", media);
            media=0;
        }
        else 
            return 0;

    }
}