//
//  drawing.h
//  HelloWorld
//
//  Created by Tessa van der Heiden on 13.07.19.
//  Copyright © 2019 Tessa van der Heiden. All rights reserved.
//

#ifndef drawing_h
#define drawing_h

#include "canvas.h"

void fill(Canvas& c, const int col, const int row, char oldColor, char color)
{
    if (row < 0 || row >= c.getHeight() || col < 0 || col >= c.getWidth() || c.getValues(col, row) != oldColor)
    {
        return;
    }
    
    c.setValues(col, row, color);
    fill(c, col+1, row, oldColor, color);
    fill(c, col-1, row, oldColor, color);
    fill(c, col, row+1, oldColor, color);
    fill(c, col, row-1, oldColor, color);
    return;
}

void bucketFill(Canvas& c, const int col, const int row, char color)
{
    if (c.getValues(col, row) == color){
        return;
    }
    fill(c, col, row, c.getValues(col, row), color);
}

void drawStraightLine(Canvas& c, const int col1, const int row1, const int col2, const int row2, char color)
{
    if (row2==row1)
    {
        for (int col = col1; col <= col2; ++col)
        {
            if (col <= c.getWidth())
                c.setValues(col-1, row1-1, color);
        }
    }
    else if (col2==col1){
        for (int row = row1; row <= row2; ++row)
        {
            if (row <= c.getHeight())
                c.setValues(col1-1, row-1, color);
        }
    }
}

void drawRectangle(Canvas& c, const int col1, const int row1, const int col2, const int row2, char color)
{
    drawStraightLine(c, col1, row1, col2, row1, color);
    drawStraightLine(c, col1, row2, col2, row2, color);
    
    drawStraightLine(c, col1, row1, col1, row2, color);
    drawStraightLine(c, col2, row1, col2, row2, color);
}

#endif /* drawing_h */
