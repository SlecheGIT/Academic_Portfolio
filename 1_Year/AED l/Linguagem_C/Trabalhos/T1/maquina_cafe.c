#include <stdio.h>


int main () {
    int ou=0;
    int func1=-1, func2=-1, func3=-1;
    int a1, a2, a3;

    printf("Digite a quantidade de funcionarios do primeiro, segundo e terceiro respectivamente:\n");
    scanf("%i %i %i", &func1, &func2, &func3);
    while ((func1<0 || func1>1000) || (func2<0 || func2>1000) || (func3<0 || func3>1000) )
    {
        printf("Entrada eh menor que 0 ou maior que 1000, ou entrada inexistente\n Digite todos novamente: ");
        scanf("%i %i %i", &func1, &func2, &func3);
    }
    
    //entrada de dados e calculando tempo e ate cada andar
    a1 = (func3 * 4) + (func2 * 2);
    a2 = (func1 * 2) + (func3 * 2);
    a3 = (func1 * 4) + (func2 * 2);
    
    if ((a1 < a2) && (a1 < a3)) 
        printf("Tempo: %d\n", a1);
    if ((a2 <= a1) && (a2 <= a3)) 
        printf("Tempo: %d\n", a2);
    if ((a3 < a1) && (a3 < a2)) 
        printf("Tempo: %d\n", a3);
        
    //impressão na tela
    printf("Maquina localizada no(s) andar(es): ");
    if ((a1 <= a2) && (a1 <= a3)) {
        printf("1");
        ou=1;
    }
    if ((a2 <= a1) && (a2 <= a3)) {
        printf(" ");
        if (ou==1)
            printf("OU ");
        printf("2");
        ou=1;
    }
    if ((a3 <= a1) && (a3 <= a2)) { 
        printf(" ");
        if (ou==1)
            printf("OU ");
        printf("3");
    }
    printf("\n");
    return 0;
}