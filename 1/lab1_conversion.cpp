#include "lab1_conversion.h"

namespace YamlConverting{
    DataFormat init_data(std::string& name, int* array, size_t arr_size){
        DataFormat temp;
        temp.name = name;
        temp.size = arr_size;
        temp.array = new int[arr_size];
        std::copy(array, array + arr_size, temp.array); //todo remote this delete
        return temp;
    }

    std::string arr_to_yaml(const std::string& name, int* array, size_t arr_size){
        std::string yaml_format = name + ":\n";
        for (size_t i = 0; i < arr_size; i++){
            yaml_format += "\t-" + std::to_string(array[i]) + "\n";
        }
        return yaml_format;
    }

    std::string arr_to_yaml(const char* name, size_t name_size, int* array, size_t arr_size){ //array of symbols
        return arr_to_yaml(std::string(name, name_size), array, arr_size);
    }

    std::string arr_to_yaml(const char* name, int* array, size_t arr_size){ //null-terminates string
        return arr_to_yaml(std::string (name), array, arr_size);
    }

    void yaml_to_arr(DataFormat& temp){
        std::istringstream stream(temp.yaml_string);
        std::string cur_line;
        std::getline(stream, cur_line);
        temp.name = cur_line.substr(0, cur_line.find(':'));
        std::vector<int> array;
        while (std::getline(stream, cur_line)){
            if (cur_line.find('-') != std::string::npos){
                int number = std::stoi(cur_line.substr(cur_line.find('-') + 1));
                array.push_back(number);
            }
        }
        temp.array = new int[array.size()];
        temp.size = array.size();
        std::copy(array.begin(), array.end(), temp.array);
        temp.yaml_string.clear();
    }

    void output_yaml(std::string& yaml_format){
        std::cout << yaml_format << std::endl;
    }

    void clean_Yaml(DataFormat& temp){
        delete[] temp.array;
        temp.array = nullptr;
    }
}