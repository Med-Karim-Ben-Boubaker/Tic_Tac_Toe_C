#include "declaration.h"

int main(){
    char winner = ' ';
    int success = 1;
    int winState = 0;
    int playMode;
    showMenue(&playMode);

    if(playMode == 1) playModePlyaerVsPlayer(&winner, &success, &winState);
    else playModePlyaerVsComputer(&winner, &success, &winState);

    if(winState == 0) checkWinner(&winner);
    showBoard();
    printWInner(winner);
    return 0;
}

