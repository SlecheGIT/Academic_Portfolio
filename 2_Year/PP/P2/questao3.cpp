#include <iostream>
#include <vector>

using namespace std;

class SolidoR3{
public:
    virtual float calcArea() = 0;
    virtual float calcVolume() = 0;
    virtual ~SolidoR3() {}
};

class Container{
    vector<SolidoR3*> fig;

public:
    void insere(SolidoR3 *ptr){
        fig.push_back(ptr);
    }
    float CalcVolumetotal(){
        float volume = 0;
        vector<SolidoR3 *>::iterator it;
        for(it = fig.begin(); it != fig.end(); ++it){
            volume += (*it)->calcVolume(); 
        }
        return volume;
    }
    float CalcAreatotal(){
        float area = 0;
        vector<SolidoR3 *>::iterator it;
        for(it = fig.begin(); it != fig.end(); ++it){
            area += (*it)->calcArea(); 
        }
        return area;
    }
    ~Container(){
        vector<SolidoR3 *>::iterator it;
        for(it = fig.begin(); it != fig.end(); ++it){
            if(*it != NULL){
                delete (*it);
            }
        }
    }
};

class Esfera : public SolidoR3{
    float Raio;
public:
    Esfera(float raio) : Raio(raio){}

    float calcArea() /*override*/{
        return 4 * 3.1415 * (Raio * Raio);
    }
    float calcVolume() /*override*/{
        return (4 / 3) * 3.1415 * (Raio * Raio * Raio);
    }
};

class Cilindro : public SolidoR3{
    float Raio, Altura;
public:
    Cilindro(float raio, float altura): Raio(raio), Altura(altura){}

    float calcArea() /*override*/{
        return 2 * 3.1415 * Raio * (Raio + Altura);
    }
    float calcVolume() /*override*/{
        return 3.1415 * (Raio * Raio) * Altura;
    }
};


int main(){
    Container obj;
    obj.insere(new Esfera(5));
    obj.insere(new Cilindro(3,2));
    cout << "area total: " << obj.CalcAreatotal() << " volume total: " << obj.CalcVolumetotal() << endl;
}