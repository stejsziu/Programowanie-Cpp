#include <iostream>
#include <cmath>
#include <string>

// g++ -Wall -Wextra lab4.cpp -o lab4 && ./lab4

template<typename T>
class Para
{
    public:
        Para() : liczba1{0}, liczba2{0} {}
        Para(T l1, T l2) : liczba1{l1}, liczba2{l2} {}

        T suma() {
            return liczba1 + liczba2;
        }

    private:
        T liczba1, liczba2;
};

template<typename T, unsigned int N>
class TablicaPar
{
    public:
        Para<T>& operator[](unsigned int idx) {
            return tablica[idx];
        }

    private:
        Para<T> tablica[N];
};

template<typename T>
class TablicaPar<T, 0>;


template <typename T>
struct S {
    void print() { puts("Szablon ogólny"); }
};

template <>
struct S<double> {
    void print() { puts("Specjalizacja dla double"); }
};

template<typename T>
T iloczyn(const T& a, const T& b)
{ return a * b; }


int main() {
    Para<double> sumeczka{1,3};
    std::cout << sumeczka.suma() << std::endl;
    Para<double> sumeczka2{3,5};
    std::cout << sumeczka2.suma() << std::endl;

    TablicaPar<double, 3> tabliczka;
    tabliczka[0] = sumeczka;
    tabliczka[1] = sumeczka2;
    std::cout << tabliczka[0].suma() << std::endl;
    std::cout << tabliczka[1].suma() << std::endl;

    S<int> s1;
    S<double> s2;
    s1.print();
    s2.print();

    iloczyn(double, 1, 3);

    // TablicaPar<double, 0> tabliczka_ale_zla; // zle
    return 0;
}
