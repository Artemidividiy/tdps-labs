//
// Created on 03.05.2022.
//

#ifndef LABS_TABLEELEMENT_H
#define LABS_TABLEELEMENT_H


#include <string>

class TableElement {
private:
    int group_code;
    std::string name;
    std::string birth_date;
public:
    static TableElement MAX_SIZE();
    TableElement();
    TableElement(std::string name, std::string birth_date, int group_code);
    ~TableElement();
    int get_group_code();
    void set_group_code(int value);
    std::string get_name();
    void set_name(std::string value);
    std::string get_birth_date();
    void set_birth_date(std::string value);
    std::string to_string();
    bool operator==(TableElement other) const;
    bool operator==(TableElement* other) const;

//    template<class T>
//            bool operator==(T other) const;
    bool operator <(TableElement other) const;
    bool operator >(TableElement other) const;
};


#endif //LABS_TABLEELEMENT_H
