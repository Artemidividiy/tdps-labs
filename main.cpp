#include <iostream>
#include "lab1/Element.h"
#include "lab1/Table.h"
#include "lab2/Drawer.h"

int main() {
    //lab1
    /*
    auto* el1 = new Table::Element(1,"xiv1","25:02:2002");
    auto* el2 = new Table::Element(1,"xiv2","25:02:2002");
    auto* table = new Table(*el1);
    table->add(el2);
    std::cout << table->length();
    std::cout << table->to_string();
    printf("find method with index provided: \n%s \n", table->find(1)->to_string().c_str());
    printf("find method with element provided: \n%i \n", table->find(el2));
    table->sort();
     */
//    auto* el1 = new Element("xiv1", "25:02:2002", 1);
//    auto* el2 = new Element("xiv2", "25:02:2002", 2);
//    auto* el3 = new Element("xiv3", "25:02:2002", 3);
//    auto* el4 = new Element("xiv4", "25:02:2002", 3);
//    auto* el5 = new Element("xiv5", "25:02:2002", 2);
//    auto* el6 = new Element("xiv6", "25:02:2002", 3);
//    auto* el7 = new Element("xiv7", "25:02:2002", 2);
//    auto* el8 = new Element("xiv8", "25:02:2002", 3);
//    auto* el9 = new Element("xiv9", "25:02:2002", 2);
//    auto* el10 = new Element("xiv10", "25:02:2002", 3);
//    std::vector<Element> els = {*el1, *el2, *el3, *el2, *el4, *el5, *el6, *el7, *el8, *el9, *el10};
//    auto* table = new Table(els);
//    table->sort();

//    lab2
    Drawer drawer = Drawer(5, 6);
    drawer.draw();
    return 0;
}
