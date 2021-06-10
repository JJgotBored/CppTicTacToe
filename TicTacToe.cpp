#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void printBoard(char board[3][3]);
int mainMenu();
void onePlayerMenu();
void easyGame();
void twoPlayerGame();
int getNextMove(char board[3][3]);
char checkWin(char board[3][3]);
int getEasyMove(char board[3][3]);

//main
int main(){

    
    int select = 0;

    

    while(select != 3){
        select = mainMenu();
        if(select == 1)
            onePlayerMenu();
        else if(select == 2)
            twoPlayerGame();
        else    
            cout << "Goodbye" << endl;
    }


    //cout << "hello world" << endl;

    return 0;
}

//prints tic tac toe board 
void printBoard(char board[3][3]){
    
    cout << setw(2) << board[0][0] << setw(2) << "|" << setw(2) << board[0][1] << setw(2) << "|" << setw(2) << board[0][2] << endl;
    cout << setw(2) << "-" << setw(2) << "+" << setw(2) << "-" << setw(2) << "+" << setw(2) << "-" << endl;
    cout << setw(2) << board[1][0] << setw(2) << "|" << setw(2) << board[1][1] << setw(2) << "|" << setw(2) << board[1][2] << endl;
    cout << setw(2) << "-" << setw(2) << "+" << setw(2) << "-" << setw(2) << "+" << setw(2) << "-" << endl;
    cout << setw(2) << board[2][0] << setw(2) << "|" << setw(2) << board[2][1] << setw(2) << "|" << setw(2) << board[2][2] << endl; 
    
    return;
}

// main menu function
int mainMenu(){
    int input = 0;

    cout << "------------------------------" << endl;
    cout << " *  Welcome to Tic Tac Toe  * " << endl;
    cout << "------------------------------" << endl;
    cout << " Please select game type:" << endl;
    cout << " 1. One player game" << endl;
    cout << " 2. Two player game" << endl;
    cout << " 3. Exit" << endl;

    cin >> input;

    while (input < 1 || input > 3){
        cout << "Invalid Input" << endl;
        cin >> input;
    }
    return input;
}

// menu for one player game
void onePlayerMenu(){
    int input = 0;

    cout << "------------------------------" << endl;
    cout << " *      One Player Game     * " << endl;
    cout << "------------------------------" << endl;
    cout << " Please game difficulty:" << endl;
    cout << " 1. Easy" << endl;
    cout << " 2. Medium" << endl;
    cout << " 3. Impossible" << endl;
    cout << " 4. Exit" << endl;

    cin >> input;

    while (input < 1 || input > 4){
        cout << "Invalid Input" << endl;
        cin >> input;
    }

    if(input == 1)
        easyGame();
    else if(input == 2)
        cout << "Medium" << endl;
    else if(input == 3)
        cout << "Impossible" << endl;
    else    
        cout << "Exiting to main menu" << endl;

    return;
}

// two player game
void twoPlayerGame(){

    char board[3][3];
    int move = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }

    printBoard(board);
    for(int i = 0; i < 9; i++){
        char win = ' ';

        //get move
        move = getNextMove(board) -1;

        if(i%2 == 0)
            board[move/3][move%3] = 'X';
        else
            board[move/3][move%3] = 'O';

        //check for game end
        win = checkWin(board);
        if(win != ' '){
            cout << win << " has won the game." << endl;
            return;
        }
        printBoard(board);
    }

    return;
}

// gets next user move
int getNextMove(char board[3][3]){
    bool valid = false;
    int input = 0;

    while(valid == false){ 
        cout << "Please make selection:" << endl;
        cout << "1. Top Left,       2. Top Centre,      3. Top Right" << endl;
        cout << "4. Centre Left,    5. Centre Centre,   6. Centre Right" << endl;
        cout << "7. Bottom Left,    8. Bottom Centre,   9. Bottom Right" << endl;

        cin >> input;

        if(input < 1 || input > 9)
            cout << "Invalid Input" << endl;
        else if (board[(input -1)/3][(input-1)%3] != ' ')
            cout << "Space Already Occupied" << endl;
        else
            valid = true;
        
    }
    return input;
}

/*checks for victory
    returns X if player 1 wins
    returns Y if player 2 wins
    returns ' ' if no victory
*/
char checkWin(char board[3][3]){
    char out = ' ';

    //check rows
    for(int i = 0; i < 3; i++){
        if (out != ' ')
            return out;
        else if( (board[i][0] == board[i][1]) && (board[i][0] == board[i][2]) && ((board[i][0] == 'X') || (board[i][0] == 'O')))
            out = board[i][0];
    }
    //check collums
    for(int i = 0; i < 3; i++){
        if (out != ' ')
            return out;
        else if( (board[0][i] == board[1][i]) && (board[0][i] == board[2][i]) && ((board[0][i] == 'X') || (board[0][1] == 'O')))
            out = board[0][i];
    }
    //check left to right diagonal 
    if (out != ' ')
            return out;
    else if( (board[0][0] == board[1][1]) && (board[0][0] == board[2][2]) && ((board[0][0] == 'X') || (board[0][0] == 'O')))
            out = board[0][0];
    //check right to left diagonal
    if (out != ' ')
            return out;
    else if( (board[0][2] == board[1][1]) && (board[0][2] == board[2][0]) && ((board[0][2] == 'X') || (board[0][2] == 'O')))
            out = board[0][2];

    return out;
}

int getEasyMove(char board[3][3], int turn){
    int move = 0;
    bool valid = false;
    move = rand() % (9 - turn);

    while (valid == false){
        move = move % (9 - turn);

        if(board[move/3][move % 3] != ' ')
            move++;
        else
            valid = true;
         
    }

    return move;
}

void easyGame(){
    char board[3][3];
    int move = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }

    printBoard(board);
    for(int i = 0; i < 9; i++){
        char win = ' ';

        //get move
        if(i%2 == 0){
            move = getNextMove(board) -1;
            board[move/3][move%3] = 'X';
        }
        else{
            move = getEasyMove(board, i);
            board[move/3][move%3] = 'O';
            cout << "Computer has taken its turn." << endl;
        }
        //check for game end
        win = checkWin(board);
        if(win != ' '){
            cout << win << " has won the game." << endl;
            printBoard(board);
            return;
        }
        printBoard(board);
    }

    return;
}