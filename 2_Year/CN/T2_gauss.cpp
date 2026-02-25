#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <locale.h>

using namespace std;
using namespace std::chrono;

void imprimir(vector<vector<float>> matriz, short int linha, short int coluna) {
    cout << "-----------------------" << endl;
    for (short int c = 0; c < coluna; c++) {
        for (short int l = 0; l < linha; l++)
            cout << "  " << matriz[l][c];
        cout << endl;
    }
    cout << "-----------------------\n" << endl;
}

int maior_pivo(vector<vector<float>> &matriz, short int inicio, short int linha, short int coluna) {
    float aux, maior = 0;
    short int linha_maior = inicio;
    int swap = 0;

    for (short int l = inicio; l < linha; l++) {
        aux = matriz[inicio][l]; // inverção de linhas e colunas por motivos desconhecidos
        if (aux < 0)
            aux *= -1;
        
        if (aux > maior) {
            maior = aux;
            linha_maior = l;
        }    
    }

    if (linha_maior != inicio) {
        for (short int c = 0; c < coluna; c++) {
            aux = matriz[c][inicio];
            matriz[c][inicio] = matriz[c][linha_maior];
            matriz[c][linha_maior] = aux;
        }
        ++swap;
        cout << "\nLinha " << inicio+1 << " = linha " << linha_maior+1 << endl;
        cout << "Linha " << linha_maior+1 << " = linha " << inicio+1 << endl;
        imprimir(matriz, linha, coluna);
    }
    return swap;
}

void calcular_gauss(vector<vector<float>> &matriz, short int linha, short int coluna, short int pivo, int *swap) {
    float m = 0;

    if (pivo < linha) {
        (*swap) += maior_pivo(matriz, pivo, linha, coluna);

        for (short l = pivo+1; l < linha; l++) {
            if (matriz[pivo][l]) {
                m = (matriz[pivo][l] * -1.0) / matriz[pivo][pivo];

                for (short c = 0; c < coluna; c++)
                    matriz[c][l] = (m * matriz[c][pivo]) + matriz[c][l];

                cout << "\n(Linha " << l+1 << " = " << m << " * linha " << pivo+1 << " + linha " << l+1 << ")\n"; 
                imprimir(matriz, linha, coluna);
            }
        }
        calcular_gauss(matriz, linha, coluna, pivo+1, swap);
    }
}

void determinante(vector<vector<float>> &matriz, short int linha, short int coluna, int swap) {
    if (linha == coluna) {
        float det = matriz[0][0];
        for (short i = 1; i < coluna; i++) {
            if (matriz[i][i] == 0)
                cout << "Determinante = Sistema indeterminável\n";
        
            det *= matriz[i][i];
        }
        while (swap-- != 0)
            det *= -1;
    
        cout << "Determinante = " << det << endl;
    } else
        cout << "Impossível calcular determinante (matriz não quadrática)\n";
}

int main() {
    short int linha, coluna;
    short int i;
    int swap = 0;
    
    setlocale(LC_ALL, "Portuguese");
    cout << fixed << setprecision(1);

    do {
        system("cls");
        cout << "Insira a ordem da matriz (linha coluna): ";
        cin >> linha >> coluna;
        cout << endl;

        if ((linha > 10) || (coluna > 10) || (linha <= 2) || (coluna <= 2)){

            cout << "| Entradas incorretas! |\n2 <= ordem da matriz <= 10\n\n";
            system("pause");
        }

    } while (((linha > 10) || (coluna > 10)) || (linha <= 2) || (coluna <= 2));

    vector<vector<float>> matriz(linha, vector<float>(coluna));

    // Inser??o da matriz
    cout << "_______________________\n" << endl;
    
    for (int cursor = 0; cursor < coluna; cursor++) {
        for (i = 0; i < linha; i++) {
            cout << "  x[" << cursor+1 << "] [" << i+1 << "] : ";
            cin >> matriz[i][cursor];
        }
        cout << endl;
    }
    cout << "|______________________|\n\n" << endl;

    auto start = steady_clock::now(); // Contador de execução de início

    calcular_gauss(matriz, linha, coluna, 0, &swap);
    
    determinante(matriz, linha, coluna, swap);

    auto end = steady_clock::now() - start; // Contador de execução de fim
    cout << "\nTempo de execução: " << end.count() << " ns\n\n";
    
    return 0;
}
