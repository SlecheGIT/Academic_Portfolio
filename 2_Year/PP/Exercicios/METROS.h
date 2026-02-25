#include <iostream>
using namespace std;

class METROS
{
private:
    float metros;

public:
    METROS(){ metros = 0;}
    METROS(float valor){
        metros=valor;
    }
    METROS& operator=(float x) {
        metros = x;
        return *this;
    }

    METROS operator+ (const METROS y){
        METROS soma;
        soma.metros = metros + y.metros;
        
        return soma;
    }
    METROS operator- (const METROS y) {
        METROS subtracao;
        subtracao.metros = metros - y.metros;

        if (subtracao.metros < 0)
            subtracao.metros = 0;
        
        return subtracao;
    }
    METROS operator* (const METROS y) {
        METROS multiplica;
        multiplica.metros = metros * y.metros;
        
        return multiplica;
    }
    METROS operator+= (const METROS y){
        metros+= y.metros;

        return *this;
    }
    METROS operator-= (const METROS y){
        metros-= y.metros;
        if (metros < 0)
            metros = 0;
        return *this;
    }
    METROS& operator++ (){
        metros++;
        return *this;

    }
    METROS operator++ (int){
        METROS copy = *this;
        ++(*this);
        return copy;
    }
    METROS& operator-- (){
        metros--;
        if (metros < 0)
            metros = 0;
        return *this;
    }
    METROS operator-- (int){
        METROS copy = *this;
        --(*this);
        if (metros < 0)
            metros = 0 ;
        return copy;
    }
    bool operator== (const METROS y) {
        if (metros == y.metros)
            return true;
        else
            return false;
    }
    bool operator!= (const METROS y) {
        if (metros != y.metros)
            return true;
        else
            return false;
    }
    bool operator< (const METROS y) {
        if (metros < y.metros)
            return true;
        else
            return false;
    }
    bool operator<= (const METROS y) {
        if (metros <= y.metros)
            return true;
        else
            return false;
    }
    bool operator> (const METROS y) {
        if (metros > y.metros)
            return true;
        else
            return false;
    }
    bool operator>= (const METROS y) {
        if (metros >= y.metros)
            return true;
        else
            return false;
    }
   

    void exibir(){
        cout << "metros = "<< metros << endl << endl;
    }

};
