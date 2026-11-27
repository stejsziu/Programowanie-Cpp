#include <iostream>
#include <vector>
#include <print>
#include "Human.hpp"

/*
g++ -std=c++23 -Wall -Wextra lab5.cpp -o lab5 && ./lab5
*/

std::vector<int> wektorek;
std::vector<int> wektorek10042{100, 42};

int main() {

    std::println("dlugosc: {}, pojemnosc: {}", wektorek.size(), wektorek.capacity());

    for(int i = 0; i < 100; i++)
    {
        wektorek.emplace_back(3);
        std::println("dlugosc: {}, pojemnosc: {}, adres pierwszego elementu: {}",
        wektorek.size(), wektorek.capacity(), static_cast<void*>(&wektorek[0]));
    }

    std::println("dlugosc: {}, pojemnosc: {}", wektorek10042.size(), wektorek10042.capacity());


    return 0;
}
