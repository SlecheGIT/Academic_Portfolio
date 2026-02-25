#include <iostream>

using namespace std;

class PontosR2
{
private:
    float x,y;
public:
    PontosR2(float X=0, float Y=0) : x(X), y(Y) {}
    
    bool operator== (PontosR2 other) const {
        return ((x == other.x) && (y == other.y));
    }
    bool operator!= (PontosR2 other) const {
        return ((x != other.x) && (y != other.y));
    }

    void operator= (PontosR2 other) {
        x = other.x;
        y = other.y;
    }

    PontosR2 operator+ (PontosR2 other) const
    {
        PontosR2 soma;
        soma.x = x + other.x;
        soma.y = y + other.y;
        return soma;
    }


    void operator++ ()
    {
        x++, y++;
    }

    PontosR2 operator++ (int)
    {
        PontosR2 aux;
        aux.x = x, aux.y = y;
        ++x, ++y;
        return aux;
    }

    void exibir()
    {
        cout<< "x = " << x << ", y = " << y << " .\n\n";
    }
};

int main()
{
    PontosR2 cord(4, 5);
    
    (cord++).exibir();
    cord.exibir();
    return 0;
}
