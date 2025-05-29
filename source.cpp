#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include<string>
#include<fstream>
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
const string fileName = "movesplayed.txt";
void goal(int board[5][5]) {
    int temp = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = temp + 1;
            temp++;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "+----";
        }
        cout << "+" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "| " << setw(2);
            if (board[i][j] == 25) {
                board[i][j] = 0;
                if (board[i][j] == 0)
                {
                    cout << " ";
                }
            }
            else {
                cout << board[i][j];
            }
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int j = 0; j < 5; j++) {
        cout << "+----";
    }
    cout << "+" << endl;
}

void init(int board[5][5]) {
    srand(time(0));
    bool used[26] = { false };
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) {
            int random;
            do {
                random = rand() % 25;
            } while (used[random]);
            board[i][j] = random;
            used[random] = true;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "+----";
        }
        cout << "+" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "| " << setw(2);
            if (board[i][j] == 0) {
                cout << " ";
            }
            else {
                cout << board[i][j];
            }
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int j = 0; j < 5; j++) {
        cout << "+----";
    }
    cout << "+" << endl;
}

int countInversions(int board[5][5]) {
    int inversions = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {

            if (board[i][j] == 0)
                continue;

            int num1 = board[i][j];

            for (int k = i; k < 5; ++k) {
                int start;
                if (k == i)
                    start = j + 1;
                else
                    start = 0;
                for (int l = start; l < 5; ++l) {
                    if (board[k][l] != 0) {

                        int num2 = board[k][l];

                        if (num1 > num2) {
                            inversions++;
                        }
                    }
                }
            }
        }
    }
    return inversions;
}


bool Is_Solveable(int board[5][5]) {
    int inversions = countInversions(board);

    return inversions % 2 == 0;
}
bool isValidMove(int row, int col) {

    return (row >= 0 && row < 5 && col >= 0 && col < 5);
}


