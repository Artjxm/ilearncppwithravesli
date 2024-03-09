#include <iostream>
#include <memory> // для std::shared_ptr

class Something; // предположим, что Something - это класс, который может выбросить исключение

int main() {
    doSomething(std::make_shared<Something>(),
                std::make_shared<Something>());

    return 0;
}
