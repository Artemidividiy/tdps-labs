//
// Created on 03.05.2022.
//

#ifndef LABS_TABLE_H
#define LABS_TABLE_H

#include "TableElement.h"
#include <vector>

class Table {
public:
    Table();
    Table(TableElement& element, const int &length);
    Table(std::vector<TableElement>& list);
    ~Table();
    void change(int index, TableElement &element);
    void sort();
    int length() const;
    size_t find(const TableElement &target);
    void remove(int index);
    void remove(TableElement& element);
    std::string to_string();
private:
    int len;
    std::vector<TableElement> list;
    void quadratic_sample();
    void quick_sort(std::vector<TableElement> &arr, int left, int right);
    void swap(TableElement &left, TableElement &right);
    int distance(std::vector<TableElement> arr, TableElement el);
    static bool element_comparison(TableElement left, TableElement right);

    std::string set_max_name();
};


#endif //LABS_TABLE_H
