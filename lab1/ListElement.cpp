//
// Created by Артемий Касьяник on 28.06.2022.
//

#include "ListElement.h"
#include <string>
#include <iostream>

ListElement::ListElement() : name(NULL), group_code(NULL), birth_date(NULL), next(nullptr){
    std::cout << "empty element created\n";
}

ListElement::ListElement(std::string name, std::string birth_date, int group_code, ListElement* next) : name(std::move(name)), birth_date(std::move(birth_date)), group_code(group_code), next(next) {
    std::cout << "element with given parameters created\n";
}

ListElement::ListElement(std::string name, std::string birth_date, int group_code) : name(name), birth_date(birth_date), group_code(group_code), next(
        nullptr) {
    std::cout << "element with given parameters created\n";
}
int ListElement::get_group_code() {
    return group_code;
}

void ListElement::set_group_code(int value) {
    group_code = value;
}

std::string ListElement::get_name() {
    return name;
}

void ListElement::set_name(std::string value) {
    name = value;
}

std::string ListElement::get_birth_date() {
    return birth_date;
}

void ListElement::set_birth_date(std::string value) {
    birth_date = value;
}

std::string ListElement::to_string() {
    return "\nElement: \n name:" + name + "\n birth date" + birth_date + "\n group code: " + std::to_string(group_code);
}

//todo: finish explicit element destructor
ListElement::~ListElement() {
//    delete &name, &group_code, &birth_date;
}

bool ListElement::operator<(ListElement other) const {
    if(name < other.name) return true;
    return false;
}

bool ListElement::operator==(ListElement other) const {
    return (name == other.name) && (group_code == other.group_code) && (birth_date == other.birth_date);
}

bool ListElement::operator==(ListElement *other) const {
    return (name == other->name) && (group_code == other->group_code) && (birth_date == other->birth_date);
}

ListElement ListElement::MAX_SIZE() {
    return ListElement("STRINGINF", "nan", INT32_MAX);
}

bool ListElement::operator>(ListElement other) const {
    return name > other.name;
}


