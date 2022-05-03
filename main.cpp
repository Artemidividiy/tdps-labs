#include <iostream>

#include "lab1/lab1.h"
int main() {
    auto* el1 = new Table::Element(1,"xiv1","25:02:2002");
    auto* el2 = new Table::Element(1,"xiv2","25:02:2002");
    auto* table = new Table(*el1);
    table->add(el2);
    std::cout << table->length();
    std::cout << table->to_string();
    printf("find method with index provided: \n%s \n", table->find(1)->to_string().c_str());
    printf("find method with element provided: \n%i \n", table->find(el2));
    table->sort();
    return 0;
}
