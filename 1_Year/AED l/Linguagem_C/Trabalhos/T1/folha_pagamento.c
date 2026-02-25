#include <stdio.h>

int main () {
    int n=0, m=0;
    int t=0;
    
        printf("Digite o numero de funcionarios: ");
        scanf("%d", &n);
        while (n<1 || n>10000) {
            if (n<1 || n>10000)
                printf("\nNumero tem que ser >= 1 ou <= 10^4\nDigite Novamente: ");
            scanf("%d", &n);
        }
        
        for (int i = 1; i <= n; i++)
        {   
            printf("digite o numero da matricula: ");
            scanf("%d", &m);
            while (m<1 || m>30000) {
                if (m<1 || m>30000)
                    printf("\nNumero tem que ser >= 1 ou <= 3*(10^4)\nDigite Novamente: ");
                scanf("%d", &m);
            }
            for (int r = 1; r <= m; r++) {
                if (m % r == 0)
                    t+=r;
            }
            printf(" --> %d\n", t);
            t=0;
        }

    return 0;
}