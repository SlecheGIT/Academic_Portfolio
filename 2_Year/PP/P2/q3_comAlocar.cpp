/*
Esfera:
    Area = PI * 4.0 * raio^2
    Volume = (PI * 4.0 * raio^3) / 3

Cilindro:
    Area = (2 * PI * raio * altura) + (2 * PI * raio^2)
    Volume = PI * raio^2 * altura
*/

#include <iostream>
#include <vector>

using namespace std;

// Valor PI para auxiliar nos calculos
#define PI 3.14

class SolidosR3 {
public:
    virtual ~SolidosR3() = default;

    virtual SolidosR3 *alocar() = 0;
    virtual double calculoArea() const = 0;
    virtual double calculoVolume() const = 0;
};

class Esfera : public SolidosR3 {
    double raio;
public:
    explicit Esfera(const double raio = 1.0) : raio(raio) {}

    SolidosR3 *alocar() override {
        return new Esfera(this->raio);
    }

    double calculoArea() const override {
        return PI * 4.0 * (raio * raio);
    }

    double calculoVolume() const override {
        return PI * 4.0 * (raio * raio * raio) / 3.0;
    }
};

class Cilindro : public SolidosR3 {
    double raio;
    double altura;
public:
    explicit Cilindro(const double raio = 1.0, const double altura = 1.0) : raio(raio), altura(altura) {}

    SolidosR3 *alocar() override {
        return new Cilindro(this->raio, this->altura);
    }

    double calculoArea() const override {
        return PI * 2.0 * (raio * altura) + PI * 2.0 * (raio * raio);
    }

    double calculoVolume() const override {
        return PI * (raio * raio) * altura;
    }
};

class ConjuntoSolidosR3 {
    vector<SolidosR3 *> solidosVector;

public:
    ~ConjuntoSolidosR3() {
        vector<SolidosR3 *>::iterator i; // Consegue iterar sobre o tipo do vector
        for (i = solidosVector.begin(); i != solidosVector.end(); ++i) {
            delete *i;
        }

        // for each: excelente para iterar, mas não sei se será aceito na prova =)
        // for (SolidosR3 *solido : solidosVector) {
        //     delete solido;
        // }
    }

    void adicionarSolido(SolidosR3 *solido) {
        solidosVector.push_back(solido->alocar());
    }

    double calcularAreaTotal() {
        double areaTotal = 0;

        vector<SolidosR3 *>::iterator i; // Consegue iterar sobre o tipo do vector
        for (i = solidosVector.begin(); i != solidosVector.end(); ++i) {
            areaTotal += (*i)->calculoArea();
        }

        // for each: excelente para iterar, mas não sei se será aceito na prova =)
        // for (const SolidosR3 *solido : solidosVector) {
        //     areaTotal += solido->calculoArea();
        // }

        return areaTotal;
    }

    double calcularVolumeTotal() {
        double volumeTotal = 0;

        vector<SolidosR3 *>::iterator i; // Consegue iterar sobre o tipo do vector
        for (i = solidosVector.begin(); i != solidosVector.end(); ++i) {
            volumeTotal += (*i)->calculoArea();
        }

        // for each: excelente para iterar, mas não sei se será aceito na prova =)
        // for (const SolidosR3 *solido : solidosVector) {
        //     volumeTotal += solido->calculoVolume();
        // }

        return volumeTotal;
    }
};

int main() {
    ConjuntoSolidosR3 conjunto;

    Esfera esfera(2);
    Cilindro cilindro(2, 3);

    conjunto.adicionarSolido(&esfera);
    conjunto.adicionarSolido(&cilindro);

    cout << "Area Total (conjunto): " << conjunto.calcularAreaTotal() << endl;
    cout << "Volume Total (conjunto): " << conjunto.calcularVolumeTotal() << endl;
    cout << endl;

    // Apenas para visualização individual dos Sólidos
    SolidosR3 *pontR3; // Ponteiro capaz de apontar para objetos de SolidosR3

    pontR3 = &esfera;
    cout << "Area Esfera: " << pontR3->calculoArea() << endl;
    cout << "Volume Esfera: " << pontR3->calculoVolume() << endl;
    cout << endl;

    pontR3 = &cilindro;
    cout << "Area Cilindro: " << pontR3->calculoArea() << endl;
    cout << "Volume Cilindro: " << pontR3->calculoVolume() << endl;

    return 0;
}
