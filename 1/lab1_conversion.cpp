#include "lab1_conversion.h"
namespace YamlConverting{
    YamlFormat arr_to_yaml(const std::string& name, int* array, size_t arr_size){
        YamlFormat temp;
        temp.name = name;
        temp.size = arr_size;
        temp.array = array;
        return temp;
    }

    YamlFormat arr_to_yaml(const char* name, size_t name_size, int* array, size_t arr_size){ //array of symbols
        return arr_to_yaml(std::string(name, name_size), array, arr_size);
    }

    YamlFormat arr_to_yaml(const char* name, int* array, size_t arr_size){ //null-terminates string
        return arr_to_yaml(std::string(name), array, arr_size);
    }

    void output_yaml(YamlFormat& temp){
        std::cout << temp.name << ":" << std::endl;
        for (size_t i{}; i < temp.size; i++){
            std::cout << "   -" << temp.array[i] << std::endl;
        }
        std::cout << std::endl;
    }
}