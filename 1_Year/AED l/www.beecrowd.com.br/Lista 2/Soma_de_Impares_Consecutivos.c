#include <stdio.h>

int main () {
 int x, y, soma=0;

    scanf("%d", &x);
    scanf("%d", &y);

    if (y>x)
    {
        soma=x;
        x=y;
        y=soma;
        soma=0;
    }
    y++;
        while (y!=x)
        {
            if (y%2 != 0)
            {
                soma= soma+y;
            }
            y++;
        }
    
      printf("%i\n", soma);
      return 0;
}
/*

 6
-5
__
 5

15
12
__
13

12
12
__
0
*/