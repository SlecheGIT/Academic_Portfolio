#include <stdio.h>

int main () {
    int i;
    float n1, n2, n3;

    scanf("%d", &i);
    for (int r=0; r<i; r++){
        scanf("%f %f %f", &n1, &n2, &n3);
        printf("%.1f\n", (n1*0.2)+(n2*0.3)+(n3*0.5));
    }
    
    return 0;
}