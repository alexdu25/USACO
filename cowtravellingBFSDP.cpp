#include <bits/stdc++.h>
using namespace std;
int n,m,t,startx,endx,starty,endy,dp[101][101][16],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
char matrix[101][101];
bool bound(int x1,int y1){
    if(x1<1||y1<1||x1>n||y1>m) return false;
    if(matrix[x1][y1]=='*') return false;
    return true;
}
int main(){
    cin >> n >> m >> t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> matrix[i][j];
        }
    }
    cin >> startx >> starty >> endx >> endy;
    dp[startx][starty][0]=1;
    for(int k=0;k<t;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(dp[i][j][k]!=0){
                    for(int l=0;l<4;l++){
                        int newx=i+dx[l],newy=j+dy[l];
                        if(bound(newx,newy)==true){
                            dp[newx][newy][k+1]+=dp[i][j][k];
                        }
                    }
                }
            }
        }
    }
    cout << dp[endx][endy][t];
}
/*
Problem Statement:
Cow Travelling
==============

Searching for the very best grass, the cows are travelling about
the pasture which is represented as a grid with N rows and M columns
(2 <= N <= 100; 2 <= M <= 100). Keen observer Farmer John has
recorded Bessie's position as (R1, C1) at a certain time and then
as (R2, C2) exactly T (0 < T <= 15) seconds later. He's not sure
if she passed through (R2, C2) before T seconds, but he knows she
is there at time T.

FJ wants a program that uses this information to calculate an integer
S that is the number of ways a cow can go from (R1, C1) to (R2, C2)
exactly in T seconds. Every second, a cow can travel from any
position to a vertically or horizontally neighboring position in
the pasture each second (no resting for the cows). Of course, the
pasture has trees through which no cow can travel.

Given a map with '.'s for open pasture space and '*' for trees,
calculate the number of possible ways to travel from (R1, C1) to
(R2, C2) in T seconds.

PROBLEM NAME: ctravel

INPUT FORMAT:

* Line 1: Three space-separated integers: N, M, and T

* Lines 2..N+1: Line i+1 describes row i of the pasture with exactly M
        characters that are each '.' or '*'

* Line N+2: Four space-separated integers: R1, C1, R2, and C2.

SAMPLE INPUT (file ctravel.in):

4 5 6
...*.
...*.
.....
.....
1 3 1 5

INPUT DETAILS:

The pasture is 4 rows by 5 colum. The cow travels from row 1, column
3 to row 1, column 5, which takes exactly 6 seconds.

OUTPUT FORMAT:

* Line 1: A single line with the integer S described above.

SAMPLE OUTPUT (file ctravel.out):

1

OUTPUT DETAILS:

There is only one way from (1,3) to (1,5) in exactly 6 seconds (and
it is the obvious one that travels around the two trees).
*/
