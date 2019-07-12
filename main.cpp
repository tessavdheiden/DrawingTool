#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;
int width = 20;
int height = 5;
char color = 'x';
enum eCommand {NEW = 'N', COLOR = 'C', LINE = 'L', RECT = 'R', BUCKET, QUIT};
eCommand command;

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
    void setValues (int x, int y, char color){ values[x][y]=color;};
    char getValues (int x, int y) const { return values[x][y];};
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
                cout << c.getValues(i, j);
            }
        }
        cout << "\n" ;
    }
    for (int j = -1; j < c.getWidth()+1; j++)
    {
        cout << "-" ;
    }
}
void fill(Canvas& c, const int i, const int j, char oldColor, char color)
{
    if (i < 0 || i >= c.getHeight() || j < 0 || j >= c.getWidth() || c.getValues(i, j) != oldColor)
    {
        return;
    }
    
    c.setValues(i, j, color);
    fill(canvas, i+1, j, oldColor, color);
    fill(canvas, i-1, j, oldColor, color);
    fill(canvas, i, j+1, oldColor, color);
    fill(canvas, i, j-1, oldColor, color);
    return;
}

void bucketFill(Canvas& c, const int row, const int col, char color)
{
    if (c.getValues(row, col) == color){
        return;
    }
    fill(canvas, row, col, c.getValues(row, col), color);
}

int main(int argc, const char * argv[]) {
    char input;
    int row, col;
    do
    {
        displayCanvas(canvas);
        cout << "\n Enter command: \n N for new canvas \n C for color \n L for line \n R for rectangle \n B for bucket \n ...";
        cin >> input;
        switch (input) {
            case 'N':
            {
                cout << "Enter width ";
                cin >> width;
                cout << "Enter height ";
                cin >> height;
                canvas.setWidth(width);
                canvas.setHeight(height);
                break;
            }
            case 'C':
            {
                cout << "Enter color ";
                cin >> color;
                break;
            }
            case 'B':
            case 'b':
            {
                cout << "Enter row ";
                cin >> row;
                cout << "Enter col ";
                cin >> col;
                bucketFill(canvas, row, col, color);
                break;
            }
            default:
                cout << "No valid input ";
            }
       
    } while (!((input == 'Q') || (input == 'q')));
    

    return 0;
}
