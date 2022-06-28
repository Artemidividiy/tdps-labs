//
// Created by Артемий Касьяник on 28.06.2022.
//

#include "List.h"
#include "iostream"
List::List(ListElement *first) : first(first), len(1){
    std::cout << "list with one element created\n";
}



void List::add(ListElement *element) {

    if(len == 1){
        if (*element > *first) {
            first->next = element;
            len++;
            return;
        }
        else {
            element->next = first;
            first = element;
            len++;
            return;
        }
    }
    ListElement *tmp = first;
    while(tmp->next){
        if(element->get_name() < tmp->next->get_name()) {
            element->next = tmp->next;
            tmp->next = element;
            len++;
            return;
        }
        tmp = tmp->next;
    }
    tmp->next = element;
    len++;
}

int List::find(const ListElement &element) {
    int target = 0;
    ListElement *tmp = first;
    while(tmp){
        if (*tmp == element) {
            return target;
        }
        ++target;
        tmp = tmp->next;
    }
}

ListElement List::find(int index) {
    ListElement *tmp = first;
    int counter = 0;
    while(tmp){
        if(index == counter) return *tmp;
        ++counter;
        tmp = tmp->next;
    }
}

int List::length() {
    return len;
}

void List::remove(const ListElement &element) {
    ListElement *tmp = first;
    while(tmp->next){
        if (*tmp->next == element){
            tmp->next = element.next;
            len--;
            return;
        }
    }
}

std::string List::to_string() {
    ListElement *tmp = first;
    std::string target = "";
    while(tmp){
        target += tmp->to_string();
    }
}
