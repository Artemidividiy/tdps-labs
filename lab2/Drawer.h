//
// Created by Артемий Касьяник on 11.05.2022.
//

#ifndef LABS_DRAWER_H
#define LABS_DRAWER_H

#include <vector>

class Drawer {
private:
    void circle(const int& k);
    std::vector<std::vector<int>> picture;
    int width, heigth;
    void fill();
    int nums = 1;
    int p = 1;
public:
    Drawer(const int &width, const int &height);
    void draw();
};


#endif //LABS_DRAWER_H
