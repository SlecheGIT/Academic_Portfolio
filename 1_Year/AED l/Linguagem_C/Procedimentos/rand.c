#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int n;
    srand(time(NULL));
    for (int i=0; i<5; i++){
        n= rand() % 10;
        printf("%d\n", n);
    }

    for (int i=0; i<5; i++){
        n= rand() % 9;
        printf(".  %d\n", n);
    }
    return 0;
}