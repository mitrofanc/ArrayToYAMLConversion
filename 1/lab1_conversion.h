#ifndef LAB1_LAB1_CONVERSION_H
#define LAB1_LAB1_CONVERSION_H
#include <iostream>
#include <string>
#include <algorithm>
#include "utils.h"
#include <sstream>
#include <vector>
namespace YamlConverting{
    struct DataFormat{
        std::string name;
        std::string yaml_string;
        size_t size{};
        int* array{};
    };

    DataFormat init_data(std::string& name, int* array, size_t arr_size);
    std::string arr_to_yaml(const char* name, size_t name_size, int* array, size_t arr_size);
    std::string arr_to_yaml(const char* name, int* array, size_t arr_size);
    std::string arr_to_yaml(const std::string& name, int* array, size_t arr_size);
    void yaml_to_arr(DataFormat& temp);
    void output_yaml(std::string& yaml_format);
    void clean_Yaml(const DataFormat& temp);
}
#endif //LAB1_LAB1_CONVERSION_H
