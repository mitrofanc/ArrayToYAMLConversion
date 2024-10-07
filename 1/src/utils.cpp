#include "../include/utils.h"

int* input_array(size_t size){
    int* arr = new int[size] {};
    for (size_t i{}; i < size; i++) arr[i] = input<int>();
    return arr;
}

void output_array(int* array, std::string& name, size_t size){
    std::cout << name << ": ";
    for (size_t i{}; i < size; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}