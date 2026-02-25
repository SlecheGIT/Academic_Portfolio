#include <stdio.h>

int main () 
{
int i, jm=7, jc, j=7;

    for (i=1; i<=9; i=i+2)
    {
       jc=1; 
       while (jc<=3)
       {
            printf("I=%i J=%i\n", i, j);
            j=j-1;
            jc++;
       }
       jm=jm+2;
       j=7;
    }
  
}