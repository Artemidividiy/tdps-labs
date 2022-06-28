//
// Created by Артемий Касьяник on 03.05.2022.
//

#include <iostream>
#include <string>
#include <utility>
#include "TableElement.h"

TableElement::TableElement() : name(NULL), group_code(NULL), birth_date(NULL){
    std::cout << "empty element created\n";
}

TableElement::TableElement(std::string name, std::string birth_date, int group_code) : name(std::move(name)), birth_date(std::move(birth_date)), group_code(group_code) {
    std::cout << "element with given parameters created\n";
}

int TableElement::get_group_code() {
    return group_code;
}

void TableElement::set_group_code(int value) {
    group_code = value;
}

std::string TableElement::get_name() {
    return name;
}

void TableElement::set_name(std::string value) {
    name = value;
}

std::string TableElement::get_birth_date() {
    return birth_date;
}

void TableElement::set_birth_date(std::string value) {
    birth_date = value;
}

std::string TableElement::to_string() {
    return "\nElement: \n name:" + name + "\n birth date" + birth_date + "\n group code: " + std::to_string(group_code);
}

//todo: finish explicit element destructor
TableElement::~TableElement() {
//    delete &name, &group_code, &birth_date;
}

bool TableElement::operator<(TableElement other) const {
    if(name < other.name) return true;
    return false;
}

bool TableElement::operator==(TableElement other) const {
    return (name == other.name) && (group_code == other.group_code) && (birth_date == other.birth_date);
}

bool TableElement::operator==(TableElement *other) const {
    return (name == other->name) && (group_code == other->group_code) && (birth_date == other->birth_date);
}

TableElement TableElement::MAX_SIZE() {
    return TableElement("STRINGINF", "nan", INT32_MAX);
}

bool TableElement::operator>(TableElement other) const {
    return name > other.name;
}
