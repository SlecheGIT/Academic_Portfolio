#include <iostream>
#include <vector>

using namespace std; 

class Array : vector<int>
{
private:
    /* data */
public:
    Array() {
        this->clear();
    }

    ~Array() { 
        this->clear();
    }

    void inserir(int valor)
    {
        unsigned t = this->size();
        unsigned count = 0;
        this->push_back(valor);

        while ((this->operator[](count) < valor) && (count < t))
            count++;

        while (t > count)
        {
            (*this)[t] = (*this)[t-1];
            --t;
        }
        this->operator[](count) = valor;
    }

    void remover(int valor)
    {
        size_t t = this->size() -1;
        size_t i = 0;
        while ((this->operator[](i) != valor) && (i < t))
            i++;
        while (i < t)
        {
            this->operator[](i) = this->operator[](i+1);
            i++;
        }
        
    }

    void exibir() 
    {
        unsigned t = this->size();
        unsigned i = 0;

        while (i < t)
        {
            cout << this->operator[](i) << " , ";
            i++;
        }
        cout << endl << endl;
    }
};

int main () {

    Array lista;

    lista.inserir(1);
    lista.inserir(2);
    lista.inserir(3);
    lista.inserir(4);
    lista.inserir(5);

    lista.exibir();
    return 0;
}