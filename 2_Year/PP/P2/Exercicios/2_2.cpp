#include <iostream>
#include <vector>
using namespace std;
/*
Crie um template, usando o template vector, que adicione a funcionalidade de inserção de um
elemento no meio do vetore e operador []
*/
template <class T>
class vetor : private vector<T>
{
public:
    ~vetor(){ this->clear(); }

    size_t size() { return vector<T>::size(); }

    T &operator[](const T &indice) { return vector<T>::operator[](indice); }

    void inserir_meio(const T valor)
    {
        size_t tam = this->size();
        size_t i = tam / 2;
        this->push_back(valor);

        while (tam > i)
        {

            (*this)[tam] = (*this)[tam-1] ;
            --tam;
        }

        this->operator[](i) = valor;

    }
};

int main () {

    vetor<int> vet;

    vet.inserir_meio(1);
    vet.inserir_meio(1);
    vet.inserir_meio(1);
    vet.inserir_meio(1);
    vet.inserir_meio(5);


    size_t tam = vet.size();

    for (size_t i = 0; i < tam; i++)
    {
        cout << vet[i] << " , ";
    }
    return 0;
}

