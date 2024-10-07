#include <gtest/gtest.h>
#include "../include/lab1_dialog.h"
#include "../include/lab1_conversion.h"
#include "../include/utils.h"

TEST(YamlConversionTests, ArrToYamlStringName) {
    int array[] = {1, 2, 3, 4};
    std::string name = "numbers";
    size_t arr_size = sizeof(array) / sizeof(array[0]);

    std::string expected_yaml = "numbers:\n\t-1\n\t-2\n\t-3\n\t-4\n";

    std::string yaml_result = YamlConverting::arr_to_yaml(name, array, arr_size);

    EXPECT_EQ(yaml_result, expected_yaml);
}

TEST(YamlConversionTests, ArrToYamlCStringName) {
    int array[] = {5, 6, 7};
    const char* name = "values";
    size_t arr_size = sizeof(array) / sizeof(array[0]);

    std::string expected_yaml = "values:\n\t-5\n\t-6\n\t-7\n";

    std::string yaml_result = YamlConverting::arr_to_yaml(name, array, arr_size);

    EXPECT_EQ(yaml_result, expected_yaml);
}

TEST(YamlConversionTests, ArrToYamlCStringWithSize) {
    int array[] = {8, 9};
    const char* name = "set";
    size_t name_size = 3;
    size_t arr_size = sizeof(array) / sizeof(array[0]);

    std::string expected_yaml = "set:\n\t-8\n\t-9\n";

    std::string yaml_result = YamlConverting::arr_to_yaml(name, name_size, array, arr_size);

    EXPECT_EQ(yaml_result, expected_yaml);
}

TEST(YamlConversionTests, YamlToArrConversion) {
    YamlConverting::DataFormat data;
    data.yaml_string = "numbers:\n\t-10\n\t-20\n\t-30\n";

    YamlConverting::yaml_to_arr(data);

    EXPECT_EQ(data.name, "numbers");
    ASSERT_EQ(data.size, 3);

    int expected_array[] = {10, 20, 30};
    for (size_t i = 0; i < data.size; i++) {
        EXPECT_EQ(data.array[i], expected_array[i]);
    }

    YamlConverting::clean_Yaml(data);
}

TEST(YamlConversionTests, YamlToArrEmptyArray) {
    YamlConverting::DataFormat data;
    data.yaml_string = "empty:\n";

    YamlConverting::yaml_to_arr(data);

    EXPECT_EQ(data.name, "empty");
    EXPECT_EQ(data.size, 0);
    EXPECT_EQ(data.array, nullptr);
}

// Тестирование правильности очистки памяти
TEST(YamlConversionTests, CleanYamlTest) {
    YamlConverting::DataFormat data;
    data.name = "test";
    data.size = 2;
    data.array = new int[2]{1, 2};

    YamlConverting::clean_Yaml(data);

    EXPECT_EQ(data.array, nullptr);
}