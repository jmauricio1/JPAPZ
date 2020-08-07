//Joshua Jacob Mauricio and Nick Harvey
//Assignment 8 / Lab 8
#include <iostream>
#include <string>

using namespace std;
const int ROW = 10;
const int COL = 10;

string upperCase(string word){
    for(int i = 0; i < word.length(); i++)
        word.at(i) = toupper(word.at(i));
    return word;
}
char randomLetter(){
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char letter = alpha.at(rand() % 26);
    return letter;
}
void menu(){
    cout << "MENU OPTIONS:" << endl
         << "1. Print key" << endl
         << "2. Print puzzle" << endl
         << "3. Add horizontal word" << endl
         << "4. Add vertical word" << endl
         << "5. Check word fit" << endl
         << "6. Space count" << endl
         << "8. QUIT" << endl;
}

//Menu option 1
void printKey(char puzzle[ROW][COL]){
    for(int k = 0; k < ROW; k++){
        for(int j = 0; j < COL; j++)
            cout << puzzle[k][j] << " ";
        cout << "" << endl;
    }
}

//Menu option 2
void printPuzzle(char puzzle[ROW][COL]){
    for(int k = 0; k < ROW; k++){
        for(int j = 0; j < COL; j++){
            if(puzzle[k][j] == '_')
                cout << randomLetter() << " ";
            else
                cout << puzzle[k][j] << " ";
        }
        cout << "" << endl;
    }
}

//Menu option 5
void checkFit(){
    int startRow = 0;
    int startCol;

    cout <<  "Enter row number: ";
    cin >> startRow;
    cout << "Enter column number: ";
    cin >> startCol;
    string word;
    cout << "Enter word: ";
    cin >> word;

    if((startRow > (11 - word.length())) || (startCol > (11 - word.length())))
        cout << "Word does not fit." << endl;
    else if (word.length() > 10)
        cout << "Word does not fit." << endl;
    else
        cout << "Fits" << endl;
}

//Menu option 3
void addHWORD(char puzzle[ROW][COL]){
    int startRow = 0;
    int startCol = 0;

    cout << "Enter row number: ";
    cin >> startRow;
    cout << "Enter column number: ";
    cin >> startCol;

    cout << "Enter word: ";
    string word;
    cin >> word;
    cout << "" << endl;
    word = upperCase(word);

    if(word.length() <= 10){
        startRow -= 1;
        startCol -= 1;
        int j = 0;
        for(int i = 0; i < word.length(); i++){
            puzzle[startRow][i + startCol] = word.at(j);
            j++;
        }
    }
}

//Menu option 4
void addVWORD(char puzzle[ROW][COL]){
    int startRow = 0;
    int startCol = 0;

    cout << "Enter row number: ";
    cin >> startRow;
    cout << "Enter column number: ";
    cin >> startCol;

    cout << "Enter word: ";
    string word;
    cin >> word;
    word = upperCase(word);
    if(word.length() <= 10){
        startRow -= 1;
        startCol -= 1;
        int j = 0;
        for(int i = 0; i < word.length(); i++){
            puzzle[i + startRow][startCol] = word.at(j);
            j++;
        }
    }
}

//Menu option 6
void countSpace(char puzzle[ROW][COL]){
    int count = 0;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if (puzzle[i][j] == '_')
                count++;
        }
    }
    cout << "There are " << count << " blank spaces in your puzzle." << endl;
}
int main()
{  
    menu();
    char crossword[ROW][COL];
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++)
            crossword[i][j] = '_';
    }
    int input = 0;
    cout << "Enter Menu number: ";
    cin >> input;
    while (input != 8){
        if (input == 1)
            printKey(crossword);
        if (input == 2)
            printPuzzle(crossword);
        else if (input == 3)
            addHWORD(crossword);
        else if(input == 4)
            addVWORD(crossword);
        else if (input == 5){
            checkFit();
        }
        else if(input == 6)
            countSpace(crossword);
        else if ((input < 0) || (input > 8))
            cout << "Please enter a valid menu number." << endl;
        cout << "Enter Menu number: ";
        cin >> input;
    }
    cout << "Exit program." << endl;
}
