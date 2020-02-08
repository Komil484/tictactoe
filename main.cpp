#include <iostream>

using namespace std;

    int whoWon(char posNum){
        int result = 0;
        if(posNum == 'X'){
                result = 1;
            } else if(posNum == 'O'){
                result = -1;
            }
        return result;
    }

    int isGameOver(char pos[]){
        int result = 0;
        if(pos[0] == pos[1] and pos[1] == pos[2]){
            result = whoWon(pos[1]);
        } else if(pos[3] == pos[4] and pos[4] == pos[5]){
            result = whoWon(pos[4]);
        } else if(pos[6] == pos[7] and pos[7] == pos[8]){
            result = whoWon(pos[7]);
        } else if(pos[0] == pos[3] and pos[3] == pos[6]){
            result = whoWon(pos[3]);
        } else if(pos[1] == pos[4] and pos[4] == pos[7]){
            result = whoWon(pos[4]);
        } else if(pos[2] == pos[5] and pos[5] == pos[8]){
            result = whoWon(pos[5]);
        } else if(pos[0] == pos[4] and pos[4] == pos[8]){
            result = whoWon(pos[4]);
        } else if(pos[2] == pos[4] and pos[4] == pos[6]){
            result = whoWon(pos[4]);
        }

        return result;
    }

char playerMover(char pos[]){
    int playerMove, result;
    cin >> playerMove;
    if(pos[(playerMove - 1)] == ' '){
        if(playerMove < 10 and playerMove > 0){
            result = playerMove - 1;
        } else {
            cout << "Invalid Input, please choose again" << endl;
            playerMover(pos);
        }
    } else {
        cout << "Please choose another spot" << endl;
        playerMover(pos);
    }
    return result;
}

int main()
{
    char pos[9];
    for(int i = 0; i < 9; i++){
        pos[i] = ' ';
    }


    cout << " " << pos[0] <<" | " << pos[1] << " | " << pos[2] << " " << endl;
    cout << "___|___|___" << endl;
    cout << " " << pos[3] <<" | " << pos[4] << " | " << pos[5] << " " << endl;
    cout << "___|___|___" << endl;
    cout << " " << pos[6] <<" | " << pos[7] << " | " << pos[8] << " " << endl;
    cout << "   |   |   " << endl;

    for(int i = 0; i < 9 and isGameOver(pos) == 0; i++){

        cout << "Choose your move 1-9" << endl;
        if(i % 2 == 0){
            pos[playerMover(pos)] = 'X';
        } else if(i % 2 == 1){
            pos[playerMover(pos)] = 'O';
        }

        for(int i = 0; i < 100; i++){
            cout << endl;
        }

        cout << " " << pos[0] <<" | " << pos[1] << " | " << pos[2] << " " << endl;
        cout << "___|___|___" << endl;
        cout << " " << pos[3] <<" | " << pos[4] << " | " << pos[5] << " " << endl;
        cout << "___|___|___" << endl;
        cout << " " << pos[6] <<" | " << pos[7] << " | " << pos[8] << " " << endl;
        cout << "   |   |   " << endl;

    }

    switch(isGameOver(pos)){
    case -1:
        cout << endl;
        cout << "O wins" << endl;
        break;
    case 0:
        cout << endl;
        cout << "Draw" << endl;
        break;
    case 1:
        cout << endl;
        cout << "X wins" << endl;
        break;
    }

    return 0;
}
/*
 X | X | X
___|___|___
 X | X | X
___|___|___
 X | X | X
   |   |
*/
