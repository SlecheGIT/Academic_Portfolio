#include <iostream>

using namespace std;


class Jogo
{
private:
    string nome;      // nome do jogo
    float preco;     // preço do jogo
    int horas;       // quantidade de horas jogadas
    float custo;     // valor por hora jogada
    void atualizar()
    {
        if (horas > 0)
            custo = preco/horas;
    }

public :
    Jogo(const string &titulo = "vazio", float valor=0){

        horas=0;
        nome=titulo;
        preco=valor;
    }
   
    void jogar(int tempo){
        if (tempo>0)
        horas+=tempo;
        atualizar();
        
    }

    void exibir(){
        cout<<"nome:"<< nome << endl;
        cout<<"preco:"<< preco << endl;
        cout<<"horas:"<< horas << endl;
        cout<<"custo:"<< custo << endl;


    }


    
};
int main(){
    Jogo thesims = {"thesims", 500};
    thesims.jogar(50);
    thesims.exibir();

    





    return 0;
}