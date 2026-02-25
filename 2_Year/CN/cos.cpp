#include <iostream>
#include <math.h>

void radianos ();

// int graus();

int main()
{
    int choise;

    do {
        // std::cout << "(1). radianos " << std::endl
        //           << "(2). graus " << std::endl
        //           << "(3). sair " << std::endl;
        // std::cin >> choise;

        choise = 1;

        system("cls");
        switch (choise)
        {
        case 1:
            radianos();
            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        default:
             std::cout << "Escolha uma opcao valida" << std::endl << std::endl;
            break;
        }
    } while (choise != 3);

    return 0;
}


void radianos (){
    double fat = 1;
    double x;
    double cos = 1;
    bool sinal = false;

    std::cout << "insira o x em radianos: ";
    std::cin >> x;
    
    for (int i = 2; i <= 20; i+=2)
    {
        fat = 1;
        for (float f = 1; f <= i; f++)
            fat*=f;


        if (sinal == true)
            cos += pow(x, i) / fat;
        else 
            cos -= pow(x, i) / fat;

        sinal = !sinal;

        std::cout << "cos: " << cos << std::endl << std::endl;

        std::cout << "x: " << x << std::endl;
        // std::cout << "fatorial: " << fat << std::endl;
        // std::cout << "pow: " << cos << std::endl << std::endl;
        
        
    }
    system("pause");
}



