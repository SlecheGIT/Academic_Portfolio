#include <iostream>
#include <vector>

using namespace std;

/*
 Crie um template para representar um vetor ordenado, usando o template vector, com as
funcionalidades de inserção, remoção por valor e operador []
*/
template <class T>
class vetor_ordenado : private vector<T>
{
public:
    ~vetor_ordenado() { this->clear(); }

    size_t getsize() { return this->size()-1; }

    T& operator[](const size_t indice){
        return vector<T>::operator[](indice);
    }

    void inserir(const T &x) {
        this->push_back(x);
        size_t tam = this->size()-1;
        size_t i = 0;

        while ((x > this->operator[](i)) && (i <= tam))
            i++;
        
        while (tam > i)
        {
            this->operator[](tam) = this->operator[](tam-1);
            tam--;
        }
        this->operator[](i) = x;

    }

    void remover(const T &x) {
        size_t tam = this->size()-1;
        size_t i = 0;
        bool pertence = false;
        vector<T> aux;

        while (i <= tam){
            if(x != this->operator[](i)){
                aux.push_back(this->operator[](i));
            } 
            else   
                pertence = true;
            i++;
        }
        this->clear();
        if(pertence)  
        {
            for ( i = 0; i < tam; i++)
                this->push_back(aux.operator[](i));
            aux.clear();
        }
        else
            cout << "valor nao contido na lista\n";
    }

};

int main () {
    vetor_ordenado<int> vetor;

    vetor.inserir(3);
    vetor.inserir(2);
    vetor.inserir(9);
    vetor.inserir(1);

    vetor.remover(9);
    
    size_t tam = vetor.getsize();

    for (size_t i = 0; i <= tam; i++)
    {
        cout << " -> [" <<  vetor[i] << "]";
    }
    cout << endl;
    return 0;
}