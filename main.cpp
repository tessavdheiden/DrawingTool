#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;
int width = 20;
int height = 5;
char color = 'x';

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

Canvas canvas(width, height);

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
}
void fill(Canvas& c, const int col, const int row, char oldColor, char color)
{
    if (row < 0 || row >= c.getHeight() || col < 0 || col >= c.getWidth() || c.getValues(col, row) != oldColor)
    {
        return;
    }
    
    c.setValues(col, row, color);
    fill(canvas, col+1, row, oldColor, color);
    fill(canvas, col-1, row, oldColor, color);
    fill(canvas, col, row+1, oldColor, color);
    fill(canvas, col, row-1, oldColor, color);
    return;
}

void bucketFill(Canvas& c, const int col, const int row, char color)
{
    if (c.getValues(col, row) == color){
        return;
    }
    fill(canvas, col, row, c.getValues(col, row), color);
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

int main(int argc, const char * argv[]) {
    char input;
    int row, col;
    int row2, col2;
    do
    {
        displayCanvas(canvas);
        cout << "\n Enter command: \n N: Create new canvas \n C: Set color \n L: Create new line \n R: Create new rectangle \n B: Fill area \n Q: Quit \n " << endl;
        
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
