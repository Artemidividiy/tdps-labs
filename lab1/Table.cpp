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

Table::Table(std::vector<Element> &list) : len(list.size())
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

size_t Table::find(const Element& target) {
    for (size_t i = 0; i < len; ++i) {
        if(static_cast<Element>(target) == list[i]) return i;
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
//todo: finish explicit table destructor
Table::~Table() {
//    for (size_t i = 0; i < len; ++i) {
//        delete &list[i];
//    }
//    delete &len;
//    delete &list;
}


//TODO: debug and finish sort
void Table::quadratic_sample() {
    std::vector<Element> target;
    std::vector<std::vector<Element>> fractioned_list;
    size_t length = sqrt(len);
    if(length*length < len) length++;
    std::vector<Element> temp;
    for (size_t i = 0; i <= len;++i) {
//        std::cout << i % length + 1
        if(i % length == 0) {
            if(temp.size())
                fractioned_list.push_back(temp);
            temp.clear();
        }
        temp.push_back(list[i]);
    }

    fractioned_list.push_back(temp);
    fractioned_list[fractioned_list.size() - 1].pop_back(); // clear up empty element in the end
    std::vector<Element> mins;

    for (int i = 0; i < fractioned_list.size(); ++i) {
        Element min_element = *std::min_element(fractioned_list[i].begin(), fractioned_list[i].end(), element_comparison);
        mins.push_back(min_element);
//        fractioned_list[segment][distance(fractioned_list[segment], min_element)] = Element::MAX_SIZE();
        std::find(fractioned_list[i].begin(), fractioned_list[i].end(), min_element)->set_group_code(-1);
    }
    int segment = -1;
    while(target.size() != len) {
//        for (int i = 0; i < fractioned_list.size(); ++i) {
//            Element min_element = *std::min_element(fractioned_list[i].begin(), fractioned_list[i].end(), element_comparison);
//            if (segment == i || segment == -1) {
//                mins.push_back(min_element);
//                fractioned_list[i].erase(std::find(fractioned_list[i].begin(), fractioned_list[i].end(), min_element));
//            }
//        }
        if(segment != -1) {
            Element min_element = *std::min_element(fractioned_list[segment].begin(), fractioned_list[segment].end(), element_comparison);

            mins.push_back(min_element);
            std::find(fractioned_list[segment].begin(), fractioned_list[segment].end(), min_element)->set_group_code(-1);
        }
        Element min_element_from_mins = *std::min_element(mins.begin(), mins.end(), element_comparison);
        target.push_back(min_element_from_mins);
        segment = distance(mins, min_element_from_mins);
        std::erase(mins, min_element_from_mins);
    }
    list = target;
}

bool Table::element_comparison(Element left, Element right) {
    if (left.get_group_code() != -1 || right.get_group_code() != -1) return false;
    return left < right;
}

int Table::distance(std::vector<Element> arr, Element el){
    int target = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (el == arr[i]) {
            target = i;
            break;
        }
    }
    return target;
}

void Table::quick_sort(std::vector<Element> &arr, int left, int right) {
    int i = left, j = right;
    Element pivot = arr[(left + right) / 2];
    while(i <= j){
        while(arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    if (left < j) quick_sort(arr, left, j);
    if (i < right) quick_sort(arr, i, right);
}

void Table::swap(Element &left, Element &right) {
    Element tmp = left;
    left = right;
    right = tmp;
}

void Table::sort() {
    if(list.size() < 10000) {
        quadratic_sample();
        return;
    }
    if (list.size() >= 10000) {
        quick_sort(list, 0, list.size() - 1);
    }
}


