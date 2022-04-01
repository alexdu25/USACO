#include <bits/stdc++.h>
using namespace std;
int n,m,psum[201][201],ans;
char mat[201][201];
int area(int width,int topleftx,int bottomleftx){
    int length=bottomleftx-topleftx+1;
    return width*length;
}
void sweep(int startx,int endx){
    int width=0;
    for(int i=0;i<m;i++){//endy coordinate
        if(mat[startx][i]=='X'||mat[endx][i]=='X'){
            width=0;
        }
        else if(width==0&&(psum[startx+1][i]-psum[endx][i]!=0)){
            width=0;
        }
        else{
            width++;
            if(psum[startx+1][i]-psum[endx][i]==0){
                int x=area(width,startx,endx);
                ans=max(ans,x);
            }
        }

    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=n-1;j>=0;j--){
            if(mat[j][i]=='X') psum[j][i]=1;
            psum[j][i]+=psum[j+1][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sweep(i,j);
        }
    }
    cout << ans;
}
/*
Problem Statement:
Fort Moo
========

Bessie is building a fort with her friend Elsie. Like any good
fort, this one needs to start with a sturdy frame. Bessie wants to
build a frame in the shape of a one-meter-wide rectangular outline,
atop which she will build the fort.

Bessie has already chosen a site on which to build the fort -- a
piece of land measuring N meters by M meters (1 <= N,M <= 200).
Unfortunately, the site has some swampy areas that cannot be used
to support the frame. Please help Bessie determine the largest area
she can cover with her fort (the area of the rectangle supported by
the frame), such that the frame avoids sitting on any of the swampy
areas.

INPUT FORMAT:

Line 1 contains integers N and M.

The next N lines each contain M characters, forming a grid
describing the site. A character of '.' represents normal grass,
while 'X' represents a swampy spot.

OUTPUT FORMAT:

A single integer representing the maximum area that Bessie can
cover with her fort.

SAMPLE INPUT:

5 6
......
..X..X
X..X..
......
..X...

SAMPLE OUTPUT:

16

In the example, the placement of the optimal frame is indicated by
'f's below:

.ffff.
.fX.fX
Xf.Xf.
.ffff.
..X...
*/
