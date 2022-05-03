//
// Created by Артемий Касьяник on 03.05.2022.
//

#include "Table.h"
#include <vector>
#include <iostream>
#include <cmath>

Table::Table() : len(0) {
    std::cout << "empty table with no elements created\n";
}

Table::Table(Element& element, const int &length) :
len(length)
{
    list.push_back(element);
    std::cout << "table with one element provided created\n";
}

Table::Table(std::vector<Element> &list, int length) : len(length)
{
    this->list = list;
    std::cout << "full table created\n";
}

void Table::change(int index, Element &element) {
    list[index] = element;
}

int Table::length() const {
    return len;
}

size_t Table::find(Element& target) {
    for (size_t i = 0; i < len; ++i) {
        if(target == list[i]) return i;
    }
    return -1;
}

void Table::remove(int index) {
    if(index != 0) {
        for (int i = index + 1; i < len; ++i) {
            list[i - 1] = list[i];
        }
    }
    if(index == 0) {
        for (int i = 0; i < len - 1; ++i) {
            list[i] = list[i + 1];
        }
    }
    len--;
}

void Table::remove(Element &element) {
    int index = find(element);
    remove(index);
}

Table::~Table() {
//    for (size_t i = 0; i < len; ++i) {
//        delete &list[i];
//    }
//    delete &len;
//    delete &list;
}

void Table::sort() {
    std::vector<std::vector<Element>> fractioned_list;
    size_t length = sqrt(len);
    if(length*length < len) length++;
    for (size_t i = 0; i <= len;i += length) {
        size_t j = 0;
        std::vector<Element> temp;
        while(j <= length) {
            temp.push_back(list[j + i]);
            ++j;
        }
        fractioned_list.push_back(temp);
    }
    for (int i = 0; i < fractioned_list.size(); ++i){
        for (int j = 0; j < fractioned_list[i].size(); ++j) {
            printf("i: %i, j: %i :: %s\n", i,j,fractioned_list[i][j].to_string().c_str());
        }
        std::cout<< std::endl;
    }
}





