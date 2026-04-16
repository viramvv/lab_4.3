#ifndef DECIMAL_H
#define DECIMAL_H

#include "Array.h"

class Decimal : public Array {
private:
    int sign;

public:
    // Конструктор: n — кількість цифр, s — знак
    Decimal(int n = 1, int s = 1);

    // Перевизначення додавання (Довга арифметика)
    Array* add(const Array* other) const override;

    // Перевантаження виводу для чисел
    std::string toString() const override;
};

#endif