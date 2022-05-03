//
// Created by Артемий Касьяник on 03.05.2022.
//

#ifndef LABS_ELEMENT_H
#define LABS_ELEMENT_H


#include <string>

class Element {
private:
    int group_code;
    std::string name;
    std::string birth_date;
public:
    Element();
    Element(std::string name, std::string birth_date, int group_code);
    ~Element();
    int get_group_code();
    void set_group_code(int value);
    std::string get_name();
    void set_name(std::string value);
    std::string get_birth_date();
    void set_birth_date(std::string value);
    std::string to_string();
    bool operator ==(Element& element);
};


#endif //LABS_ELEMENT_H
