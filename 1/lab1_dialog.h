#ifndef LAB1_LAB1_DIALOG_H
#define LAB1_LAB1_DIALOG_H
#include <iostream>
#include <map>
#include <functional>
#include <variant>
#include "lab1_conversion.h"
#include "utils.h"

void menu();
void input_data(YamlConverting::YamlFormat& temp);
void outputYAML(YamlConverting::YamlFormat& temp);
void outputArr(YamlConverting::YamlFormat& temp);
void deleteArr(YamlConverting::YamlFormat& temp);
#endif //LAB1_LAB1_DIALOG_H
