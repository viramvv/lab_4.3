#include <iostream>
#include <vector>
#include <typeinfo> // Для роботи з RTTI (визначення типу)
#include "Decimal.h"
#include "String.h"

int main() {
    // 1. Створюємо поліморфні об'єкти
    // Використовуємо вказівник базового класу для об'єктів нащадків
    Array* p1 = new Decimal(2, 1);
    (*p1)[0] = 7; // Одиниці: 7
    (*p1)[1] = 4; // Десятки: 4 (число 47)

    Array* p2 = new Decimal(2, 1);
    (*p2)[0] = 5; // Одиниці: 5
    (*p2)[1] = 1; // Десятки: 1 (число 15)

    Array* p3 = new String("C++ ");
    Array* p4 = new String("Polymorphism");

    // Зберігаємо в вектор для масової перевірки
    std::vector<Array*> objects = { p1, p2, p3, p4 };

    std::cout << "--- Runtime Type Identification (RTTI) ---\n";
    for (Array* obj : objects) {
        // typeid дозволяє побачити справжній клас об'єкта під час виконання
        std::cout << "Pointer to Array* actually points to: "
                  << typeid(*obj).name() << " | Value: " << *obj << "\n";
    }

    std::cout << "\n--- Virtual Functions Execution ---\n";

    // Виклик віртуального додавання для Decimal
    Array* sumDec = p1->add(p2); // Викличе Decimal::add
    std::cout << "47 + 15 = " << *sumDec << "\n";

    // Виклик віртуального додавання для String
    Array* sumStr = p3->add(p4); // Викличе String::add
    std::cout << "String concatenation: " << *sumStr << "\n";

    // Очищення пам'яті
    for (auto obj : objects) delete obj;
    delete sumDec; delete sumStr;

    return 0;
}