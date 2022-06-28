// Solution.h
// Created by Артемий Касьяник on 11.05.2022.
//

#ifndef LABS_SOLUTION_H
#define LABS_SOLUTION_H
#include <vector>
#include <string>
#include <set>
class Solution {
private:
    std::set<char> symbols;
    std::set<char> digits;
    std::string input_string;
public:
    Solution();
    Solution(std::string &input_string);
    bool obey();
};


#endif //LABS_SOLUTION_H
