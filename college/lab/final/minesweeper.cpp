#include <iostream>
using namespace std;

void minesweeper()
{
    int size;
    cout << "Enter the size of the board: ";
    cin >> size;
    char board[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 'X';
        }
    }
    int mines;
    cout << "Enter the number of mines: ";
    cin >> mines;
    int mineX[mines];
    int mineY[mines];
    for (int i = 0; i < mines; i++)
    {
        mineX[i] = rand() % (size - 1);
        mineY[i] = rand() % (size - 1);
        ;
        board[mineX[i]][mineY[i]] = '*';
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    int x, y;
    cout << "Enter the x coordinate of the cell you want to uncover: ";
    cin >> x;
    cout << "Enter the y coordinate of the cell you want to uncover: ";
    cin >> y;
    if (board[x][y] == '*')
    {
        cout << "You lose!" << endl;
        exit(0);
    }
    else
    {
        int count = 0;
        for (int i = 0; i < mines; i++)
        {
            if (mineX[i] == x && mineY[i] == y)
            {
                count++;
            }
        }
        board[x][y] = count + '0';
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        minesweeper();
    }
    return 0;
}
