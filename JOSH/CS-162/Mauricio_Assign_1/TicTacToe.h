#include <iostream>

using namespace std;

class TicTacToe {
private:
    char currentPlayer;
    char board[3][3];
public:
    void print();
    char getCurrentPlayer();
    bool isDone();
    char getWinner();
    bool isValidMove(int row, int col);
    void makeMove(int row, int col);
};

    void TicTacToe::print(){

    }
