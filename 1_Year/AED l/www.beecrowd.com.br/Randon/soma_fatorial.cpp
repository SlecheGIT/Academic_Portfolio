#include <stdio.h>

int main () {
    long long int f1, f2, conta= 1; 
    int i=1, l;
    
    while(scanf("%lld %lld", &f1, &f2) != EOF) {

        while (i<=f1){
            conta*=i;
            i++;
        }
        f1=conta;
        conta=1;
        i=1;

        while (i<=f2){
            conta*=i;
            i++;
        }
        f2=conta;
        conta=1;
        i=1;
        printf("%lld\n", f1+f2);
    }
    
    return 0;
}