#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> v;
    std::string str("bye");

    std::cout << "Copying str\n";
    v.push_back(str);

    std::cout << "str: " << str << '\n';
    std::cout << "v: " << v.back() << '\n';

    std::cout << "Moving str\n";
    v.push_back(std::move(str));

    std::cout << "str: " << str << '\n';
    std::cout << "v: " << v.at(0) << ' ' << v.at(1) << '\n';

    return 0;
}
