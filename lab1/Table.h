//
// Created by Артемий Касьяник on 03.05.2022.
//

#ifndef LABS_TABLE_H
#define LABS_TABLE_H

#include "Element.h"
#include <vector>

class Table {
public:
    Table();
    Table(Element& element, const int &length);
    Table(std::vector<Element>& list, int length);
    ~Table();
    void change(int index, Element &element);
    void sort();
    int length() const;
    size_t find(Element &target);
    void remove(int index);
    void remove(Element& element);
private:
    int len;
    std::vector<Element> list;
};


#endif //LABS_TABLE_H
