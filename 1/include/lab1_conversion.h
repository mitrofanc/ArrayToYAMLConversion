#ifndef LAB1_LAB1_CONVERSION_H
#define LAB1_LAB1_CONVERSION_H

#include <iostream>
#include <string>
#include <algorithm>
#include "utils.h"
#include <sstream>
#include <vector>

namespace YamlConverting{

    /**
     * @brief Структура для хранения данных.
     *
     * Структура, которая содержит имя массива, YAML-строку,
     * размер массива и указатель на массив целых чисел.
     */
    struct DataFormat{
        std::string name;       ///< Имя массива.
        std::string yaml_string; ///< Строка с данными в формате YAML.
        size_t size{};          ///< Размер массива.
        int* array{};           ///< Указатель на массив целых чисел.
    };

    /**
     * @brief Инициализация структуры DataFormat.
     *
     * Создает структуру `DataFormat`, копируя переданное имя и массив в структуру.
     *
     * @param name Имя массива.
     * @param array Указатель на массив целых чисел.
     * @param arr_size Размер массива.
     * @return Структура `DataFormat` с заполненными полями.
     */
    DataFormat init_data(std::string& name, int* array, size_t arr_size);

    /**
     * @brief Преобразование массива в YAML-строку с указанным именем.
     *
     * Эта функция принимает массив целых чисел и возвращает его представление в виде
     * строки в формате YAML. Каждый элемент массива записывается как элемент списка в YAML.
     *
     * @param name Имя массива.
     * @param array Указатель на массив целых чисел.
     * @param arr_size Размер массива.
     * @return YAML-строка, представляющая массив в формате YAML.
     */
    std::string arr_to_yaml(const std::string& name, int* array, size_t arr_size);

    /**
     * @brief Преобразование массива в YAML-строку с указанным именем.
     *
     * Аналогично функции с параметром `std::string`, но принимает C-строку
     * для имени и указатель на массив целых чисел.
     *
     * @param name C-строка, представляющая имя массива.
     * @param array Указатель на массив целых чисел.
     * @param arr_size Размер массива.
     * @return YAML-строка, представляющая массив в формате YAML.
     */
    std::string arr_to_yaml(const char* name, int* array, size_t arr_size);

    /**
     * @brief Преобразование массива в YAML-строку с указанным именем.
     *
     * Аналогично предыдущей функции, но принимает массив символов с указанием его длины
     * для имени массива и указатель на массив целых чисел.
     *
     * @param name C-строка (массив символов), представляющая имя массива.
     * @param name_size Размер имени в символах.
     * @param array Указатель на массив целых чисел.
     * @param arr_size Размер массива.
     * @return YAML-строка, представляющая массив в формате YAML.
     */
    std::string arr_to_yaml(const char* name, size_t name_size, int* array, size_t arr_size);

    /**
     * @brief Преобразование YAML-строки в массив целых чисел.
     *
     * Парсит YAML-строку и заполняет массив целых чисел и имя в структуре `DataFormat`.
     *
     * @param temp Структура `DataFormat`, в которую будут записаны имя и массив.
     */
    void yaml_to_arr(DataFormat& temp);

    /**
     * @brief Вывод YAML-строки на консоль.
     *
     * Печатает YAML-строку, которая передается в параметре.
     *
     * @param yaml_format YAML-строка для вывода.
     */
    void output_yaml(std::string& yaml_format);

    /**
     * @brief Освобождение памяти в структуре `DataFormat`.
     *
     * Удаляет массив, который был выделен динамически, и устанавливает указатель
     * на `nullptr`, чтобы предотвратить повторное использование освобожденной памяти.
     * Также очищает строку формата YAML.
     *
     * @param temp Структура `DataFormat`, содержащая указатель на массив.
     */
    void clean_Yaml(DataFormat& temp);

}

#endif //LAB1_LAB1_CONVERSION_H
