#include <stdio.h>

int main () {
    char especie1[12], especie2[12], especie3[12];

    scanf("%s", &especie1);
    scanf("%s", &especie2);
    scanf("%s", &especie3);
    
    if (especie1=="vertebrado") 
    {
        if (especie2=="ave") 
        {
            scanf("%s", &especie3);
            if (especie3 =="carnivoro") printf("aguia\n");
            else printf("pomba\n");

        } else {
            if (especie3 =="onivoro") printf("homem\n");
            else printf("vaca\n");
        }
        
    }
    
    return 0;
}