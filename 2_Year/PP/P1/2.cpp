#include <iostream>
using namespace std;
//ERRO:nenhuma função constante marcada como constante
class pontos
{
public:
    float x, y;

public:
    pontos(float x0 = 0, float y0 = 0){ x=x0, y=y0; }

    float getx(){ return x; }
    void setx(float x0){ x = x0; }

    float gety(){ return y; }
    void sety(float y0){ y = y0; }

    bool operator== (pontos cord) {
        return ((x == cord.x) && (y == cord.y));
    }
    bool operator!= (pontos cord) {
        return ((x != cord.x) && (y != cord.y));
    }

    pontos operator+ (pontos cord) {
        pontos soma;
        soma.x = x + cord.x;
        soma.y = y + cord.y;
        return soma;
    }
    pontos operator- (pontos cord) {
        pontos subtracao;
        subtracao.x = x - cord.x;
        subtracao.y = y - cord.y;
        return subtracao;
    }

    pontos &operator++ () {//erro: retorno por referencia
        ++x, ++y;
        return *this;
    }
    pontos operator++ (int) {
        pontos aux = *this;
        x++, y++;
        return aux;
    }
    
    pontos &operator-- () {//erro: retorno por referencia
        --x, --y;
        return *this;
    }
    pontos operator-- (int) {
        pontos aux = *this;
        x--, y--;
        return aux;
    }
    
};

int main () {

    pontos cordenada1(5.5, 10);
    pontos cordenada2(5, 5);
    pontos cordenada3;
    cout << endl << "A) " << endl;

    cout << "(" << cordenada1.getx() << " == " << cordenada2.getx();
    cout << " , " << cordenada1.gety() << " == " << cordenada2.gety() << ") : ";
    if (cordenada1 == cordenada2)
        cout << "true";
    else
        cout << "false";
    
    cout << endl << endl;

    cout << "(" << cordenada1.getx() << " != " << cordenada2.getx();
    cout << " , " << cordenada1.gety() << " != " << cordenada2.gety() << ") : ";
    if (cordenada1 != cordenada2)
        cout << "true";
    else
        cout << "false";

    cout << endl << endl << "B) " << endl;

    cout << "Funcao soma: " << endl;
    cout << "(" << cordenada1.getx() << " + " << cordenada2.getx();
    cout << " , " << cordenada1.gety() << " + " << cordenada2.gety();
    cordenada3 = cordenada1 + cordenada2;
    cout << ") == (" << cordenada3.x << " , " << cordenada3.y << ")";
    
    cout << endl << endl;

    cout << "Funcao subtracao: " << endl;
    cout << "(" << cordenada1.getx() << " - " << cordenada2.getx();
    cout << " , " << cordenada1.gety() << " - " << cordenada2.gety();
    cordenada3 = cordenada1 - cordenada2;
    cout << ") == (" << cordenada3.x << " , " << cordenada3.y << ")";

    cout << endl << endl;

    cout << "++Pre-fixado: " << endl;
    cout << "++(" << cordenada1.getx() << " , " << cordenada1.gety() << ")";
    ++cordenada1;
    cout << " == (" << cordenada1.getx() << " , " << cordenada1.gety() << ")";
    
    cout << endl << endl;

    cout << "--Pre-fixado: " << endl;
    cout << "--(" << cordenada1.getx() << " , " << cordenada1.gety() << ")";
    --cordenada1;
    cout << " == (" << cordenada1.getx() << " , " << cordenada1.gety() << ")";

    cout << endl << endl;

    cout << "Pos-fixado++: " << endl;
    cout << "(" << cordenada1.getx() << " , " << cordenada1.gety() << ")++";
    cout << " == (" << (cordenada1++).getx() << " , " << cordenada1.gety() << ")"; //antes do acrescimo
    cout << "\nsegunda chamada == ";
    cout << " == (" << cordenada1.getx() << " , " << cordenada1.gety() << ")"; // apos o acrescimo

    cout << endl << endl;

    cout << "Pos-fixado--: " << endl;
    cout << "(" << cordenada1.getx() << " , " << cordenada1.gety() << ")--";
    cout << " == (" << (cordenada1--).getx() << " , " << cordenada1.gety() << ")"; // antes da subtração
    cout << "\nsegunda chamada == ";
    cout << " == (" << cordenada1.getx() << " , " << cordenada1.gety() << ")"; // apos a subtracao

    cout << endl << endl;
    return 0;
}