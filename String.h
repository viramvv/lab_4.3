#ifndef STRING_H
#define STRING_H

#include "Array.h"

class String : public Array {
public:
    // Конструктор приймає стандартний рядок для ініціалізації
    String(const std::string& s = "");

    // Конкатенація рядків через віртуальну функцію
    Array* add(const Array* other) const override;

    std::string toString() const override;
};

#endif