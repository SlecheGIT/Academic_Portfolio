#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <iomanip>
#include <vector>
#include <locale.h>

using namespace std;
using namespace std::chrono;

void clear()
{
    system("cls");
}
// void imprimir(vector<vector<float>> matriz, short linha /*, short int coluna*/);
// void imprimir_solucao(float solucao[], short linha);
// int teste_covergencia(vector<vector<float>> matriz, short n);
// int test_parada(short n, float solucao_atual[], float solucao_ini[], float precisao);
// void seidel(vector<vector<float>> matriz, short n, int teste, float solucao_ini[], float precisao);

void imprimir(vector<vector<float>> matriz, short linha /*, short int coluna*/)
{
    cout << "-------------------------------------------------------------" << endl;
    for (short int l = 0; l < linha - 1; l++)
    {
        for (short int c = 0; c < linha; c++)
            cout << "  " << matriz[l][c];
        cout << endl;
    }
    cout << "-------------------------------------------------------------\n"
         << endl;
}

void imprimir_solucao(float solucao[], short linha)
{
    cout << "-----------------------" << endl;
    for (short l = 0; l < linha - 1; l++)
        cout << "  " << solucao[l] << endl;
    cout << "-----------------------\n"
         << endl;
}

int teste_covergencia(vector<vector<float>> matriz, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        float diagonal_principal = matriz[i][i];
        float soma = 0.0, valor;

        for (int j = 0; j < n - 1; j++)
            if (i != j)
            {
                valor = matriz[i][j];
                if (valor < 0)
                    valor = -valor;

                soma += valor;
            }

        if (diagonal_principal < 0)
            diagonal_principal = -diagonal_principal;

        if (diagonal_principal <= soma)
            return 0;
    }
    return 1;
}

int test_parada(short n, float solucao_atual[], float solucao_ini[], float precisao)
{
    float maior_atual = 0;
    float maior_ini = 0;
    float parada = 0;

    for (int i = 0; i < n; i++)
    {
        if ((solucao_atual[i] > maior_atual) || ((solucao_atual[i] * -1) > maior_atual))
            maior_atual = solucao_atual[i];
    }
    if (maior_atual < 0)
        maior_atual = (maior_atual * (-1));

    for (int i = 0; i < n - 1; i++)
        if ((solucao_ini[i] > maior_ini) || ((solucao_ini[i] * -1) > maior_ini))
            maior_ini = solucao_ini[i];
    
    if (maior_ini < 0)
        maior_ini = (maior_ini * (-1));

    parada = ((maior_atual - maior_ini) / maior_atual);
    if (parada < 0)
        parada = (parada * -1);
    cout << "\nErro: " << parada << endl;

    if (parada < precisao)
        return 0;
    return 1;
}

void seidel(vector<vector<float>> matriz, short coluna, int teste, float solucao_ini[], float precisao)
{
    float solucao_atual[coluna - 1];
    int pivo;
    float aux[coluna - 1];
    int parada;

    if (teste == 0)
    {
        cout << "A matriz inicial nao converge";

        for (int i = 0; i < coluna - 1; i++)
        {
            pivo = i;

            for (int z = i + 1; z < coluna; z++)
                if (matriz[z][i] > matriz[pivo][i] || matriz[z][i] < -matriz[pivo][i])
                    pivo = z;


            if (pivo != i)
            { // troca de linha
                for (int j = 0; j < coluna; j++)
                {
                    float aux = matriz[i][j];
                    matriz[i][j] = matriz[pivo][j];
                    matriz[pivo][j] = aux;
                }
            }
            if (i < coluna - 1)
            {
                cout << "\n Matriz \n";
                imprimir(matriz, coluna);
            }

            teste = teste_covergencia(matriz, coluna);
            if (teste == 0)
            {
                cout << "Nao foi possivel garantir convergencia";
                return;
            }

            else if (teste == 1)
            {
                cout << "Matriz Final:\n";
                imprimir(matriz, coluna);
            }
        }
    }
    cout << "A matriz garante convergencia\n";
    int cont = 1;
    do
    {
        for (int i = 0; i < coluna - 1; i++)
        {

            aux[i] = solucao_ini[i];
        }
        for (int i = 0; i < coluna - 1; i++)
        {
            solucao_atual[i] = matriz[i][coluna - 1];
            // printf("%.7f\n",solucao_atual[i]);
            // aux[i]=0;
            for (int j = 0; j < coluna; j++)
            {
                if (j != i)
                {
                    solucao_atual[i] -= (aux[j] * matriz[i][j]);
                    // printf("%.7f\n",solucao_atual[i]);
                }
            }
            // printf("dd %.7f\n",solucao_atual[i]+ matriz[i][i]);
            solucao_atual[i] = ((solucao_atual[i]) / matriz[i][i]);
            // printf("cc %.7f\n",solucao_atual[i]);
            aux[i] = solucao_atual[i];
        }
        cout << "Solucao X("<< cont <<")\n";
        imprimir_solucao(solucao_atual, coluna);
        parada = test_parada(coluna, solucao_atual, solucao_ini, precisao);

        for (int j = 0; j < coluna - 1; j++)
            solucao_ini[j] = solucao_atual[j];

        cont++;

    } while (parada);
}

int main()
{

    short linha, coluna;
    float precisao;

    setlocale(LC_ALL, "Portuguese");
    cout << fixed << setprecision(7);

    do
    {
        system("cls");
        cout << "Insira a ordem da matriz (linha coluna): ";
        cin >> linha >> coluna;
        cout << endl;

        if ((linha > 10) || (coluna > 10) || (linha < 2) || (coluna < 2))
        {

            cout << "| Entradas incorretas! |\n2 <= ordem da matriz <= 10\n\n";
            system("pause");
        }

    } while (((linha > 10) || (coluna > 10)) || (linha < 2) || (coluna < 2));

    vector<vector<float>> matriz(linha, vector<float>(coluna));

    cout << "_______________________" << endl;
    cout << "|                     |";
    for (int l = 0; l < linha; l++)
    {
        cout << endl;
        for (short c = 0; c < coluna; c++)
        {
            if (c != coluna - 1)
                cout << "   A[" << l + 1 << "][" << c + 1 << "] = ";
            else
                cout << "      B[" << l + 1 << "] = ";
            cin >> matriz[l][c];
        }
    }
    cout << "|_____________________|\n"
         << endl;

    cout << "Insira a precis�o: ";
    cin >> precisao;
    float inicial[linha];

    cout << "\nInsira a solu��o inicial:\n";
    for (int i = 0; i < linha; i++)
    {
        cout << " X(0) [" << i + 1 << "]: ";
        cin >> inicial[i];
    }
    // clear();

    auto start = steady_clock::now(); // Contador de execu��o de incio

    cout << "\n A matriz Inicial de ordem (" << linha << " x " << coluna << ") �:\n";
    imprimir(matriz, coluna);

    int teste = teste_covergencia(matriz, coluna);

    seidel(matriz, coluna, teste, inicial, precisao);

    auto end = steady_clock::now() - start; // Contador de execu��o de fim
    cout << "\nTempo de execu��o: " << duration<float>{end}.count() << " ns\n\n";

    return 0;
}
