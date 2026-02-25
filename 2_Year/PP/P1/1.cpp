#include <iostream>
#include <cmath>
using namespace std;
//Erro:falta destrutor
template <typename T>
struct FIFO
{
    T valor;
    FIFO *prox;
};

template <typename T>
class fila
{
private:
    FIFO<T> *inicio;
public:
    fila(){ inicio = NULL; }

    void inserir_fim (T val) {
        FIFO<T> *novo = new FIFO<T>();
        novo->valor = val;
        novo->prox = NULL;

        if (inicio != NULL) {

            FIFO<T> *pont = inicio; // pont de ponteiro
            while (pont->prox != NULL)
                pont = pont->prox;
            pont->prox = novo;
        }
        else 
            inicio = novo;
    }   

    void remover_inicio() {

        FIFO<T> *pont = inicio; // pont de ponteiro

        if (pont->prox != NULL)
        {
            inicio = inicio->prox;
            delete pont;
        } 
        else {
            inicio = NULL;
            delete pont;
        }
    }

    T &operator[] (int indice) {//erro: retorno apenas para leitura
        FIFO<T> *pont = inicio; // pont de ponteiro
        int i = 0;

        while ((i < indice) && (pont != NULL))
        {
            ++i;
            pont = pont->prox;
        }
        if (pont == NULL) { cout << "erro no indice"; }
        return pont->valor;
    }

    int getsize() {//erro:const
        FIFO<T> *pont = inicio; // pont de ponteiro
        int i = 0;
        while (pont != NULL)
        {
            i++;
            pont = pont->prox;
        }
        return i;
    }
}; 


int main () {
    fila<float> lista;
    int limite;

    lista.inserir_fim(1);
    lista.inserir_fim(2);
    lista.inserir_fim(3);
    lista.inserir_fim(4);
    cout << endl;

    limite = lista.getsize();
    cout << "insercao: ";
    for (int i = 0; i < limite; i++)
        cout << "-> [ " << lista[i] << " ] ";
    cout << endl;

    lista.remover_inicio();
    lista.remover_inicio();
    limite = lista.getsize();
    lista[1] = 44;
    cout << "remocao: ";
    for (int i = 0; i < limite; i++)
        cout << "-> [ " << lista[i] << " ] ";
    cout << endl;



    cout << endl;
    return 0;
}

