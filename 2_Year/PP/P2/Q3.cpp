#include <iostream>
#include <vector>
#include <math.h>

#define PI 3.14

using namespace std;

class SolidosR3
{
public:
    virtual ~SolidosR3() {}
    virtual float calcular_area() const = 0;
    virtual float calcular_volume() const = 0;
};

class Esferas : public SolidosR3
{
private:
    float raio;
public:
    Esferas(float X = 1) : raio(X) {}

    float calcular_area() const {
        return PI * 4.0 * (raio * raio);
    }

    float calcular_volume() const {
        return PI * 4.0 * (raio * raio * raio) / 3.0;
    }
};

class Cilindros : public SolidosR3
{
private:
    float raio;
    float altura;
public:
    Cilindros(float R = 1, float A = 1) : raio(R), altura(A) {}

    float calcular_area() const {
        return PI * 2.0 * (raio * altura) + PI * 2.0 * (raio * raio);
    }
    float calcular_volume() const {
        return PI * (raio * raio) * altura;
    }
};

class ConjuntosSolidosR3
{
private:
    vector<SolidosR3*> conjuntos;
public:
    ConjuntosSolidosR3() : conjuntos(NULL) {}
    ~ConjuntosSolidosR3() {
        conjuntos.clear();
    }
    void inserir_solido(SolidosR3 *solido)
    {
        conjuntos.push_back(solido);
    }
    float area_total(){
        vector<SolidosR3*>::iterator i;
        float total = 0;

        for (i = conjuntos.begin(); i != conjuntos.end(); i++)
            total+= (*i)->calcular_area();
        
        return total;
    }
    float volume_total() {
        vector<SolidosR3*>::iterator it;
        float total = 0;
        for ( it = conjuntos.begin(); it < conjuntos.end(); it++)
        {
            total +=  (*it)->calcular_volume();
        }
        return total;
    }
};




int main() 
{
    Cilindros cili(4, 4);
    Esferas esfera(2);

    ConjuntosSolidosR3 lista;
    lista.inserir_solido(&cili);
    lista.inserir_solido(&esfera);

    cout << " volume: " << cili.calcular_area() << endl;
    cout << "volume : " << esfera.calcular_volume() << endl;
    cout << "total area: " << lista.area_total() << endl;
    cout << "total volume: " << lista.volume_total() << endl;
    return 0;
}
