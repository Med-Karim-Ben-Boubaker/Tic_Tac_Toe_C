#ifndef DECLARATION_H_
#define DECLARATION_H_
//Global Functions
    void resetBoard();
    void showBoard();
    int checkFreeSpaces();
    int playerMove(char player);
    int computerMove();
    int checkWinner(char* winner);
    void printWInner(char winner);
    void showMenue(int* playMode);
    void playModePlyaerVsPlayer(char* winner, int* success, int* winState);
    void playModePlyaerVsComputer(char* winner, int* success, int* winState);

    #endif