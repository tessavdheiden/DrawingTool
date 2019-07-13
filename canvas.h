//
//  canvas.h
//  HelloWorld
//
//  Created by Tessa van der Heiden on 13.07.19.
//  Copyright © 2019 Tessa van der Heiden. All rights reserved.
//

#ifndef canvas_h
#define canvas_h

#include <vector>

using namespace std;

class Canvas {
    int width, height;
    vector<vector<char>> values;
public:
    Canvas(){};
    Canvas(int w, int h): width(w), height(h){values = vector<vector<char>>(h, vector<char>(w, ' '));};
    void setWidth(int w) {
        values = w > width ? vector<vector<char>>(height, vector<char>(w, ' ')) : values;
        width = w;
    };
    void setHeight(int h) {
        values = h > height ? vector<vector<char>>(h, vector<char>(width, ' ')) : values;
        height = h;};
    void setValues (int col, int row, char color){ values[row][col]=color;};
    char getValues (int col, int row) const { return values[row][col] != '\0'? values[row][col]: ' ';};
    const int getWidth() const {return width;};
    int getHeight() const {return height;};
};


#endif /* canvas_h */
