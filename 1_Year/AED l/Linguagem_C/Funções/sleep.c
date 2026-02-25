#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <stdlib.h>

int main () {
    bool pause = true;

    if (pause == true)
    {
        pause = false;
        printf("\nRetornando ao menu");
        usleep(400000);
        for(int k=0; k<3 ;k++){
        printf(" .");
        usleep(400000);
        }
    }
    return 0;
}