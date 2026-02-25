#include <stdio.h>
#include <math.h>

int main() {
    int t, n;
    scanf("%i", &t);
    
    while (t--) {
        scanf("%i", &n);
        printf("%i\n",(int) pow(2, n) - 1);
    }

    return 0;
}