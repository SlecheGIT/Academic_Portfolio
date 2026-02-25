#include <stdio.h>

void teste (int *di){
    ++*di;
    
}

int main () {
    char dir[][2] = {"abc"};
    char *pi = &dir[0][0];

    // for (int i = 0; i < 3; i++)
    // {
    //     pi[3] = &dir[i];
    // }
    
    printf("\n%c", *pi);
    teste(pi);

    return 0;
}