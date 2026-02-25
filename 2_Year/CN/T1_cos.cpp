#include <iostream>
#include <math.h>
#include <chrono>
#include <locale.h>

#define PI 3.1415926
using namespace std::chrono;

void clear(){
    system("cls");
}

void cosseno(float x, short int termos);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    short int choice, termos = 100;
    float rad;

    do {
        clear();
        std::cout << "(1). radianos " << std::endl
                  << "(2). graus " << std::endl
                  << "(0). sair " << std::endl << "-> ";
        std::cin >> choice;
        clear();

        if ((choice == 1) || (choice == 2))
        {
            if (choice == 1)
                std::cout << "Insira o x em radianos: ";
            else
                std::cout << "Insira o x em graus: ";
            std::cin >> rad;

            std::cout << "Insira o numero de termos: ";
            std::cin >> termos;

            //
            auto start = steady_clock::now();
            {
            if (choice == 2)
                rad = (rad * PI) / 180.0;
            
            cosseno(rad, termos);
            } 
            auto end = steady_clock::now();
            auto time = end - start;
            //
            std::cout << "Tempo de execu??o: " << duration<float>{time}.count() << " ns\n\n";
            system("pause");
        }         
        else if ((choice < 0) || (choice > 2)){
            std::cout << "Escolha uma op??oo v?lida!" << std::endl << std::endl;
            system("pause");
        }

    } while (choice != 0);
    std::cout << "Encerrando o programa. . . " << std::endl << std::endl;

    return 0;
}

void cosseno(float x, short int termos){
    float fat, cos = 1.0;
    bool sinal = false;

    for (short int i = 2; i <= termos; i+=2)
    {
        fat = 1;
        for (short int f = 1; f <= i; f++)
            fat *= f;

        if (sinal == true)
            cos += pow(x, i) / fat;
        else 
            cos -= pow(x, i) / fat;
        sinal = !sinal;
    }
    std::cout << std::fixed << "\ncos(x): " << cos << std::endl;
    // std::fixed = erro pois independente da quantidade de aproximação ele nunca ficaria igual a 0, sempre o mais próximo possível
}
