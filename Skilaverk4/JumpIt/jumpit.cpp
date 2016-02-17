#include <iostream>
#include "jumpit.h"
using namespace std;

const int PENALTY = 1000;	// Used to assign a very high cost
int cost = 0;

int jumpIt(const int board[], int startIndex, int endIndex){
    if(startIndex >= endIndex || startIndex +1 == endIndex || startIndex +2 == endIndex){
        int sendInt = cost;
        cost = 0;
        return sendInt + board[endIndex];
    }

    else{
        if(board[startIndex + 1] > board[startIndex + 2]){
            cost += board[startIndex + 2];
            return jumpIt(board, startIndex +2, endIndex);
        }
        else{
            cost += board[startIndex + 1];
            return jumpIt(board, startIndex +1, endIndex);
        }
    }

};
