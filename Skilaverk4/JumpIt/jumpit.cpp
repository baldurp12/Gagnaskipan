#include <iostream>
#include "jumpit.h"
using namespace std;

const int PENALTY = 1000;	// Used to assign a very high cost
int cost = 0;

int jumpIt(const int board[], int startIndex, int endIndex)
{
    int sentInt = cost;
    cost = 0;
    if (startIndex >= endIndex || min(startIndex + 1 == endIndex, startIndex +2 == endIndex))
        return sentInt + board[endIndex];
    else
    {
        return min(board[startIndex] + jumpIt(board, startIndex + 1, endIndex), board[startIndex] + jumpIt(board, startIndex + 2, endIndex));
    }
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
