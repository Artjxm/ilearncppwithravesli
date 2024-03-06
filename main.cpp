#include <iostream>

template<class T>
class Auto_ptr3 {
    T* m_ptr;

public:
    // конструктор по умолчанию
    Auto_ptr3(T* ptr = nullptr) : m_ptr(ptr) {}
    ~Auto_ptr3() { delete m_ptr; }

    // конструктор копирования
    Auto_ptr3(const Auto_ptr3& a) = delete;

    // конструктор перемещения
    Auto_ptr3(Auto_ptr3&& rRef)  noexcept : m_ptr(rRef.m_ptr) {
        rRef.m_ptr = nullptr;
    }

    // перегрузка оператора присвоения копированием, который выполняет глубокое копирование
    Auto_ptr3& operator=(const Auto_ptr3& a) = delete;

    // перегрузка оператора присвоения перемещением, который передает право собственности
    // на rRef.m_ptr в m_ptr
    Auto_ptr3& operator=(Auto_ptr3&& rRef) noexcept {
        if (&rRef == this)
            return *this;

        delete m_ptr;

        m_ptr = rRef.m_ptr;
        rRef.m_ptr = nullptr;

        return *this;
    }

    T& operator*() { return *m_ptr; }
    T* operator->() { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};

class Item {
public:
    Item() { std::cout << "Item acquired\n"; }
    ~Item() { std::cout << "Item destroyed\n"; }
};

Auto_ptr3<Item> generateItem() {
    Auto_ptr3<Item> item(new Item);
    return item;
}

int main() {
    Auto_ptr3<Item> mainItem;
    mainItem = generateItem();

    return 0;
}
