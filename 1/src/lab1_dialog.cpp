#include "../include/lab1_dialog.h"

namespace YC = YamlConverting;

void menu(){
    YC::DataFormat temp{};

    std::map<int, std::function<void(YC::DataFormat&)>> menuChoice = {
            {1, input_data_to_arr},
            {2, input_data_to_yaml},
            {3, convert_arr_to_yaml},
            {4, convert_yaml_to_arr},
            {5, outputArr},
            {6, outputYAML},
            {7, [](YC::DataFormat&) {std::cout << "Exit" << std::endl; }}
    };

    try{
        int choice;
        do{
            std::cout << "Menu:" << std::endl;
            std::cout << "1. Input data to array" << std::endl;
            std::cout << "2. Input data to YAML" << std::endl;
            std::cout << "3. Convert data from array to YAML" << std::endl;
            std::cout << "4. Convert data from YAML ta array" << std::endl;
            std::cout << "5. Output in Array format" << std::endl;
            std::cout << "6. Output in YAML format" << std::endl;
            std::cout << "7. Exit" << std::endl;
            choice = input<int>();
            auto iterator = menuChoice.find(choice);
            if (iterator !=  menuChoice.end()){
                try{
                    iterator->second(temp);
                }
                catch (const std::logic_error& e) { std::cerr << e.what() << std::endl; }

            }
            else std::cout << "Try again" << std::endl;
        } while (choice != 7);
    }
    catch (std::runtime_error& e){ std::cerr << e.what() << std::endl; }
    catch (std::bad_alloc& e) { std::cerr << e.what() << std::endl; }
    deleteArr(temp);
}

void input_data_to_arr(YC::DataFormat& temp){
    if (!temp.yaml_string.empty()) {
        temp.yaml_string.clear();
    }
    std::cout << "Input the name: ";
    auto name = input<std::string>();
    std::cout << std::endl;
    std::cout << "Input the size: ";
    auto size = input<int>();
    std::cout << std::endl;
    int* array = input_array(size);
    temp = YC::init_data(name, array, size);
    delete array;
}

void input_data_to_yaml(YC::DataFormat& temp){
    std::cout << "Input the string in yaml format:" << std::endl;
    std::cout << "name: \\n \\t num1" << std::endl;
    if (*temp.array) {
        deleteArr(temp);
    }
    temp.yaml_string = input<std::string>();
}

void convert_arr_to_yaml(YC::DataFormat& temp){
    if (temp.array == nullptr){
        throw std::runtime_error("Don`t have Array format to convert");
    }
    temp.yaml_string = YC::arr_to_yaml(temp.name, temp.array, temp.size);
    deleteArr(temp);
    temp.size = 0;
    temp.name.clear();
}

void convert_yaml_to_arr(YC::DataFormat& temp){
    if (temp.yaml_string.empty()){
        throw std::runtime_error("Don`t have YAML format to convert");
    }
    YC::yaml_to_arr(temp);
}

void outputYAML(YC::DataFormat& temp){
    if (temp.array != nullptr) {
        throw std::runtime_error("Have only Array format");
    }
    YC::output_yaml(temp.yaml_string);
}

void outputArr(YC::DataFormat& temp){
    if (!temp.yaml_string.empty()) {
        throw std::runtime_error("Have only YAML format");
    }
    output_array(temp.array, temp.name, temp.size);
}

void deleteArr(YC::DataFormat& temp){
    YC::clean_Yaml(temp);
}