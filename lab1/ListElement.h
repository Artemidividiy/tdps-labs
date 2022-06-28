//
// Created by Артемий Касьяник on 28.06.2022.
//

#ifndef LABS_LISTELEMENT_H
#define LABS_LISTELEMENT_H

#include <string>

class ListElement {
private:
    int group_code;
    std::string name;
    std::string birth_date;
public:
    ListElement* next;
    static ListElement MAX_SIZE();
    ListElement();
    ListElement(std::string name, std::string birth_date, int group_code, ListElement *next);
    ListElement(std::string name, std::string birth_date, int group_code);
    ~ListElement();
    int get_group_code();
    void set_group_code(int value);
    std::string get_name();
    void set_name(std::string value);
    std::string get_birth_date();
    void set_birth_date(std::string value);
    std::string to_string();
    bool operator==(ListElement other) const;
    bool operator==(ListElement* other) const;

//    template<class T>
//            bool operator==(T other) const;
    bool operator <(ListElement other) const;
    bool operator >(ListElement other) const;
};



#endif //LABS_LISTELEMENT_H
