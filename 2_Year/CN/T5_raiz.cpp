#include <iostream>
#include <chrono>
#include <math.h>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void calcula (float p, float m) {
    float xn = 1, ant = 0;
    unsigned cont = 0;

    while (xn != ant)
    {
        if (xn != ant)
            cout << "\nX" << cont++ << " = " << xn << endl;
        ant = xn;
        xn = (1/m)*((m-1) * xn + (p / pow(xn, m-1)));
    }
    
}

int main ()
{
    float p, m;

    cout << "\ninsira o radicando p (exemplo: p^(1/m)) : ";
    cin >> p;
    cout << "\ninsira o radical m (exemplo: p^(1/m)) : ";
    cin >> m;

    cout << setprecision(8) << endl;
    cout << "-------------------------------------\n";

    auto start = steady_clock::now();
    calcula(p, m);
    auto time_exe = steady_clock::now() - start;

    cout << "\nTempo de execucao: " << time_exe.count() << "/ns\n";
    cout << "-------------------------------------\n\n";


    return 0;
}