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
    deque.push_back('c');
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
}