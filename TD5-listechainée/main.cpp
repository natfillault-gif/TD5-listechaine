#include "Link.h"
#include "LinkedList.h"
#include <iostream>

int main() {
    LinkedList list;

    try {

        list.add(18);
        list.add(32);
        list.add(27);

        std::cout << "Taille : " << list.size() << std::endl;  // 3
        std::cout << "Index 1 : " << list[1] << std::endl;     // 32

        list.insert(99, 1);
        std::cout << "Apres insert(99, 1) : " << list[1] << std::endl;  // 99

        list.remove(0);
        std::cout << "Apres remove(0) : " << list[0] << std::endl;  // 99

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }
}