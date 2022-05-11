//
// Created by Артемий Касьяник on 11.05.2022.
//

#include "Drawer.h"
#include <iostream>
#include <vector>

Drawer::Drawer(const int &width, const int &height) : width(width), heigth(height){
    picture.resize(height);
    for (int i = 0; i < height; ++i) {
        picture[i].resize(width);
    }
    fill();
}
void Drawer::draw() {
    for (int i = 0; i < heigth; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << picture[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Drawer::fill() {

    if (width<heigth){
        for (int k = 0; k < (width+1)/2; k++){
            circle(k);
        }
    } else {
        for (int k = 0; k < (heigth+1)/2; k++){
            circle(k);
        }
    }

}

void Drawer::circle(const int& k) {
    for (int i = 0+k; i < width-k; i++){
        if (picture[heigth-heigth+k][i] == 0)
            picture[heigth-heigth+k][i] = nums;
        nums++;
    }
    nums--;
    for (int i = 0+k; i < heigth-k; i++){
        if (picture[i][width-1-k] == 0)
            picture[i][width-1-k] = nums;
        nums++;
    }
    nums--;
    for (int i = width-p; i >= 0+k; i--){
        if (picture[heigth-1-k][i]==0)
            picture[heigth-1-k][i] = nums;
        nums++;
    }
    nums--;
    for (int i = heigth-p; i > 0+k; i--){
        if (picture[i][0+k] == 0)
            picture[i][0+k] = nums;
        nums++;
    }
    p++;
}


