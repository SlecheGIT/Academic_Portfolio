#include <stdio.h>

int main (){
 int r[4], p[4], f=0, i;

   scanf("%d",&r[1]);
   scanf("%d",&r[2]);
   scanf("%d",&r[3]);

   scanf("%i",&p[1]);
   scanf("%i",&p[2]);
   scanf("%i",&p[3]);

   for (i=1; i<=3; i++){

    if (r[i]<p[i]) {
    f= (p[i] - r[i]) + f;   
    } 
   }

   printf("%d\n",f);

/*
80 20 40 -refeições
45 23 48 -passageiros
________
11

0 0 0 
100 100 100
_________
300

41 42 43
41 42 43
________
0
*/
   return 0;
}