#ifndef LAB1_LAB1_CONVERSION_H
#define LAB1_LAB1_CONVERSION_H
#include <iostream>
#include <string>
#include <algorithm>
#include "utils.h"
namespace YamlConverting{
    struct YamlFormat{
        std::string name;
        size_t size{};
        int* array{};
    };

    YamlFormat arr_to_yaml(const char* name, size_t name_size, int* array, size_t arr_size);
    YamlFormat arr_to_yaml(const char* name, int* array, size_t arr_size);
    YamlFormat arr_to_yaml(const std::string& name, int* array, size_t arr_size);
    int* yaml_to_arr(YamlConverting::YamlFormat* temp, std::string& name, size_t& size);
    void output_yaml(YamlConverting::YamlFormat& temp);
}
#endif //LAB1_LAB1_CONVERSION_H