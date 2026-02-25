#include <iostream>
#include <vector>

using namespace std;

class Array : private vector<int>{
    void swap(int &num1, int &num2){
        int aux = num1;
        num1 = num2;
        num2 = aux;
    }
public:
    void insert_in_middle(int num){
        int i = 0;
        if(size() % 2 == 0){
            i = size() / 2;
        }
        else{
            i = ( (size() - 1) / 2) ;
        }
        int j = size();
        push_back(num);
        while( j > i){
            swap(at(j), at(j-1));
            j--;
        }

    }
    int &operator[] (int posicao){
        return at(posicao);
    }
};

int main(){
    Array obj;
    obj.insert_in_middle(5);
    obj.insert_in_middle(2);
    obj.insert_in_middle(3);
    obj.insert_in_middle(1);
    obj.insert_in_middle(6);
    obj[2] = 10;
    for(int i = 0; i < 5; i++){
        cout << obj[i] << endl;
    }
}