#include "lab1_dialog.h"

namespace YC = YamlConverting;

void menu(){
    YC::YamlFormat temp{};

    std::map<int, std::function<void(YC::YamlFormat&)>> menuChoice = {
            {1, input_data},
            {2, outputYAML},
            {3, outputArr},
            {4, deleteArr},
            {5, [](YC::YamlFormat&) {std::cout << "Exit" << std::endl; }}
    };

    try{
        int choice;
        do{
            std::cout << "Menu:" << std::endl;
            std::cout << "1. Input data" << std::endl;
            std::cout << "2. Output in YAML format" << std::endl;
            std::cout << "3. Output in Array format" << std::endl;
            std::cout << "4. Delete data" << std::endl;
            std::cout << "5. Exit" << std::endl;
            choice = input<int>();
            auto iterator = menuChoice.find(choice);
            if (iterator !=  menuChoice.end()){
                try{
                    iterator->second(temp);
                }
                catch (std::logic_error& e) { std::cerr << e.what() << std::endl; }

            }
            else std::cout << "Try again" << std::endl;
        } while (choice != 5);
    }
    catch (std::runtime_error& e){ std::cerr << e.what() << std::endl; }
    catch (std::bad_alloc& e) { std::cerr << e.what() << std::endl; }
    deleteArr(temp);
}

void input_data(YC::YamlFormat& temp){
    std::string name;
    std::cout << "Input the name: ";
    name = input<std::string>();
    std::cout << std::endl;
    std::cout << "What format will the name stored in?" << std::endl;
    std::cout << "1. std::string" << std::endl;
    std::cout << "2. null-terminated string" << std::endl;
    std::cout << "3. array of symbols" << std::endl;
    int choice = input<int>();
    while (choice < 1 || choice > 3) choice = input<int>();
    std::cout << "Input the quantity: ";
    int size = input<int>();
    std::cout << std::endl;
    int* array = input_array(size);
    if (choice == 1){
        temp = YC::arr_to_yaml(name, array, size);
    }
    if (choice == 2){
        temp = YC::arr_to_yaml(name.c_str(), array, size);
    }
    if (choice == 3){
        temp = YC::arr_to_yaml(name.c_str(), name.length(), array, size);
    }
    delete array;
}

void outputYAML(YC::YamlFormat& temp){
    YC::output_yaml(temp);
}

void outputArr(YC::YamlFormat& temp){
    output_array(temp.array, temp.name, temp.size);
}

void deleteArr(YC::YamlFormat& temp){
    YC::clean_Yaml(temp);
}