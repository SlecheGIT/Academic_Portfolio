#include <stdio.h>
 
int main() {
 int t1, t2, t3, t4, t;

 scanf("%i", &t1);
 scanf("%i", &t2);
 scanf("%i", &t3);
 scanf("%i", &t4);

t= (t1-1)+(t2-1)+(t3-1)+t4;

printf("%i\n",t);

/**  
2 4 3 2 = 8

6 6 6 6 = 21

2 2 2 2 = 5  
*/
    return 0;
}