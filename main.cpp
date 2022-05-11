#include <iostream>
#include "lab1/Element.h"
#include "lab1/Table.h"
#include "lab2/Drawer.h"
#include "lab3/Solution.h"

#include "time.h"

// main.cpp
// Created by Артемий Касьяник on 10.04.2022.
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
//    clock_t start = clock();
//    Drawer drawer1 = Drawer(10000, 10000);
//    drawer1.draw();
//    clock_t stop = clock();
//    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
//    printf("\n");
//    printf("Time elapsed: %f\n", elapsed);
//    Drawer drawer2 = Drawer(5, 6);
//    drawer2.draw();
//    printf("\n");
//    Drawer drawer3 = Drawer(1, 1);
//    drawer3.draw();
//    printf("\n");
//    Drawer drawer4 = Drawer(3, 12);
//    drawer4.draw();
//    printf("\n");
//    Drawer drawer5 = Drawer(8, 8);
//    drawer5.draw();
//    printf("\n");
//    lab3
    Solution solution = Solution();
    std::cout << (solution.obey() ? "True" : "False");
    return 0;
}
