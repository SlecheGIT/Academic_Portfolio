#include <stdio.h>

int main () {
    long int senha;
    while((scanf("%ld", &senha) != EOF))
        printf("%ld\n", senha-1);
    return 0;
}