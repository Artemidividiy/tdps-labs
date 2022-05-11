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
    Table(std::vector<Element>& list);
    ~Table();
    void change(int index, Element &element);
    void sort();
    int length() const;
    size_t find(const Element &target);
    void remove(int index);
    void remove(Element& element);
private:
    int len;
    std::vector<Element> list;
    void quadratic_sample();
    void insertion_sort();

    void quick_sort(std::vector<Element> &arr, int left, int right);
    void swap(Element &left, Element &right);
    int distance(std::vector<Element> arr, Element el);
    static bool element_comparison(Element left, Element right);
};


#endif //LABS_TABLE_H
