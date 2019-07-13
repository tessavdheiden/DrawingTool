#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "canvas.h"
#include "drawing.h"

using namespace std;

void displayCanvas(const Canvas& c)
{
    for (int j = -1; j < c.getWidth()+1; j++)
    {
        cout << "-" ;
    }
    cout << "\n";
    for (int i = 0; i < c.getHeight(); i++)
    {
        for (int j = -1; j < c.getWidth()+1; j++)
        {
            if ((j == -1 || j == c.getWidth())){cout << '|';}
            else{
                cout << c.getValues(j, i);
            }
        }
        cout << "\n" ;
    }
    for (int j = -1; j < c.getWidth()+1; j++)
    {
        cout << "-" ;
    }
    cout << endl;
}


int main(int argc, const char * argv[]) {
    int width = 20;
    int height = 10;
    char color = 'x';
    
    Canvas canvas(width, height);
    
    char input;
    int row, col;
    int row2, col2;
    
    cout << "\n Enter command: \n N: Create new canvas \n C: Set color \n L: Create new line \n R: Create new rectangle \n B: Fill area \n Q: Quit \n " << endl;
    
    do
    {
        displayCanvas(canvas);
        cin >> input;
        switch (input) {
            case 'N':
            {
                cout << "Enter width \n...";
                cin >> width;
                cout << "Enter height \n...";
                cin >> height;
                canvas.setWidth(width);
                canvas.setHeight(height);
                break;
            }
            case 'c':
            case 'C':
            {
                cout << "Enter color \n...";
                cin >> color;
                break;
            }
            case 'l':
            case 'L':
            {
                cout << "Enter first col \n...";
                cin >> col;
                cout << "Enter first row \n...";
                cin >> row;
                cout << "Enter second col \n...";
                cin >> col2;
                cout << "Enter second row \n...";
                cin >> row2;
                drawStraightLine(canvas, col, row, col2, row2, color);
                break;
            }
            case 'r':
            case 'R':
            {
                cout << "Enter first col \n...";
                cin >> col;
                cout << "Enter first row \n...";
                cin >> row;
                cout << "Enter second col \n...";
                cin >> col2;
                cout << "Enter second row \n...";
                cin >> row2;
                drawRectangle(canvas, col, row, col2, row2, color);
                break;
            }
            case 'B':
            case 'b':
            {
                cout << "Enter row  \n...";
                cin >> row;
                cout << "Enter col  \n...";
                cin >> col;
                bucketFill(canvas, col, row, color);
                break;
            }
            case 'Q':
            case 'q':
                break;
            default:
                cout << "No valid input \n";
        }
        
    } while (!((input == 'Q') || (input == 'q')));
    return 0;
}
