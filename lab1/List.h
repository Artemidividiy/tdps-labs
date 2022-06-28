//
// Created by Артемий Касьяник on 28.06.2022.
//

#ifndef LABS_LIST_H
#define LABS_LIST_H
#include "TableElement.h"
#include "ListElement.h"

class List {
public:
    List();
    List(ListElement *first);
    void add(ListElement *element);
    void remove(const ListElement &element);
    int find(const ListElement &element);
    void remove(int index);
    ListElement find(int index);
    int length();
private:
    ListElement* first;
    int len;
};


#endif //LABS_LIST_H
