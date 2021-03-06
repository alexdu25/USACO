#include <bits/stdc++.h>
using namespace std;
int n,input[100],dp[100][100],totalsum;
int recurse(int leftindex,int rightindex){
    if(leftindex==rightindex) return input[leftindex];
    if(leftindex==rightindex-1) return max(input[leftindex],input[rightindex]);
    if(dp[leftindex][rightindex]!=0) return dp[leftindex][rightindex];
    return dp[leftindex][rightindex]= max(min(recurse(leftindex+2,rightindex),recurse(leftindex+1,rightindex-1))+input[leftindex],min(recurse(leftindex,rightindex-2),recurse(leftindex+1,rightindex-1))+input[rightindex]);
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> input[i];
        totalsum+=input[i];
    }
    int x=recurse(0,n-1);
    cout << x << " " << totalsum-x << endl;
}
/*
Problem Statement:
A Game
======

Consider the following two-player game played with a sequence of
N positive integers (2 <= N <= 100) laid onto a game board.
Player 1 starts the game. The players move alternately by
selecting a number from either the left or the right end of the
sequence. That number is then deleted from the board, and its
value is added to the score of the player who selected it. A
player wins if his sum is greater than his opponents.

Write a program that implements the optimal strategy. The
optimal strategy yields maximum points when playing against the
"best possible" opponent. Your program must further implement
an optimal strategy for player 2.

PROGRAM NAME: game1

INPUT FORMAT:

* Line 1: N, the size of the board

* Line 2-etc: N integers in the range (1..200) that are the
  contents of the game board, from left to right

SAMPLE INPUT:

6
4 7 2 9
5 2

OUTPUT FORMAT:

Two space-separated integers on a line: the score of Player 1
followed by the score of Player 2.

SAMPLE OUTPUT:

18 11
*/
