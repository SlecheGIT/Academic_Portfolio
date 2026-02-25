#include <stdio.h>

int main () {

    int r;
    scanf("%d", &r);
    char toorg[200][r];
    for (int i = 0; i < r; i++)
    {
        scanf("%s", &toorg[0][r]);
        printf("I am Toorg!\n");
    }
    
    return 0;
}