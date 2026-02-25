#include <stdio.h>

int main (){
    char name[20];
    double money, sell;
    // ingles pq é menorzinho
    scanf("%s", &name);
    scanf("%lf %lf", &money, &sell);
    money += sell*0.15;
    printf("TOTAL = R$ %.2lf\n", money);

    return 0;
}