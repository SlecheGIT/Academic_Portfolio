#include <iostream>
#define MI_ME 1609.34 // Define a constante de conversão de milhas para metros
using namespace std;

class DMilhas; // Declaração antecipada para a conversão

class DMedidas {
    float metros;

public:
    DMedidas(const float metros = 0) : metros(metros) {}

    float getMetros() const {
        return metros;
    }

    void setMetros(const float metros) {
        this->metros = metros;
    }

    DMedidas operator +(const DMedidas &other) const {
        return DMedidas(metros + other.metros);
    }

    DMedidas operator -(const DMedidas &other) const {
        return DMedidas(metros - other.metros);
    }

    DMedidas& operator ++() {
        ++metros;
        return *this;
    }

    DMedidas operator ++(int) {
        DMedidas temp = *this;
        ++metros;
        return temp;
    }

    bool operator ==(const DMedidas &other) const {
        return metros == other.metros;
    }

    bool operator !=(const DMedidas &other) const {
        return metros != other.metros;
    }

    bool operator <(const DMedidas &other) const {
        return metros < other.metros;
    }

    bool operator <=(const DMedidas &other) const {
        return metros <= other.metros;
    }

    bool operator >(const DMedidas &other) const {
        return metros > other.metros;
    }

    bool operator >=(const DMedidas &other) const {
        return metros >= other.metros;
    }

    // Operador de conversão para DMilhas
    operator DMilhas() const;
};

class DMilhas {
    float medida;

public:
    DMilhas(float milhas = 0.0) : medida(milhas) {}

    // Construtor de cópia corrigido
    DMilhas(const DMilhas &other) {
        medida = DMilhas.medida;
    }

    float getMedida() const {
        return medida;
    }

    void setMedida(float milhas) { // Corrigido para retornar void
        medida = milhas;
    }

    // Operador de conversão para DMedidas
    operator DMedidas() const {
        return DMedidas(medida * MI_ME);
    }
};

// Definição do operador de conversão para DMilhas fora da classe DMedidas
DMedidas::operator DMilhas() const {
    return DMilhas(metros / MI_ME);
}

int main() {
    DMedidas m1(4), m2(2), m3;
    DMilhas milha1(2), milha2;

    m3 = milha1; // Converte DMilhas para DMedidas
    milha2 = m1; // Converte DMedidas para DMilhas

    cout << "Metros: " << m3.getMetros() << " Milhas: " << milha2.getMedida() << endl;

    return 0;
}
/*
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

using namespace std;
template <typename T>

class Deque {
private:
    vector<T> data;

public:
    Deque() = default;

    void push_front(const T& value) {
        data.insert(data.begin(), value);
    }

    void push_back(const T& value) {
        data.push_back(value);
    }

    void pop_front() {
        if (data.empty()) {
            throw out_of_range("Deque is empty");
        }
        data.erase(data.begin());
    }

    void pop_back() {
        if (data.empty()) {
            throw out_of_range("Deque is empty");
        }
        data.pop_back();
    }

    T& operator[](size_t index) {
        if (index >= data.size()) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= data.size()) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    operator std::string() const {
        std::ostringstream oss;
        for (const auto& elem : data) {
            oss << elem << " ";
        }
        std::string result = oss.str();
        if (!result.empty()) {
            result.pop_back(); // Remove the trailing space
        }
        return result;
    }

    size_t getSize() const {
        return data.size();
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    Deque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_front(0);
    deque.push_front(-1);

    cout << "Deque contents: " << string(deque) << endl;
    cout << "Deque size: " << deque.getSize() << endl;

    deque.pop_back();
    cout << "After pop_back: " << string(deque) << endl;

    deque.pop_front();
    cout << "After pop_front: " << string(deque) << endl;

    cout << "Element at index 1: " << deque[1] << endl;

    deque[1] = 42;
    cout << "After setting element at index 1 to 42: " << string(deque) << endl;

    return 0;
}*/

