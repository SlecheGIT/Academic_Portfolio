#include <stdio.h>

int main () {
    int i=1, t=0, cc=0, maria=0, jao=0;

    while (i!=0)
    {
        scanf("%d", &i);
        t=i;
        while (t>0)
        {
            scanf("%d", &cc);
            if (cc==0)
                maria++;
            else  
                jao++;
            t--;
        }
        if (i!=0){
            printf("Mary won %d times and John won %d times\n", maria, jao);
            maria=0;
            jao=0;
        }
    }
    return 0;
}