char* legal_moves(int init_state[5][5]) {

    int emptyRow = {}, emptyCol = {};
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (init_state[i][j] == 0) {
                emptyRow = i;
                emptyCol = j;
                break;
            }
        }
    }


    char* moves = new char[5];
    int moveCount = 0;


    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };
    char directions[] = { 'u', 'd', 'l', 'r' };


    for (int i = 0; i < 4; ++i) {
        int newRow = emptyRow + dr[i];
        int newCol = emptyCol + dc[i];

        if (isValidMove(newRow, newCol)) {

            moves[moveCount++] = directions[i];
        }
    }
    moves[moveCount] = '\0';
    return moves;
}
void saveMoves(int movesplayed) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << movesplayed;
        outFile.close();
    }
    else {
        cout << "Unable to save moves to file." << endl;
    }
}
void make_move(int board[5][5], char move) {
    int emptyrow = {}, emptycolumn = {};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == 0)
            {
                emptyrow = i;
                emptycolumn = j;
                break;
            }
        }
    }
    int emptyIndex;
    int newRow = emptyrow, newCol = emptycolumn;
    switch (move) {
    case 'u':
        newRow = emptyrow - 1;
        break;
    case 'd':
        newRow = emptyrow + 1;
        break;
    case 'l':
        newCol = emptycolumn - 1;
        break;
    case 'r':
        newCol = emptycolumn + 1;
        break;
    default:
        cout << "Invalid move." << endl;
        return;
    }
    if (isValidMove(newRow, newCol)) {
        static int movesplayed = 0;
        int temp = board[emptyrow][emptycolumn];
        board[emptyrow][emptycolumn] = board[newRow][newCol];
        board[newRow][newCol] = temp;
        movesplayed++;
        cout << "No. Of Moves: " << movesplayed;
        cout << endl;
        saveMoves(movesplayed);
    }
    else {
        cout << "Invalid move." << endl;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "+----";
        }
        cout << "+" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "| " << setw(2);
            if (board[i][j] == 0) {
                cout << " ";
            }
            else {
                cout << board[i][j];
            }
            cout << " ";
        }
        cout << "|" << endl;
    }
    for (int j = 0; j < 5; j++) {
        cout << "+----";
    }
    cout << "+" << endl;

}
void printmenu() {
    SetConsoleTextAttribute(h, 15);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t*****************************************" << endl;
    cout << "\t\t\t\t\t\t*            24-Puzzle Game             *" << endl;
    cout << "\t\t\t\t\t\t*****************************************" << endl;
    cout << "\t\t\t\t\t\t1. Play Game" << endl;
    cout << "\t\t\t\t\t\t2. Moves" << endl;
    cout << "\t\t\t\t\t\t3. Credits" << endl;
    cout << "\t\t\t\t\t\t4. Quit Game" << endl;
    cout << "\t\t\t\t\t\t*****************************************" << endl;
    cout << "\t\t\t\t\t\t Enter Your Choice: ";
}
void credits() {
    system("cls");
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\t\t---------------------------------" << endl;
    SetConsoleTextAttribute(h, 1);
    cout << "\t\t\t\t\t\t\t\t\t24-Puzzle Game Credits         " << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\t\t---------------------------------" << endl;
    SetConsoleTextAttribute(h, 2);
    cout << "\t\t\t\t\t\t\t\t   Developed and Designed by:            " << endl;
    cout << "\t\t\t\t\t\t\t\t   Arslan Aftab	 23F-0639      " << endl;
    SetConsoleTextAttribute(h, 3);
    cout << "\t\t\t\t\t\t\t\t   Nauman Khalid 23F-0853         " << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\t\t---------------------------------" << endl;
    SetConsoleTextAttribute(h, 4);
    cout << "\t\t\t\t\t\t\t\t        Special Thanks to:       " << endl;
    cout << "\t\t\t\t\t\t\t\t   Sir. Hanan Farooq" << endl;
    SetConsoleTextAttribute(h, 5);
    cout << "\t\t\t\t\t\t\t\t   Miss. Areeba Waseem" << endl;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\t\t\t\t\t---------------------------------" << endl;
}
int loadMoves() {
    int movesplayed = 0;
    ifstream inFile(fileName);
    if (inFile.is_open()) {
        inFile >> movesplayed;
        inFile.close();
    }
    else {
        cout << "Unable to load moves from file." << endl;
    }
    return movesplayed;
}
int main()
{
    bool exit = true;
    while (exit != false) {
        int choice;
        printmenu();
        cin >> choice;
        system("cls");
        if (choice == 1) {
            SetConsoleTextAttribute(h, 15);
            char move;
            int array1[5][5];
            int array2[5][5];
            cout << "The goal is: " << endl;
            goal(array1);
            cout << endl;
            init(array2);
            cout << endl;
            countInversions(array2);
            Is_Solveable(array2);
            if (Is_Solveable(array2))
            {
                cout << "It is Solveable.";
                while (array1 != array2) {
                    legal_moves(array2);
                    cout << endl;
                    cout << legal_moves(array2);
                    cout << endl;
                    cout << "Enter Your Move. Above shows the Legal Moves.\nPress 'u' for Moving up.\nPress 'd' for Moving Down.\nPress 'l' for Moving Left.\nPress 'r' for Moving Right.\n";
                    cin >> move;
                    make_move(array2, move);

                }

            }
            else
            {
                cout << "Not Solveable." << endl;
                cout << "Press any Key to Continue";
                int key = _getch();
                system("cls");

            }
            if (array1 == array2)
            {
                cout << endl << "Congratulations You Won The Game" << endl;
            }

        }
        else if (choice == 2)
        {
            int movesplayed = loadMoves();
            cout << "Number of moves last played: " << movesplayed << endl;
            cout << "Press any key to return to the main menu...";
            int key = _getch();
            system("cls");
        }
        else if (choice == 3)
        {
            credits();
            cout << "Press any key to return to the main menu...";
            int key = _getch();
            system("cls");
        }
        else if (choice == 4)
        {
            exit = false;
        }
    }

    system("pause");
    return 0;
}
