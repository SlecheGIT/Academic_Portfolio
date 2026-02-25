#include <iostream>
#include "METROS.h"
using namespace std;

int main() {
    float one, two;
    cout << "entre com o primeiro valor de metros: ";
    cin >> one;
    cout << endl;
    cout << "entre com o segundo valor de metros: ";
    cin >> two;
    cout << "\n\n\n";

    METROS carro1(one);
    METROS carro2(two);
    METROS x;

    x = carro1 + carro2;
    cout << "x = " << one << "+" << two << ": ";
    x.exibir();

    x = carro1 - carro2;
    cout << "x = " << one << "-" << two << ": ";
    x.exibir();

    x = carro1 * carro2;
    cout << "x = " << one << "*" << two << ": ";
    x.exibir();

    x = carro1;
    x += carro2;
    cout << one << " += " << two << ": " ;
    x.exibir();

    x = carro1;
    x -= carro2;
    cout << one << " -= " << two << ": " ;
    x.exibir();

    x = carro1;
    cout << " ++"<< one << ": " ;
    ++x;
    x.exibir();

    x = carro1;
    cout << "(primeira operacao) " << one << "++ : " ;
    x++.exibir();
    cout <<"(segunda operacao) " << one << "++ : " ;
    x.exibir();

    x = carro1;
    cout << " --"<< one << ": " ;
    --x;
    x.exibir();

    x = carro1;
    cout << "(primeira operacao) " << one << "-- : " ;
    x--.exibir();
    cout <<"(segunda operacao) " << one << "-- : " ;
    x.exibir();

    cout << one << " == " << two << ": ";
    if (carro1 == carro2)
        cout << "true\n\n";
    else
        cout << "false\n\n";

    cout << one << " != " << two << ": ";
    if (carro1 != carro2)
        cout << "true\n\n";
    else
        cout << "false\n\n";

    cout << one << " < " << two << ": ";
    if (carro1 < carro2)
        cout << "true\n\n";
    else
        cout << "false\n\n";

    cout << one << " <= " << two << ": ";
    if (carro1 <= carro2)
        cout << "true\n\n";
    else
        cout << "false\n\n";

    cout << one << " > " << two << ": ";
    if (carro1 > carro2)
        cout << "true\n\n";
    else
        cout << "false\n\n";

    cout << one << " >= " << two << ": ";
    if (carro1 >= carro2)
        cout << "true\n\n";
    else
        cout << "false\n\n";

    return 0;
}