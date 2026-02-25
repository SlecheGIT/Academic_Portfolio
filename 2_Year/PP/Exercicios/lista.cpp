#include <iostream>
using namespace std;

template <typename T>
struct deque {
  T x;
  deque *prox;
};

template <typename T> 
class Lista {
private:
    deque<T> *inicio;

public:
    Lista(){
        inicio = NULL;
    }

    void inserir_back(T valor){
        deque<T> *novo = new deque<T>();  
        novo->x = valor;

        if (inicio != NULL) {
            novo->prox = inicio;        
            inicio = novo; 
        }
        else {         
            novo->prox = NULL;        
            inicio = novo;              
        }
    }
    void inserir_front(T valor) {
        deque<T> *novo = new deque<T>();  
        deque<T> *p = inicio;
        novo->x = valor;
        novo->prox = NULL;     

        if (inicio != NULL) {

            while (p->prox != NULL)
                p = p->prox;
            p->prox = novo;
        }
        else       
            inicio = novo;              
        
    }

    void remove_back(){

        if (inicio != NULL){
            deque<T> *p = inicio;
            if (inicio->prox != NULL)
                inicio = inicio->prox;
            else
                inicio = NULL;
            delete p;
        } 
    }
    void remove_front(){

        deque<T> *p = inicio;
        int i = 1, cont = 0;

        while (p->prox != NULL){
            p = p->prox;
            cont++;
        }
        delete p;
        p = inicio;
        while (i < cont){
            p = p->prox;
            i++;    
        }
        p->prox = NULL;
        
    }
    void exibir() {
        deque<T> *p = inicio;

        if (p != NULL)
        {
            while (p != NULL)
            {
                cout << "-> [" << p->x <<"] ";
                p = p->prox;
            }
            cout << endl;
        }
    }

    T operator[](int vet){

        deque<T> *p = inicio;
        int i = 0;
        while ((i != vet) && (p->prox != NULL))
        {
            i++;
            p = p->prox;
        }

        if (p->prox == NULL && i != vet)
        {
            cout << "fora dos limites do indice\n\n";
            return '\n';
        }
        else
            return p->x;
    }

    int cont_vector(){

        deque<T> *p = inicio;

        int i = 1;
        while (p->prox != NULL)
        {
            i++;
            p = p->prox;
        }
        return i;
    }
};

void clear(){
    system("cls");
}

int main() {
    Lista<int> lista_back;
    Lista<int> lista_front;
    int i, limite;

    clear();

    cout << "inserir atras\n";
    lista_back.inserir_back(1);
    lista_back.inserir_back(2);
    lista_back.inserir_back(3);
    lista_back.inserir_back(4);
    limite = lista_back.cont_vector();
    cout << "Tamanho do vetor: " << limite << endl;

    i = 0;
    while (i < limite)
    {
        cout << "List[" << i << "] == " << lista_back[i] << endl;
        i++;
    }
    cout << endl;
    
    cout << "inserir frente\n";
    lista_front.inserir_front(1);
    lista_front.inserir_front(2);
    lista_front.inserir_front(3);
    lista_front.inserir_front(4);
    limite = lista_front.cont_vector();
    cout << "Tamanho do vetor: " << limite << endl;

    i = 0;
    while (i < limite)
    {
        cout << "List[" << i << "] == " << lista_front[i] << endl;
        i++;
    }
    cout << endl;

    cout << "removendo atras: ";
    lista_front.remove_back();
    lista_front.exibir();

    cout << "removendo frente: ";
    lista_front.remove_front();
    lista_front.exibir();
    // do {
    //     cout<< "   Menu\n"
    //         << "(0) sair\n"
    //         << "(1) inserir\n"
    //         << "(2) remover\n"
    //         << "(3) indice\n";
    //     cin >> metodo;
    //     clear();

    //     if (metodo != 0 && metodo != 3) {
    //         cout<< "(1) inicio\n"
    //             << "(2) fim\n";
    //         cin >> lado;

    //         if (metodo == 1)
    //         {
    //             if (lado == 1)
    //                 lista_back.inserir_ini();
                
    //         }
            
    //         clear();
    //         lista_back.exibir();
    //         system("pause");
    //     }
    //     if (metodo == 3)
    //     {
    //         cin >> lado;
    //         cout << "List[" << lado << "] == " << lista_back[lado] << endl;
    //     }
        
    // } while (metodo != 0);
    

    return 0;
}

// template <class T>
// struct deque {
//     T x;
//     deque *prox;
// };

// template <class T>
// class lista
// {
// private:
//     deque<T> *inicio;

// public:
//     lista(/* args */){
//         inicio = NULL;
//     }
//     ~lista();

//     void inserir_ini (T x) {
        
//     }
// };


// template <typename T>
// int main () {
//     int metodo, lado;
//     T valor;
//     lista<int> deque;

//     do {
//         cout<< "(0) sair\n"
//             << "(1) inserir\n"
//             << "(2) remover\n";
//         cin >> metodo;

//         cout<< "(1) inicio\n"
//             << "(2) fim\n";
//         cin >> lado;

//         if (metodo == 1)
//         {
//             cout << "insira o noh";
//             cin >> valor;
//             if (lado == 1)
//                 inserir_ini(valor);
            
            
            
//         }
        
//         clear();
//         if (deque.inicio != NULL)
//         {
//             while (deque.inicio->prox != NULL)
//             {
//                 cout << "[" << deque.inicio->x <<"] -> ";
//             }
            
//         }


//     } while (metodo != 0);
    


//     return 0;
// }