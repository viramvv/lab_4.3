#include "Decimal.h"

Decimal::Decimal(int n, int s) : Array(n, 0), sign(s) {}

Array* Decimal::add(const Array* other) const {
    // RTTI: перевіряємо, чи ми додаємо Decimal до Decimal
    const Decimal* d_other = dynamic_cast<const Decimal*>(other);
    if (!d_other) return nullptr;

    // Створюємо результат. Максимальна довжина = макс(a, b) + 1 (для переносу)
    Decimal* res = new Decimal(std::max(this->count, d_other->count) + 1, this->sign);
    
    int carry = 0; // Перенос у наступний розряд
    int i = 0;
    while (i < this->count || i < d_other->count || carry) {
        int v1 = (i < this->count) ? this->data[i] : 0;
        int v2 = (i < d_other->count) ? d_other->data[i] : 0;
        
        int sum = v1 + v2 + carry;
        (*res)[i] = sum % 10; // Записуємо останню цифру
        carry = sum / 10;     // Десяток іде далі
        i++;
    }
    // Оновлюємо реальну кількість розрядів у результаті
    // (Ми не можемо звернутися до count напряму, якби він був private, але він protected)
    res->count = i; 
    return res;
}

std::string Decimal::toString() const {
    std::string s = (sign == -1) ? "-" : "";
    // Виводимо у зворотному порядку (від одиниць в кінці до старших розрядів на початку)
    for (int i = count - 1; i >= 0; --i) {
        s += std::to_string((int)data[i]);
    }
    return s;
}