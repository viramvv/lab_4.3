#include <gtest/gtest.h>
#include "Decimal.h"
#include "String.h"

// Тест для Decimal: додавання з переносом (47 + 15 = 62)
TEST(DecimalTest, AdditionWithCarry) {
    Decimal d1(2, 1);
    d1[0] = 7; d1[1] = 4; // 47

    Decimal d2(2, 1);
    d2[0] = 5; d2[1] = 1; // 15

    Array* result = d1.add(&d2);
    
    // Перевірка результату через toString
    EXPECT_EQ(result->toString(), "62");
    delete result;
}

// Тест для String: конкатенація Pascal-рядків
TEST(StringTest, Concatenation) {
    String s1("Hi ");
    String s2("AI");

    Array* result = s1.add(&s2);
    
    EXPECT_EQ(result->toString(), "\"Hi AI\"");
    delete result;
}

// Тест для Array: перевірка виходу за межі (rangeCheck)
TEST(ArrayTest, OutOfBoundsException) {
    Array arr(5, 1);
    // Очікуємо, що виклик з індексом 10 викине std::out_of_range
    EXPECT_THROW(arr[10], std::out_of_range);
}