#include "lab1_conversion.h"
namespace YamlConverting{
    YamlFormat arr_to_yaml(const std::string& name, int* array, size_t arr_size){
        return arr_to_yaml(name.c_str(), array, arr_size);
    }

    YamlFormat arr_to_yaml(const char* name, size_t name_size, int* array, size_t arr_size){ //array of symbols
        return arr_to_yaml(std::string(name, name_size), array, arr_size);
    }

    YamlFormat arr_to_yaml(const char* name, int* array, size_t arr_size){ //null-terminates string
        YamlFormat temp;
        temp.name = name;
        temp.size = arr_size;
        temp.array = new int[arr_size];
        std::copy(array, array + arr_size, temp.array); //todo delete array
        return temp;
    }

    void output_yaml(const YamlFormat& temp){
        std::cout << temp.name << ":" << std::endl;
        for (size_t i{}; i < temp.size; i++){
            std::cout << "   -" << temp.array[i] << std::endl;
        }
        std::cout << std::endl;
    }

    void clean_Yaml(const YamlFormat& temp){
        delete[] temp.array;
    }
}