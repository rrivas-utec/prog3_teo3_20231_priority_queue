#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// stack, queue son adaptadores de deque por default
// priority_queu es adaptador del vector por default

void ejemplo_pq1() {
    vector v = {1, 2, 3, 4};
//    priority_queue<int> q(std::move(v));
    priority_queue q(less<int>(), std::move(v)); // Copy constructor
    cout << size(v) << endl; // n
    vector v1 = {1, 2, 3, 4};
    priority_queue q2(begin(v1), end(v1)); // Copy constructor
    cout << size(v1) << endl;  // 2n

    priority_queue<int, vector<int>, less<>> q3(less<>(), std::move(v1));
    cout << size(v1) << endl;  // n
}

void ejemplo_pq2() {
    vector v = {4, 2, 1, 3};
    priority_queue q(less<int>(), std::move(v)); // Copy constructor

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;

    vector v2 = {4, 2, 1, 3};
    priority_queue q2(greater<int>(), std::move(v2)); // Copy constructor
    while (!q2.empty()) {
        cout << q2.top() << " ";
        q2.pop();
    }
}

struct Persona {
    string nombre;
    string apellido;
    bool operator>(const Persona& other) const {
        return nombre > other.nombre;
    }
    bool operator<(const Persona& other) const {
        return nombre < other.nombre;
    }
};
void ejemplo_pq3() {
    vector v = {Persona{"Ana", "Zapata"},
                Persona{"Victor", "Abarca"},
                Persona{"Mario", "Bravo"},
                Persona{"Luis", "Diaz"},};

    priority_queue q(greater<>(), move(v));
    while (!q.empty()) {
        cout << q.top().nombre << " " << q.top().apellido << endl;
        q.pop();
    }
}

void ejemplo_pq4() {
    vector v = {Persona{"Ana", "Zapata"},
                Persona{"Victor", "Abarca"},
                Persona{"Mario", "Bravo"},
                Persona{"Luis", "Diaz"},};

    auto compare_desc_apellido = [](auto a, auto b) { return a.apellido < b.apellido; };
    auto compare_asce_apellido = [](auto a, auto b) { return a.apellido > b.apellido; };

    priority_queue q(compare_desc_apellido, v);
    while (!q.empty()) {
        cout << q.top().nombre << " " << q.top().apellido << endl;
        q.pop();
    }
    cout << "-----\n";
    priority_queue q2(compare_asce_apellido, v);
    while (!q2.empty()) {
        cout << q2.top().nombre << " " << q2.top().apellido << endl;
        q2.pop();
    }
}


int main() {
//    ejemplo_pq1();
//    ejemplo_pq2();
    ejemplo_pq3();
    ejemplo_pq4();
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
