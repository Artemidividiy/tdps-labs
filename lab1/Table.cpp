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

Table::Table(TableElement& element, const int &length) :
len(length)
{
    list.push_back(element);
    std::cout << "table with one element provided created\n";
}

Table::Table(std::vector<TableElement> &list) : len(list.size())
{
    this->list = list;
    std::cout << "full table created\n";
}

void Table::change(int index, TableElement &element) {
    list[index] = element;
}

int Table::length() const {
    return len;
}

size_t Table::find(const TableElement& target) {
    for (size_t i = 0; i < len; ++i) {
        if(static_cast<TableElement>(target) == list[i]) return i;
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

void Table::remove(TableElement &element) {
    int index = find(element);
    remove(index);
}
//todo: finish explicit table destructor
Table::~Table() {
}


void Table::quadratic_sample() {
    //массив чисел, который мы будем передавать по итогу в Table::list
    std::vector<TableElement> target;
    //массив подмассивов Table::list
    std::vector<std::vector<TableElement>> fractioned_list;
    size_t length = sqrt(len);
    if(length*length < len) length++;
    //генерируем массив подмассивов
    std::vector<TableElement> temp;
    for (size_t i = 0; i <= len;++i) {
        if(i % length == 0) {
            if(temp.size())
                fractioned_list.push_back(temp);
            temp.clear();
        }
        temp.push_back(list[i]);
    }

    fractioned_list.push_back(temp);
    fractioned_list[fractioned_list.size() - 1].pop_back(); // clear up empty element in the end
    std::vector<TableElement> mins;
    //первичное заполнение массива минимальных элементов
    for (int i = 0; i < fractioned_list.size(); ++i) {
        TableElement min_element = *std::min_element(fractioned_list[i].begin(), fractioned_list[i].end(), element_comparison);
        mins.push_back(min_element);

    }
    while(target.size() != len) {
        //ищем наименьший элемент в mins
        TableElement min_element = mins[0];
        int min_element_index = 0;
        for (int i = 0; i < mins.size(); ++i) {
            if (mins[i] < min_element) {
                min_element = mins[i];
                min_element_index = i;
            }
        }
        //убрали из mins встраиваемый в target элемент
        mins.erase(mins.begin() + min_element_index);
        //делаем как можно большую длину имени, чтобы при сортировке уже вставленный в target элемент таблицы никогда
        //не проходил по условию
        target.push_back(min_element);
        for (int i = 0; i < fractioned_list[min_element_index].size(); ++i) {
            if(fractioned_list[min_element_index][i] == min_element) {
                fractioned_list[min_element_index][i].set_name(set_max_name());
                break;
            }
        }
        if(fractioned_list[min_element_index].size() != 0)
            mins.insert(mins.begin() + min_element_index,*std::min_element(fractioned_list[min_element_index].begin(), fractioned_list[min_element_index].end(), element_comparison));
    }
    list = target;
}

bool Table::element_comparison(TableElement left, TableElement right) {
    return left < right;
}

std::string Table::set_max_name() {
    std::string target = "";
    for (int i = 0; i < 10000; ++i) {
        target += 'z';
    }
    return target;
}

int Table::distance(std::vector<TableElement> arr, TableElement el){
    int target = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (el == arr[i]) {
            target = i;
            break;
        }
    }
    return target;
}

void Table::quick_sort(std::vector<TableElement> &arr, int left, int right) {
    int i = left, j = right;
    TableElement pivot = arr[(left + right) / 2];
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

void Table::swap(TableElement &left, TableElement &right) {
    TableElement tmp = left;
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

std::string Table::to_string() {
    std::string target = "";
    for (int i = 0; i < list.size(); ++i) {
        target += list[i].to_string() + "\n";
    }
    return target;
}


