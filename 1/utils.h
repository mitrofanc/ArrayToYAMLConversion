#ifndef LAB1_UTILS_H
#define LAB1_UTILS_H
#include <iostream>
//#include <limits>
//#include <stdexcept>
template <typename T> bool tryInput (T& dst);
template <typename T> T input();
int* input_array(size_t size);
void output_array(int* array, std::string& name, size_t size);
#endif //LAB1_UTILS_H
