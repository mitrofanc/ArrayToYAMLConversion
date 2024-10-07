#ifndef LAB1_UTILS_H
#define LAB1_UTILS_H
#include <iostream>
#include <limits>
#include <stdexcept>

template <typename T>
bool tryInput (T& dst){
    std::cin >> dst;
    if (std::cin.eof())
        throw std::runtime_error("EOF");
    if (std::cin.bad())
        throw std::runtime_error("Broken input");
    if (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

template <typename T>
T input(){
    T res;
    while(!tryInput<T>(res));
    return res;
}

int* input_array(size_t size);
void output_array(int* array, std::string& name, size_t size);
#endif //LAB1_UTILS_H
