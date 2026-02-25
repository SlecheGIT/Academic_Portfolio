#include <stdio.h>
 
int main() {
 int p, r;

    scanf("%i",&p);
    scanf("%i",&r);

    if ((p==1) && (r==1)) {
      printf("A\n");
    } else if (p==1 && r==0) {
      printf("B\n");
    } else if (p==0) {
      printf("C\n");
    }
 /*
1 1 = A
1 0 = B
0 0 = C
 */
    return 0;
}