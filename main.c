#include <stdio.h> 
#include <stdlib.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

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
int playerMove(){
    if (checkFreeSpaces() == 0) return 0;
    int choice;
    printf("Enter the position of your X, from 1 -> 9\n");
    while(1){
        scanf("%d", &choice);
        if(board[(choice-1)/3][(choice-1)%3] == ' '){
            board[(choice-1)/3][(choice-1)%3] = 'X';
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
            printf("Debug in checkWinner: row %d is active", i);
            *winner = board[i][0];
            return 1;
        } 
    }
    //check for diagonals
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')||( board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')){
         *winner = board[1][1];
         return 1;
    }
    return 0;
}

void printWInner(char winner){
    printf("The winner is : %c\n", winner);
}

void startGame(){
  /*  char winner = ' ';
    int success;
    resetBoard();
    while(success){
        showBoard();
        success = playerMove();
        showBoard();
        success = computerMove();
    }
    winner = checkWinner();
    printWInner(winner); */
    return;
}

int main(){
    char winner = ' ';
    int success = 1;
    int win = 0;
    resetBoard();
    while(success && !win){
        showBoard();
        success = playerMove();
        success = computerMove();
        win = checkWinner(&winner);
        printf("Debug---Winner = %c ---Win = %d --- \n", winner, win);
    }
    if(win == 0) checkWinner(&winner);
    printWInner(winner);
    return 0;
}

