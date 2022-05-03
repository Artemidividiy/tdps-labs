//
// Created by Артемий Касьяник on 03.05.2022.
//

#ifndef LABS_LAB1_H
#define LABS_LAB1_H

#include <cstdio>
#include <string>
#include <vector>

class Table {
public:
    struct Element{
        int group_code;
        std::string name;
        std::string birth_date;
        Element* next;
        Element();
        Element(const int& group_code, const std::string& name, const std::string birth_date);
        Element(const int& group_code, const std::string& name, const std::string birth_date, Element* next);
        std::string to_string();
    };
    Table();
    Table(Element& element);
    void add(Element *element);
    void remove(Element& element);
    void remove(int index);
    Element* find(int index);
    int find(Element* element);
    void sort();

    int length();
    std::string to_string();
private:
    int len;
    Element* first;
    void quadratic_sample();
    std::vector<Element*> to_vector();
};
#endif //LABS_LAB1_H
