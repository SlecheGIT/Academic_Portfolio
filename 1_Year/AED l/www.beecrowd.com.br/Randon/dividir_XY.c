#include <stdio.h>

int main () {
    int i;
    float x=0, y=0;

    scanf("%d", &i);
    for(int r=0; r<i; r++)
    {
        scanf("%f %f", &x, &y);
        if (y==0)
            printf("divisao impossivel\n");
        else
            printf("%.1f\n", (x/y));
        
    }
    return 0;
}