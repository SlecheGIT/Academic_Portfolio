#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class U>
class OrderedIntVector: private vector<U>{
    static void swap(U &a, U &b){
        U aux = a;
        a = b;
        b = aux;
    }
public:
    void insert(const U &num){
        int i = size();
        vector<U>::push_back(num);
        while(i > 0) {
            if ( vector<U>::at(i) <  vector<U>::at(i - 1)) {//mesma coisa operador de indice
                swap( vector<U>::at(i),  vector<U>::at(i - 1));
            }
            else{
                i = 1;
            }
            --i;
        }
    }
    unsigned size() const{
        return vector<U>::size();
    }
    operator string(){
        string str = "";
        typename vector<U>::iterator it; /*typename demonstra que o tipo do vector depende de uma declaraco de tipo posterior*/
        for(it = vector<U>::begin(); it != vector<U>::end(); ++it){
            str+=to_string(*it) + ' ';
        }
        return str;
    }

};
int main() {
    OrderedIntVector<int> obj;
    obj.insert(3);
    obj.insert(1);
    obj.insert(0);

    cout<<(string)obj<<endl;
    return 0;
}
