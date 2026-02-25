#include <iostream>

using namespace std;

template<class T>
struct FIFO
{
    T key;
    FIFO *prox;
};
    

template<class T>
class Fila
{
private:
    FIFO<T> *ptr;
public:
    Fila(){
        ptr = NULL;
    }
    ~Fila(){
        FIFO<T> *remove;
        while (ptr!=NULL)
        {
            remove= ptr;
            ptr = ptr->prox;
            delete remove;
        }
    }

    void inserir(T valor) //começo
    {
        FIFO<T> *percursor = ptr;
        FIFO<T> *novo = new FIFO<T>();
        novo->key =valor;
        novo->prox = NULL;

        if (percursor)
        {
            while (percursor->prox)
                percursor = percursor->prox;
            
            percursor->prox = novo;
        }
        else
            ptr = novo;
        
    }

    T remover() //fim
    {
        if (ptr)
        {
            FIFO<T> *inicio = ptr->prox;

            T aux = ptr->key;
            delete ptr;

            ptr = inicio;

            return aux;
        }
        else
            printf("fila vazia");
        
        return EXIT_FAILURE;
    }

    size_t getsize() const 
    {
        FIFO<T> *percursor = ptr;
        size_t cont = 0;
        while (percursor)
        {
            cont++;
            percursor = percursor->prox;
        }
        return cont;
    }

    T &operator[](unsigned indice)
    {
        FIFO<T> *percursor = ptr;
        
        while (indice--)
            percursor = percursor->prox;
        
        return percursor->key;
    }

    void exibir(){
        FIFO<T> *percursor = ptr;
        while (percursor != NULL)
        {
            printf("%d ", percursor->key);
            percursor = percursor->prox;
        }
        cout << endl << endl;
    }
};

int main()
{
    Fila<int> fila;

    // Inserir valores na fila
    fila.inserir(10);
    fila.inserir(20);
    fila.inserir(30);

    cout << "Fila original: ";
    fila.exibir();

    // Acesso por índice (leitura)
    cout << "Elemento no indice 1: " << fila[1] << endl << endl;

    // Modificar elemento por índice
    fila[1] = 302;

    cout << "Fila apos modificacao: ";
    fila.exibir();

    // Testar índice inválido
    try {
        cout << fila[3] << endl; // Índice fora do intervalo
    } catch (const out_of_range& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}


