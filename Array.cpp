#include "Array.h"

Array::Array(int n, unsigned char val) {
    // Перевірка, щоб не перевищити MAX_SIZE
    this->count = (n > MAX_SIZE) ? MAX_SIZE : n;
    for (int i = 0; i < MAX_SIZE; ++i) {
        data[i] = (i < this->count) ? val : 0;
    }
}

Array::~Array() {}

bool Array::rangeCheck(int index) const {
    return index >= 0 && index < count;
}

unsigned char& Array::operator[](int index) {
    if (!rangeCheck(index)) throw std::out_of_range("Index out of bounds");
    return data[index];
}

const unsigned char& Array::operator[](int index) const {
    if (!rangeCheck(index)) throw std::out_of_range("Index out of bounds");
    return data[index];
}

Array* Array::add(const Array* other) const {
    // Базова реалізація: просто поцифрове додавання значень байтів
    int res_size = std::max(this->count, other->count);
    Array* result = new Array(res_size);
    for (int i = 0; i < res_size; ++i) {
        unsigned char v1 = (i < this->count) ? this->data[i] : 0;
        unsigned char v2 = (i < other->count) ? other->data[i] : 0;
        (*result)[i] = v1 + v2;
    }
    return result;
}

std::string Array::toString() const {
    std::string s = "Array size " + std::to_string(count) + ": [ ";
    for (int i = 0; i < count; ++i) s += std::to_string((int)data[i]) + " ";
    return s + "]";
}

std::ostream& operator<<(std::ostream& os, const Array& obj) {
    os << obj.toString();
    return os;
}