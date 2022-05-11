//
// Created by Артемий Касьяник on 03.05.2022.
//

#include <iostream>
#include <string>
#include <utility>
#include "Element.h"

Element::Element() : name(NULL), group_code(NULL), birth_date(NULL){
    std::cout << "empty element created\n";
}

Element::Element(std::string name, std::string birth_date, int group_code) : name(std::move(name)), birth_date(std::move(birth_date)), group_code(group_code) {
    std::cout << "element with given parameters created\n";
}

int Element::get_group_code() {
    return group_code;
}

void Element::set_group_code(int value) {
    group_code = value;
}

std::string Element::get_name() {
    return name;
}

void Element::set_name(std::string value) {
    name = value;
}

std::string Element::get_birth_date() {
    return birth_date;
}

void Element::set_birth_date(std::string value) {
    birth_date = value;
}

std::string Element::to_string() {
    return "\nElement: \n name:" + name + "\n birth date" + birth_date + "\n group code: " + std::to_string(group_code);
}

//todo: finish explicit element destructor
Element::~Element() {
//    delete &name, &group_code, &birth_date;
}

bool Element::operator<(Element other) const {
    if(name < other.name) return true;
    return false;
}

bool Element::operator==(Element other) const {
    return (name == other.name) && (group_code == other.group_code) && (birth_date == other.birth_date);
}

bool Element::operator==(Element *other) const {
    return (name == other->name) && (group_code == other->group_code) && (birth_date == other->birth_date);
}

Element Element::MAX_SIZE() {
    return Element("STRINGINF", "nan", INT32_MAX);
}

bool Element::operator>(Element other) const {
    return name > other.name;
}

//template<class T>
//bool Element::operator==(T other) const {
//    Element element = static_cast<Element>(other);
//    return (name == element.name) && (group_code == element.group_code) && (birth_date == element.birth_date);
//}
