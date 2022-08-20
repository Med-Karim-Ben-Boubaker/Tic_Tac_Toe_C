//Global Variables
    char board[3][3];
    char const PLAYER1;
    char const PLAYER2;
    char const COMPUTER;
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

//Main Variables
    char winner;
    int success;
    int winState;
    int playMode;