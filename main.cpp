#include <iostream>
#include "lab1/TableElement.h"
#include "lab1/Table.h"
#include "lab2/Drawer.h"
#include "lab3/Solution.h"

#include "time.h"
#include "lab1/List.h"

// main.cpp
// Created by Артемий Касьяник on 10.04.2022.
int main() {
//    lab1 basic variant
//    auto* el1 = new TableElement("A.S.1", "25:02:2002", 1);
//    auto* el2 = new TableElement("A.S.2", "25:03:2002", 2);
//    auto* el3 = new TableElement("A.S.3", "25:04:2002", 3);
//    auto* el4 = new TableElement("A.S.4", "25:05:2002", 3);
//    auto* el5 = new TableElement("A.S.5", "25:01:2002", 2);
//    auto* el6 = new TableElement("A.S.6", "24:02:2002", 3);
//    auto* el7 = new TableElement("A.S.7", "23:02:2002", 2);
//    auto* el8 = new TableElement("A.S.8", "29:02:2001", 3);
//    auto* el9 = new TableElement("A.S.9", "26:12:2002", 2);
//    auto* el10 = new TableElement("A.S.10", "25:02:2002", 3);
//    std::vector<TableElement> els = {*el1, *el2, *el3, *el2, *el4, *el5, *el6, *el7, *el8, *el9, *el10};
//    auto* table = new Table(els);
//    table->sort();
//    std::cout << table->to_string();

//    lab1 alternative variant
    ListElement *el1 = new ListElement("asd", "12.12.2002", 3);
    ListElement *el2 = new ListElement("bsd", "12.12.2002", 2);
    ListElement *el3 = new ListElement("csd", "12.12.2002", 3);
    ListElement *el4 = new ListElement("dsd", "12.12.2002", 1);
    List *list = new List(el1);
    list->add(el3);
    list->add(el2);
    list->add(el4);
    printf("index of searched element: %i\n",list->find(*el2));
    printf("searched by index element: %s\n",list->find(2).to_string().c_str());
}
