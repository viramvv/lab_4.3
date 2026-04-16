#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <stdexcept>

class Array {
protected:
    static const int MAX_SIZE = 256;
    unsigned char data[MAX_SIZE];
    int count;

public:
    // Конструктор: ініціалізує кількість елементів та заповнює їх початковим значенням
    Array(int n = 0, unsigned char val = 0);

    // Віртуальний деструктор обов'язковий для коректного видалення нащадків через Array*
    virtual ~Array();

    // Метод перевірки індексу за умовою
    bool rangeCheck(int index) const;

    // Перевантаження оператора [] з перевіркою rangeCheck
    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    // Віртуальна функція додавання — буде перевизначена в Decimal та String
    virtual Array* add(const Array* other) const;

    // Метод toString для виводу
    virtual std::string toString() const;

    // Дружня функція виводу, що використовує toString
    friend std::ostream& operator<<(std::ostream& os, const Array& obj);

    // Гетер для кількості (використовується в логіці додавання)
    int getCount() const { return count; }
};

#endif