#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> moves(9, " ");
int lastMove;
bool played[9];
bool draw = false;

void displayScreen()
{
    system("cls");
    cout << "       |       |       " << endl;
    cout << "   " << moves[0] << "   |   " << moves[1] << "   |   " << moves[2] << "   " << endl;
    cout << "       |       |       " << endl;
    cout << "-----------------------" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << moves[3] << "   |   " << moves[4] << "   |   " << moves[5] << "   " << endl;
    cout << "       |       |       " << endl;
    cout << "-----------------------" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << moves[6] << "   |   " << moves[7] << "   |   " << moves[8] << "   " << endl;
    cout << "       |       |       " << endl;

    cout << "PLAYER 1: X    PLAYER 2: O" << endl;
}

void askPlayer1Input()
{
    cout << "Player 1 Enter your move: " << endl;
    cout << "Select the number where you want to place your move." << endl;
    int move;
    cin >> move;
    if (played[move - 1])
    {
        cout << "Please enter valid move!!" << endl;
        askPlayer1Input();
        return;
    }
    played[move - 1] = true;
    moves[move - 1] = 'X';
    lastMove = 1;
}

void askPlayer2Input()
{
    cout << "Player 2 Enter your move: " << endl;
    cout << "Select the number where you want to place your move." << endl;
    int move;
    cin >> move;
    if (played[move - 1])
    {
        cout << "Please enter valid move!!" << endl;
        askPlayer2Input();
        return;
    }
    played[move - 1] = true;
    moves[move - 1] = 'O';
    lastMove = 2;
}

bool checkDraw()
{
    for (int i = 0; i < 9; i++)
    {
        if (!played[i])
            return false;
    }
    return true;
}

bool isGameOver()
{

    if (
        (moves[0] == moves[1] && moves[1] == moves[2]) ||
        (moves[3] == moves[4] && moves[3] == moves[5]) ||
        (moves[8] == moves[7] && moves[7] == moves[6]) ||
        (moves[0] == moves[3] && moves[3] == moves[6]) ||
        (moves[7] == moves[1] && moves[1] == moves[4]) ||
        (moves[2] == moves[5] && moves[5] == moves[8]) ||
        (moves[0] == moves[4] && moves[4] == moves[8]) ||
        (moves[2] == moves[4] && moves[4] == moves[6])

    )
        return true;
    else if (checkDraw())
    {
        draw = true;
        return true;
    }

    else
        return false;
}

void GameOver()
{
    cout << "Game Over" << endl;
    if (draw)
    {
        cout << "The Game is a Draw!!" << endl;
    }
    else
        cout << "Player " << lastMove << " has won the game!\nCongratulations\n\n"
             << endl;
}

void playGame()
{
    displayScreen();
    askPlayer1Input();
    if (isGameOver())
        return;
    else
    {
        displayScreen();
        askPlayer2Input();
    }
}

void menu()
{
    cout << "Welcome to TIC.TAC.TOE" << endl;
    cout << "What would you like to do?" << endl;
    cout << "\t1.Play Game\n\t2.Quit Game" << endl;
}

void resetBoard()
{
    for (int i = 0; i < 9; i++)
    {
        moves[i] = char('0' + i + 1);
        played[i] = false;
    }
    draw = false;
}

int main()
{
    menu();
    int choice;
    cin >> choice;
    while (choice == 1)
    {
        resetBoard();

        while (!isGameOver())
        {
            playGame();
            if (isGameOver())
            {
                break;
            }
        }
        GameOver();
        cout << "Would you like to play again?" << endl;
        cout << "\t1.Yes\n\t2.No" << endl;
        cin >> choice;
        if (choice == 1)
        {
            menu();
            cin >> choice;
        }
        else
            break;
    }
    cout << "Thank you for using this application!!" << endl;

    return 0;
}
