#include <iostream>
#include <cmath>
#include "pontos.h"
using namespace std;
#define pi 3.14

//Erro: não definiu op de casting (no lugar escreveu uma função)
//Não marcou as funções constantes

class polares
{
private:
    float r;
    float angulo;
public:
    polares(float r0 = 0, float angulo0 = 0) { r = r0, angulo = angulo0; };
    polares(pontos cordenada)
    { //convertendo pontos para polares 
        r = sqrt((cordenada.getx() * cordenada.getx()) + (cordenada.gety() * cordenada.gety()));
        angulo = atan2(cordenada.gety() , cordenada.getx());
    }
    float getR () { return r; }
    float getAngulo () { return angulo; }

    pontos converter() { //ponto = cordenadapolar.converter()
        pontos novo;
        novo.setx( r * cos(angulo) );
        novo.sety( r * sin(angulo) );
        return novo; 
    }
};

int main () {
    pontos cordenada(2, 2);
    polares polar(cordenada);
    pontos cordenada2;

    cout << endl <<endl;

    cout << "converter ponto : (x = " << cordenada.getx() << " , y = " << cordenada.gety() << ")\n";

    cout << "\ncordenada polar : ";
    cout << "(r = " << polar.getR() << " , angulo = " << polar.getAngulo() << ")\n";
    
    cout << "\nretornando polar para ponto : ";
    cordenada2 = polar.converter(); 
    cout << "(x = " << cordenada2.getx() << " , y = " << cordenada2.gety() << ")";

    cout << endl <<endl;
    return 0;
}