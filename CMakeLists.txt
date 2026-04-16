cmake_minimum_required(VERSION 3.20)
project(Lab_VirtualFunctions CXX)

set(CMAKE_CXX_STANDARD 17)

# Знаходимо або завантажуємо GTest (зазвичай він є в системі або CLion його підтягне)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Створюємо бібліотеку з вашим кодом, щоб не дублювати компіляцію
add_library(LabLogic
        Array.cpp Array.h
        Decimal.cpp Decimal.h
        String.cpp String.h
)

# 1. Головна програма
add_executable(MainApp main.cpp)
target_link_libraries(MainApp LabLogic)

# 2. Юніт-тести
add_executable(UnitTests UnitTest.cpp)
# Лінкуємо логіку + GTest + gtest_main (щоб не писати main у тестах)
target_link_libraries(UnitTests LabLogic GTest::GTest GTest::Main)

# Дозволяємо запуск тестів через вкладку "Run"
enable_testing()
add_test(NAME AllTests COMMAND UnitTests)