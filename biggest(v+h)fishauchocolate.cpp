#include <iostream>
#include <climits>
using namespace std;
const char UP_RIGHT = 187;
const char DOWN_RIGHT = 188;
const char DOWN_LEFT = 200;
const char UP_LEFT = 201;

const char UP_EDGE = 203;
const char RIGHT_EDGE = 185;
const char DOWN_EDGE = 202;
const char LEFT_EDGE = 204;

const char HORIZONTAL = 205;
const char VERTICAL = 186;

const char MIDDLE = 206;
//const char FILLING = 0xb0; //0x20 for space, 0xb0 to 0xb2 for fillings

const int MAX_ROWS = INT_MAX;
const int MAX_COLS = 117;
const int TITLE_SIZE = 236;

void Chocolate(int, int, int);
void Title (string);
// COMPILE TIMESTAMP: 10/26/2023 10:06 PM, RAN ON FIRST TRY!
// COMPILE TIMESTAMP: 10/26/2023 10:51 PM, ADDED HORIZONTAL* LINES, RAN ON FIRST TRY, AGAIN! (* previously VERTICAL)
// COMPILE TIMESTAMP: 10/26/2023 10:59 PM, ADDED VERTICAL LINES, TOOK A FEW MORE TRIES
// COMPILE TIMESTAMP: 10/26/2023 11:05 PM, ADDED FILLINGS INSIDE THE CHOCOLATE, LOWERED MAX COLS AND ROWS DUE TO SIZE RESTRICTIONS
// COMPILE TIMESTAMP: 11/11/2023 21:11 PM, ADDED USER INPUT FOR TEXTURE CHOICE
int main()
{
    string title = "[CHOCOLATE SIMULATOR]";
    Title(title);
    int rows, cols, texture;
    cout<<"Input length of chocolate (max: " << MAX_ROWS << "): ";
    cin>>rows;
    cout<<"Input width of chocolate (max: " << MAX_COLS << "): ";
    cin>>cols;
    cout<<"Type of chocolate filling (input 0 for nothing, 1 through 3 for different textures): ";
    cin>>texture;

    Chocolate(rows, cols, texture);
    return 0;
}
void Title (string title)
{
    int distance = (TITLE_SIZE-title.size()-2)/2;
    cout<<UP_LEFT;
    for(int i=1; i<TITLE_SIZE-1; i++)
    {
        cout<<HORIZONTAL;
    }
    cout<<UP_RIGHT;
    cout<<endl;
    cout<<VERTICAL;
    for(int i=0; i<distance; i++)
    {
        cout<<" ";
    }
    cout<<title;
    for(int i=0; i<distance; i++)
    {
        cout<<" ";
    }
    cout<<" ";
    cout<<VERTICAL;
    cout<<endl;
    cout<<DOWN_LEFT;
    for(int i=1; i<TITLE_SIZE-1; i++)
    {
        cout<<HORIZONTAL;
    }
    cout<<DOWN_RIGHT;
    cout<<endl;
}
void Chocolate(int rows, int cols, int texture)
{
    rows--;
    cols--;
    char filling;
    if(texture == 0)
    {
        filling = (char)0x20;
    }
    else
    {
        filling = (char)(0xaf+texture);
    }
    cout<<UP_LEFT;
    for(int i=0; i<cols; i++)
    {
        cout<<HORIZONTAL; //
        cout<<UP_EDGE;
    }
    cout<<HORIZONTAL;
    cout<<UP_RIGHT<<endl;
    for(int i=0; i<rows; i++)
    {
        for(int k=0; k<=cols; k++) //<= cols, important
        {
            cout<<VERTICAL<<filling;
        }
        cout<<VERTICAL;
        cout<<endl;
        cout<<LEFT_EDGE;
        for(int j=0; j<cols; j++)
        {
            cout<<HORIZONTAL; //
            cout<<MIDDLE;
        }
        cout<<HORIZONTAL; //
        cout<<RIGHT_EDGE<<endl;
    }
    for(int i=0; i<=cols; i++) //<= cols, important
    {
        cout<<VERTICAL<<filling;
    }
    cout<<VERTICAL;
    cout<<endl;
    cout<<DOWN_LEFT;
    for(int i=0; i<cols; i++)
    {
        cout<<HORIZONTAL; //
        cout<<DOWN_EDGE;
    }
    cout<<HORIZONTAL; //
    cout<<DOWN_RIGHT<<endl;
}
