#include <stdio.h>

int main () {
 float sa, isento, oito, dezoito, vinte;

    scanf("%f",&sa);
    
    if (sa<=2000){
        printf("isento\n");
    } 
    if (sa>=2000.01 && sa<=3000)
    {
        sa= sa-2000;
        oito= (sa/100) * 8;
        printf("%.2f\n", oito);  
    }
    if (sa>=3000.01 && sa<=4500)
    {
        sa= sa-2000;
        dezoito= sa-1000;
        oito= sa-dezoito;
        oito= (oito/100) * 8;
        dezoito= (dezoito/100) * 18;
        printf("%.2f\n", dezoito+oito);
    }
    if (sa>=4500.01)
    {

       oito= (1000/100) * 8;
       dezoito= (1500/100) * 18;
       sa= (sa-4500);
       vinte= (sa/100) * 28;
       printf("R$ %.2f\n", vinte+dezoito+oito);
    }
 /*
3002.00 = R$ 80.36

1701.12 = Isento

4520.00 = R$ 355.60
 */   
return 0;
}
