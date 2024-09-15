#include "utils.h"

bool tryInput (int& dst){
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

int input(){
    int res;
    while(!tryInput(res));
    return res;
}

int* input_array(size_t size){
    int* arr = new int[size] {};
    for (size_t i{}; i < size; i++) std::cin >> arr[i];
    return arr;
}

void output_array(int* array, std::string& name, size_t size){
    std::cout << name << ": ";
    for (size_t i{}; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}