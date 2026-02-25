#include <iostream>

using namespace std;

int main () {
    int ant=0, atu=1, dep, i, r, resul[40];

    scanf("%d", &r);

    for (i=0; i<r; i++)
    {
        resul[i]=atu;
        dep= ant+atu;
        ant=atu;
        atu=dep;
    }
    r--;
    for (i=0; i<r; r--){
        printf("%d ", resul[r]);
    }
    printf("%d\n", resul[0]);

    return 0;
}