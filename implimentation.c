#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include "declaration.h"

char const PLAYER1 = 'X';
char const PLAYER2 = 'O';
char const COMPUTER = 'O';

void resetBoard(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j] = ' ';
        }
    }
}
void showBoard(){
    for(int i=0; i<3; i++){
        printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        printf("---|---|---\n");
    }
}
int checkFreeSpaces(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == ' ') return 1;
        }
    }
    return 0;
}
int playerMove(char player){
    if (checkFreeSpaces() == 0) return 0;
    int choice;
    printf("Enter the position of your %c, from 1 -> 9:\n", player);
    while(1){
        scanf("%d", &choice);
        if(board[(choice-1)/3][(choice-1)%3] == ' '){
            board[(choice-1)/3][(choice-1)%3] = player;
            return 1;
        }
        else printf("Invalide Input, please change your input\n");
    }
}

int computerMove(){
    if (checkFreeSpaces() == 0) return 0;
    while(1){
        int choice = rand()%9 +1;
        if(board[(choice-1)/3][(choice-1)%3] == ' '){
            board[(choice-1)/3][(choice-1)%3] = 'O';
            return 1;
        }
    }
}

int checkWinner(char* winner){
    //check for columns and rows
    for(int i=0; i<3; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '){
            *winner = board[0][i];
            return 1;
        }
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
            *winner = board[i][0];
            return 1;
        } 
    }
    //check for diagonals
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')||( board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')){
         *winner = board[1][1];
         return 1;
    }
    return 0; //Otherwise, if no winner has been determined, return 0.
}

void printWInner(char winner){
    if (winner == ' ') printf("The winner is : DRAW\n"); 
    else printf("The winner is : %c\n", winner);
}

void showMenue(int* playMode){
    printf("---- Game Menue ----\n");
    printf("Please choose your play mode:\n  1-Plyer1 vs. Player2\n   2-Player1 vs. Computer\n");
    scanf("%d", playMode);
}

void playModePlyaerVsPlayer(char* winner, int* success, int* winState){
    resetBoard();
    while(*success && !(*winState)){
        showBoard();
        *success = playerMove('X');
        *winState = checkWinner(winner);
        if(*winState == 1) break;
        showBoard();
        *success = playerMove('O');
        *winState = checkWinner(winner);
    }
}

void playModePlyaerVsComputer(char* winner, int* success, int* winState){
    resetBoard();
    while(*success && !(*winState)){
        showBoard();
        *success = playerMove('X');
        *success = computerMove();
        *winState = checkWinner(winner);
    }
}