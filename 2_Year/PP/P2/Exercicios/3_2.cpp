#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
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
    Esfera(const float R = 1.0) : raio(R) {}

    float calculo_area() const override {
        return (M_PI * 4.0 * pow(raio, 2));
    }

    float calculo_volume() const override {
        return ( (4/3) * M_PI * pow(raio, 3) );
    }
};

class Cilindro : public solidosR3
{
private:
    float raio;
    float altura;
public:
    Cilindro(const float R = 1.0, const float A = 1.0) : raio(R), altura(A) {}

    float calculo_area() const override {
        return ((2 * M_PI * pow(raio, 2)) + ( altura * 2 * M_PI * raio ) ); 
    }

    float calculo_volume() const override {
        return ( altura * M_PI * pow(raio, 2) );
    }
};

class Conjuntos
{
private:
    vector<solidosR3*> vetor;

public:
    ~Conjuntos() {
        vetor.clear();
    }
    
    void inserir(solidosR3 *solido) {
        vetor.push_back(solido);
    }

    float total_area() {
        vector<solidosR3*> :: iterator end = vetor.end();
        vector<solidosR3*> :: iterator it;
        float total = 0;

        for ( it = vetor.begin() ; it < end; it++)
        {
            total += (*it)->calculo_area();
        }
        return total;

    }

    float total_volume () {
        vector<solidosR3*> :: iterator end = vetor.end();
        vector<solidosR3*> :: iterator it;
        float total = 0;

        for ( it = vetor.begin() ; it < end; it++)
        {
            total+= (*it)->calculo_volume();
        }
        return total;
    }
};

int main () {

    Conjuntos conjunto;
    Esfera esfera(2);
    Cilindro cilindro(2,3);

    
    cout << "area total: " << esfera.calculo_area() << endl;
    cout << "volume total: " << esfera.calculo_volume() << endl;

    conjunto.inserir(&esfera);
    conjunto.inserir(&cilindro);

    cout << "area total: " << conjunto.total_area() << endl;
    cout << "volume total: " << conjunto.total_volume() << endl;
    return 0;
}