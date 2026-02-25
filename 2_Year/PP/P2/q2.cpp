/*
Assuma que o template vector possui apenas os procedimentos listados abaixo:

    - size_type size() const; // Numero de elementos
    - reference operator[](size_type n); // operador[]
    - void push_back(const value_type& val); // Insere na ultima posição
    - void clear(); // Elimina todos os elementos

Crie um template, usando o template vector, que adicione a funcionalidade
de inserção no meio do vetor e operador [].
*/

#include <iostream>
#include <vector>
    
using namespace std;

template <class T>
class Vetor : private vector<T> {
public:
    ~Vetor() {
        this->clear();
    }

    size_t getSize() const {
        return this->size();
    }

    T& operator[](size_t index) {
        return vector<T>::operator[](index);
    }

    void inserir(const T valor) {
        if (this->size() < 2) {
            this->push_back(valor);
            return;
        }

        vector<T> temp;
        // Criar um novo vetor e insere o valor desejado no meio
        for (size_t i = 0; i < this->size(); i++) {
            if (i == this->size() / 2) {
                temp.push_back(valor);
            }

            temp.push_back((*this)[i]);
        }

        this->clear(); // Limpa o vetor atual

        // Substitui o vetor atual pelo vetor novo vetor
        for (size_t i = 0; i < temp.size(); i++) {
            this->push_back(temp[i]);
        }
    }
};

int main() {
    Vetor<int> vet;

    vet.inserir(7);
    vet.inserir(5);
    vet.inserir(2);
    vet.inserir(10);
    vet.inserir(1);
    vet.inserir(4);

    cout << "Vetor: ";
    for (size_t i = 0; i < vet.getSize(); i++) {
        cout << vet[i] << " ";
    }
    cout << endl;

    return 0;
}
