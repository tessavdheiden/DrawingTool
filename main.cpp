#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayCanvas(const vector<vector<char> >& vy)
{
    for (int j = 0; j < vy[0].size(); j++)
    {
        cout << "-" ;
    }
    for (int i = 0; i < vy.size(); i++)
    {
        cout << "\n|" ;
        for (int j = 0; j < vy[i].size(); j++)
        {
            cout << " " << vy[i][j];
        }
        cout << "|" ;
    }
    cout << "\n";
    for (int j = 0; j < vy[0].size(); j++)
    {
        cout << "-" ;
    }
}

vector<vector<char>> createCanvas(const int w, const int h)
{
    vector<vector<char>> canvas(w, vector<char>(h));
    return canvas;
}

void fill(vector<vector<char>>& canvas, const int i, const int j, char oldColor, char color)
{
    if (i < 0 || i >= canvas.size() || j < 0 || j >= canvas[0].size() || canvas[i][j] != oldColor)
    {
        return;
    }
    
    canvas[i][j] = color;
    fill(canvas, i+1, j, oldColor, color);
    fill(canvas, i-1, j, oldColor, color);
    fill(canvas, i, j+1, oldColor, color);
    fill(canvas, i, j-1, oldColor, color);
    return;
}

void bucketFill(vector<vector<char>>& canvas, const int row, const int col, char color)
{
    if (canvas[row][col] == color){
        return;
    }
    fill(canvas, row, col, canvas[row][col], color);
}

int main(int argc, const char * argv[]) {
    char input;
    int w, h;
    int row, col;
    char color = 'x';
    cout << "Enter width ";
    cin >> w;
    cout << "Enter height ";
    cin >> h;
    vector<vector<char>> canvas = createCanvas(w, h);
    displayCanvas(canvas);
    
    do
    {
        cout << "\n Enter feature ";
        cin >> input;
        switch (input) {
            case 'N':
            case 'n':
            {
                cout << "Enter width ";
                cin >> w;
                cout << "Enter height ";
                cin >> h;
                canvas = createCanvas(w, h);
                displayCanvas(canvas);
                break;
            }
            case 'C':
            case 'c':
            {
                cout << "Enter color ";
                cin >> color;
                displayCanvas(canvas);
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
                displayCanvas(canvas);
                break;
            }
            default:
                cout << "No valid input ";
        }
    } while (!((input == 'Q') || (input == 'q')));
    

    return 0;
}
