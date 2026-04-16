#include "String.h"

String::String(const std::string& s) : Array((int)s.length() + 1) {
    // data[0] — це довжина рядка за умовою Pascal Strings
    this->data[0] = (unsigned char)s.length();
    for (int i = 0; i < s.length(); ++i) {
        this->data[i + 1] = s[i];
    }
}

Array* String::add(const Array* other) const {
    const String* s_other = dynamic_cast<const String*>(other);
    if (!s_other) return nullptr;

    // Створюємо новий рядок, об'єднуючи два існуючі
    std::string combined = "";
    // Зчитуємо символи першого рядка (з 1-го байта)
    for (int i = 1; i <= (int)this->data[0]; ++i) combined += (char)this->data[i];
    // Зчитуємо символи другого рядка
    for (int i = 1; i <= (int)s_other->data[0]; ++i) combined += (char)s_other->data[i];

    return new String(combined);
}

std::string String::toString() const {
    std::string res = "";
    int len = (int)data[0];
    for (int i = 1; i <= len; ++i) res += (char)data[i];
    return "\"" + res + "\"";
}