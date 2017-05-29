#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>

using namespace std;

#define SEA 0
#define SHIP 1
#define HIT 2
#define NOHIT 3

const int rows = 10;
const int columns = 10;
int ships = 10;
int grid[rows][columns];

// Initialize
void initArray()
{
    for(int i = 0; i < rows; i++)    //This loops on the rows.
        {
            for(int j = 0; j < columns; j++) //This loops on the columns
                {
                    grid[i][j] = SEA;
                }
        }
}

// Display the board
void printArray()
{
    cout << setw(4) << " ";
    cout << "0 1 2 3 4 5 6 7 8 9" << endl;
    for(int i = 0; i < rows; i++)
        {
        cout << setw(2) << i << "  ";
            for(int j = 0; j < columns; j++)
                {
                    if(grid[i][j] == SHIP || grid[i][j] == SEA)
                    {
                        cout << "* ";
                    }
                    else if(grid[i][j] == NOHIT)
                    {
                        cout << "O ";
                    }
                    else if(grid[i][j] == HIT)
                    {
                        cout << "X ";
                    }
                }
            cout << endl;
        }
}

// Number of ships
int numOfShips()
{
    int c = 0;

    for(int i = 0; i < rows; i++)    //This loops on the rows.
        {
            for(int j = 0; j < columns; j++) //This loops on the columns
                {
                    if(grid[i][j] == SHIP)
                    c++;
                }
        }
        return c;
}



//Generate random ships
void gnrShips()
{
    int s = 0;
    while(s < ships)
    {
        int x = rand() % rows;
        int y = rand() % columns;
        if(grid[x][y] != 1)
        {
            s++;
            grid[x][y] = SHIP;

        }
    }
}

bool userAttack(int x, int y)
{
    if(grid[x][y] == SHIP)
    {
        grid[x][y] = HIT;
        return true;
    }
    else if(grid[x][y] = NOHIT)
    return false;
}


int main()
{
    srand(time(0));
    initArray();
    printArray();
    gnrShips();
    int position1, position2;
    int trials = 20;

    cout << "---------------------------------" << endl;
    cout << "Object of Battleship:\nTo become the winner of Battleship you must be able to find (sink)\nall ten ships in your opponent’s fleet" << endl;
    cout << "---------------------------------" << endl;
    do
    {

        cout << endl << "Please input location(ROW,COLUMN): "<<  endl;
        cin >> position1 >> position2;
        bool found = false;

        if(userAttack(position1,position2)){
            found = true;
            cout << endl << "---------------------------------" << endl;
            cout << endl << "There is a ship at that Position." <<  endl;
            cout << endl << "---------------------------------" << endl;

                }
        if(!found)
        {
        trials--;
        cout << endl << "------------------------" << endl;
        cout << "Sorry no ship at that Position" << endl;
        cout << "------------------------" << endl;
        cout << "Number of ships left: " << numOfShips() << endl;
        cout << "Number of tries left: " << trials << endl;
        cout << "------------------------" << endl;
        }printArray();
    }while(trials > 0);
    cout << endl << "---------------------------------" << endl;
    cout << endl << "Game Over!" << endl;
    cout << endl << "---------------------------------" << endl;

    printArray();
    return 0;

}
