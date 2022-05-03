//
// Created by Артемий Касьяник on 03.05.2022.
//

#include "lab1.h"

#include <string>
#include <iostream>
#include <cmath>

Table::Table(): first(NULL), len(0){
    std::cout << "empty table created\n";
}

Table::Table(Element& element): first(&element), len(1){
    std::cout << "table with 1 element created\n";
}

void Table::add(Element* element){
    Element* cur = first;
    while(cur->next) cur = cur->next;
    cur->next = element;
    len++;
}

void Table::remove(Element &element){
    Element* cur = first;
    while (cur && cur->next != &element) cur=cur->next;
    if(!cur->next && cur != &element){
        std::cout << "no matching element";
        return;
    }
    if((cur->next = &element)){
        if(element.next){
            cur->next->next = cur->next;
        } else {
            cur->next = nullptr;
        }
    }
    len--;
}

void Table::remove(int index){
    if(index > len) {
        std::cout << "Given index is higher than table length\n";
        return;
    }
    int counter = 0;
    Element* cur = first;
    while (counter != index) {
        cur=cur->next;
        counter++;
    }
    if(cur->next->next){
        cur->next = cur->next->next;
    } else {
        cur->next = nullptr;
    }
    len--;
}

Table::Element* Table::find(int index){
    if(index > len) return NULL;
    int counter = 0;
    Element* result = first;
    while (counter != index) {
        result = result->next;
        counter++;
    }
    return result;
}

int Table::find(Element *element){
    Element* cur = first;
    int result = 0;

    while (element != cur) {
        cur= cur->next;
        result++;
        if(element == cur) return result;
    }
    return -1;
}


int Table::length() {return len;}

std::string Table::to_string(){
    std::string result = "-/- The table:\n";
    Element* cur = first;
    while (cur) {
        result += cur->to_string() + "\n---\n";
        cur=cur->next;
    }
    return result + "length: " + std::to_string(len) + "\n";
}

std::vector<Table::Element*> Table::to_vector() {
    Element* cur = first;
    std::vector<Element*> target;
    while(cur) {
        target.push_back(cur);
        cur=cur->next;
    }
    return target;
}
//TODO: доделать сортировку
/*
void Table::quadratic_sample() {
    std::vector<Element*> vectored_table = to_vector();
    int length = sqrt(vectored_table.size());
    if(length*length < vectored_table.size()) length++;
    std::vector<std::vector<Element*>> fractioned_vector;
    for (size_t i = 0; i < length; i + sqrt(length)) {
        size_t j = i;
        std::vector<Element*> partition;
        while(j != sqrt(length) + i){
            partition.push_back(vectored_table[j]);
            j++;
        }
        fractioned_vector.push_back(partition);
    }
}
*/

void Table::sort() {
    quadratic_sample();
}

Table::Element::Element() : group_code(NULL), name(NULL), birth_date(NULL), next(nullptr)
{
    std::cout << "Empty element created \n";
}

Table::Element::Element(const int& group_code, const std::string& name, const std::string birth_date) :
        group_code(group_code),
        name(name),
        birth_date(birth_date),
        next(nullptr)
{
    std::cout << "Element without next element ptr created\n";
}

Table::Element::Element(const int& group_code, const std::string& name, const std::string birth_date, Element* next) :
        group_code(group_code),
        name(name),
        birth_date(birth_date),
        next(next)
{
    std::cout << "Element with all fields provided created\n";
}

std::string Table::Element::to_string(){
    return "Element: \nname: " + name + "\nbirth date: " + birth_date + "\ngroup code: " + std::to_string(group_code);
}
