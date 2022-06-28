// Solution.cpp
// Created by Артемий Касьяник on 11.05.2022.
//

#include "Solution.h"
#include "stdio.h"
#include <iostream>

Solution::Solution() {
    std::getline(std::cin, input_string);
    for (int i = 65; i < 91; ++i) {
        symbols.insert(i);
    }
    for (int i = 97; i < 123; ++i) {
        symbols.insert(i);
    }
    for (int i = 48; i < 58; ++i) {
        digits.insert(i);
    }
}

Solution::Solution(std::string &input_string) : input_string(input_string) {
    for (int i = 65; i < 91; ++i) {
        symbols.insert(i);
    }
    for (int i = 97; i < 123; ++i) {
        symbols.insert(i);
    }
    for (int i = 48; i < 58; ++i) {
        digits.insert(i);
    }
}

bool Solution::obey() {
    for (int i = 1; i < input_string.size(); ++i) {
        if (symbols.contains(input_string[i]) && symbols.contains(input_string[i - 1])) return false;
        if (digits.contains(input_string[i]) && digits.contains(input_string[i - 1])) return false;
    }
    return true;
}
