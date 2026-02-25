#include <iostream>
#include <stdio.h>
#include <math.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct ponto
{
    int a;
    int b;
};

void BuscaRaiz(ponto &intervalo, float constante[], int &n){

    float fx, ant=0;
    bool raiz = false;

    for (int i = intervalo.a; i < intervalo.b; i++)
    {     
        fx = 0;

        for (int xn = 0; xn <= n; xn++)
        {
            fx += constante[xn] * pow(i, xn);
        }

        if (i!= intervalo.a)
        {
            if (fx == 0 )
            {
                if (raiz == false)
                {
                    printf("Raiz dentro dos intervalo: \n");
                    raiz = true;
                }
                printf("\nRaiz no ponto: (%d, 0) --> F(X) = (%.7f) \n", i, fx);
            }
            else
            if (fx * ant <= 0 && ant != 0)
            {
                
                    if (raiz == false)
                    {
                        printf("Raiz dentro dos intervalo: \n");
                        raiz = true;
                    }
                    printf("\n(a,b) = (%d, %d)", i-1, i);
                    printf(" [ --> ] (F(%d) = %.7f , F(%d) = %.7f) \n", i-1,  ant, i, fx);
                
            }
            
        }
        ant = fx;
    }
    if(raiz == false)
        cout<< "Nao houve ocorrencia de raiz nesse intervalo\n";
}

int main () {
    ponto intervalo;
    int n;
    
    cout << "Insira o grau da funcao: ";
    cin >> n;
    cout << "Insira o intervalo a e b: ";
    cin >> intervalo.a >> intervalo.b;

    float constante[n+1];

    cout << "Insira as constantes que multiplicam: \n";
    for (int i = 0; i <= n; i++){
        cout << "\n X^"<< i <<" = ";
        cin >> constante[i];
    }
    cout << endl;

    printf("-------------------------------------");
    printf("\nF(X) = %.2f(X^%i)", constante[n], n);
    for (int i = n-1; i >= 0; i--){
        if (constante[i] > 0 )
            printf(" + %.2f(X^%i)", constante[i], i);
        else
            printf(" - %.2f(X^%i)", -constante[i], i);
    }
    cout << endl << endl;

    auto start = steady_clock::now();

    BuscaRaiz(intervalo, constante, n);

    auto time_exe = steady_clock::now() - start;
    cout << "\nTempo de execucao: " << time_exe.count() << "/ns\n";

    printf("-------------------------------------\n\n");
   
}