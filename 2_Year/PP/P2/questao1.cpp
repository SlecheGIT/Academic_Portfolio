#include <iostream>
#include <vector>

using namespace std;

class Ordenado : private vector<int>{
public:

    void troca(int &num1, int &num2){
        int aux = num1;
        num1= num2;
        num2 = aux;
    }
    void insert (int num){
        int i = size();
        push_back(num);
        while(i > 0){
            if(at(i) < at(i-1)){
                troca(at(i), at(i-1));
            }
            --i;
        }
    }
    int operator[](int posicao){
        return at(posicao);
    }
    int tam(){
        return size();
    }
};


int main(){
    Ordenado obj;
    obj.insert(5);
    obj.insert(3);
    obj.insert(1);
    obj.insert(0);
    obj.insert(5);
    for(int i = 0; i < obj.tam(); i++)
        cout << obj[i] << endl;
}