#include <bits/stdc++.h>
using namespace std;
int n,dist,input[401][401],prepsum[401][402],psum[401][401],ans;
int convert(int x1){
    if(x1<0) return 0;
    if(x1>n) return n;
    return x1;
}
void precalc(){
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x=i; y=j-dist;//west one
            prepsum[x][convert(y)]+=input[i][j];
            if(dist!=0){
                for(int k=1;;k++){
                    int newx=x+k,newy=y+k;
                    if(newx>=0&&newx<n) prepsum[newx][convert(newy)]+=input[i][j];
                    newx=x-k,newy=y+k;
                    if(newx>=0&&newx<n) prepsum[newx][convert(newy)]+=input[i][j];
                    if(newy==j) break;
                }
                x=i; y=j+dist;//east one
                prepsum[x][convert(y+1)]-=input[i][j];
                for(int k=1;;k++){
                    int newx=x-k,newy=y-k;
                    if(newx>=0&&newx<n) prepsum[newx][convert(newy+1)]-=input[i][j];
                    newx=x+k,newy=y-k;
                    if(newx>=0&&newx<n) prepsum[newx][convert(newy+1)]-=input[i][j];
                    if(newy==j) break;
                }
            }
            else prepsum[x][convert(y)+1]-=input[i][j];
        }
    }
}
void calc(){
    for(int i=0;i<n;i++){
        psum[i][0]=prepsum[i][0];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            psum[i][j]=prepsum[i][j]+psum[i][j-1];
        }
    }
}
int main(){
    cin >> n >> dist;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> input[i][j];
        }
    }
    precalc();
    calc();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans=max(ans,psum[i][j]);
        }
    }
    cout << ans;
}
/*
Problem Statement:
The Lazy Cow
============

It's a hot summer day, and Bessie the cow is feeling quite lazy. She wants
to locate herself at a position in her field so that she can reach as much
delicious grass as possible within only a short distance.

The field Bessie inhabits is described by an N by N grid of square cells
(1 <= N <= 400). The cell in row r and column c (1 <= r,c <= N) contains
G(r,c) units of grass (0 <= G(r,c) <= 1000). From her initial square in
the grid, Bessie is only willing to take up to K steps (0 <= K <= 2*N).
Each step she takes moves her to a cell that is directly north, south,
east, or west of her current location.

For example, suppose the grid is as follows, where (B) describes Bessie's
initial position (here, in row 3, column 3):

50    5     25*   6     17
14    3*    2*    7*    21
99*   10*   1*(B) 2*    80*
8     7*    5*    23*   11
10    0     78*   1     9

If K=2, then Bessie can only reach the locations marked with *s.

Please help Bessie determine the maximum amount of grass she can reach, if
she chooses the best possible initial location in the grid.

PROBLEM NAME: lazy

INPUT FORMAT:

* Line 1: The integers N and K.

* Lines 2..1+N: Line r+1 contains N integers describing row r of the
        grid.

SAMPLE INPUT:

5 2
50 5 25 6 17
14 3 2 7 21
99 10 1 2 80
8 7 5 23 11
10 0 78 1 9

OUTPUT FORMAT:

* Line 1: The maximum amount of grass Bessie can reach, if she chooses
        the best possible initial location (the location from which
        she can reach the most grass).

SAMPLE OUTPUT:

342

OUTPUT DETAILS:

In the example above, Bessie can reach 342 total units of grass if she
locates herself in the middle of the grid.
*/
