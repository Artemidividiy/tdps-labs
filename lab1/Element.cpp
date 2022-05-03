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

bool Element::operator==(Element &element) {
    if(name == element.name && birth_date == element.birth_date && group_code == element.group_code) return true;
    return false;
}

Element::~Element() {
//    delete &name, &group_code, &birth_date;
}
