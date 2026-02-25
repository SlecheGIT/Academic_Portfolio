#include <stdio.h>

int main()
{
    float n[4], exame, media;

    scanf("%f %f %f %f", &n[0], &n[1], &n[2], &n[3]);
    media = ((n[0]*2) + (n[1]*3) + (n[2]*4) + n[3]) / 10;
    printf("Media: %.1f\n", media);

    if (media>=7)
        printf("Aluno aprovado.\n");

    if (media>5.0 && media<7.0)
    {
        printf("Aluno em exame.\n");
        scanf("%f", &exame);
        printf("Nota do exame: %.1f\n", exame);
        
        media= (media + exame) / 2;

        if ((media)<5)
            printf("Aluno reprovado.\n");

        else if (media>=5)
            printf("Aluno aprovado.\n");

    printf("Media final: %.1f\n", media);
        
    } else if (media<5.0) 
        printf("Aluno reprovado.\n");
    
    return 0;
}