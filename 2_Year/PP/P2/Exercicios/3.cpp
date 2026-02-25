#include <iostream>
#include <vector>
#include <math.h>

/*
Crie um aplicativo, em C++, para a representação de sólidos em R3 e calculo de área de
superfície e volume destes sólidos. Na hierarquia de classes, obrigatoriamente deverá existir uma classe
responsável pelo armazenamento do conjunto de objetos, que representam os sólidos, e calculo, de área
e volume, total desse conjunto de objetos.
Seu aplicativo deve admitir que o usuário realize a inserção de esferas e cilindros, requisitar o calculo
da área e volume total dos sólidos inseridos. Além disso deve prever a ampliação do conjunto de
sólidos, implementados inicialmente, sem a necessidade de alteração das classes criadas inicialmente.

Esfera:
    float raio;
    Area = PI * 4.0 * raio^2
    Volume = (PI * 4.0 * raio^3) / 3

Cilindro:
    float raio, altura;
    Area = (2 * PI * raio * altura) + (2 * PI * raio^2)
    Volume = PI * raio^2 * altura
*/

using namespace std;

class solidosR3
{
public:
    virtual ~solidosR3() = default;
    virtual float calculo_area() const = 0;
    virtual float calculo_volume() const = 0;
};

class Esfera : public solidosR3
{
private:
    float raio;
public:
    Esfera(const float r = 1.0) : raio(r) {}

    float calculo_area() const override { return (M_PI * 4.0 * pow(raio, 2)); }

    float calculo_volume() const override { return (M_PI * 4.0 * pow(raio, 3) / 3.0); }
};

class Cilindro : public solidosR3
{
private:
    float raio, altura;
public:
    Cilindro(const float raio, const float altura) : raio(raio), altura(altura) {}

    float calculo_area() const override { return ((2 * M_PI * raio * altura) + (2 * M_PI * pow(raio, 2))); }

    float calculo_volume() const override { return (M_PI * pow(raio, 2) * altura); }
};

class Conjuntos
{
private:
    vector<solidosR3*> vetor;
public:
    ~Conjuntos() { vetor.clear(); }

    void adicionar(solidosR3 *solido) {
        vetor.push_back(solido);
    }

    float area_total() {
        vector<solidosR3*> :: iterator end = vetor.end(); 
        vector<solidosR3*> :: iterator it;
        float total = 0;

        for ( it = vetor.begin(); it < end; it++)
            total += (*it)->calculo_area();
         
        return total;
    }

    float volume_total() {
        vector<solidosR3*> :: iterator end = vetor.end(); 
        vector<solidosR3*> :: iterator it;
        float total = 0;

        for ( it = vetor.begin(); it < end; it++)
            total += (*it)->calculo_volume();
            
        return total;
    }
};



int main () {

    Esfera esfera(2);
    Cilindro cilindro(2, 3);

    cout << cilindro.calculo_area() << " direto \n";
    cout << cilindro.calculo_volume() << " direto \n";
    
    Conjuntos conjunto;
    conjunto.adicionar(&esfera);
    conjunto.adicionar(&cilindro);

    cout << conjunto.area_total() << " conjunto  \n";
    cout << conjunto.volume_total() << " conjunto  \n";

    return 0;
}