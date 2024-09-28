#ifndef LAB1_LAB1_DIALOG_H
#define LAB1_LAB1_DIALOG_H
#include <iostream>
#include <map>
#include <functional>
#include <variant>
#include "lab1_conversion.h"
#include "utils.h"
#include <string>

void menu();
void input_data_to_arr(YamlConverting::DataFormat& temp);
void input_data_to_yaml(YamlConverting::DataFormat& temp);
void convert_arr_to_yaml(YamlConverting::DataFormat& temp);
void convert_yaml_to_arr(YamlConverting::DataFormat& temp);
void outputYAML(YamlConverting::DataFormat& temp);
void outputArr(YamlConverting::DataFormat& temp);
void deleteArr(YamlConverting::DataFormat& temp);
#endif //LAB1_LAB1_DIALOG_H
