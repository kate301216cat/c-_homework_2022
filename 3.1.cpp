#include <vector>
#include <iostream>

int main() {
    std::vector<int> v;

    // Обратите внимание на то, как изменяется емкость вектора при добавлении элементов
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
        std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << "\n";
    }

    // Теперь давайте резервируем определенное количество элементов
    v.reserve(200);
    std::cout << "\nAfter reserve:\n";
    std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << "\n";

    // И давайте снова добавим некоторые элементы
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
        std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << "\n";
    }

    return 0;
}
