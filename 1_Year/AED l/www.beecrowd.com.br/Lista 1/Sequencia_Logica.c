#include <stdio.h>
 
int main() {
int i, n;

    scanf("%i", &n);
    
    for (i=1; i<=n; i++) {
        printf("%i %i %i\n",i ,i*i , i*i*i);
        printf("%i %i %i\n",i ,(i*i)+1, (i*i*i)+1);
    }
    /**
1 1 1
1 2 2
2 4 8
2 5 9
3 9 27
3 10 28
4 16 64
4 17 65
5 25 125
5 26 126
     */
    return 0;
}