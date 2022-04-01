#include <iostream>
#include <queue>
using namespace std;
int r,c,m[1001][1001],ans=1000000000;
bool visited[1001][1001],visited2[1001][1001];
queue<int> x,y,counter,x1,y1,counter1;
void bfs(void){
    while(!x1.empty()){
        if(x1.front()+1>=0&&x1.front()+1<r&&y1.front()>=0&&y1.front()<c&&m[x1.front()+1][y1.front()]!=1){
            if(visited2[x1.front()+1][y1.front()]==false){
                visited2[x1.front()+1][y1.front()]=true;
                if(m[x1.front()+1][y1.front()]==3){
                    ans=min(ans,counter1.front()+1);
                    break;
                }
                x1.push(x1.front()+1);
                y1.push(y1.front());
                counter1.push(counter1.front()+1);
            }
        }
        if(x1.front()-1>=0&&x1.front()-1<r&&y1.front()>=0&&y1.front()<c&&m[x1.front()-1][y1.front()]!=1){
            if(visited2[x1.front()-1][y1.front()]==false){
                visited2[x1.front()-1][y1.front()]=true;
                if(m[x1.front()-1][y1.front()]==3){
                    ans=min(ans,counter1.front()+1);
                    break;
                }
                x1.push(x1.front()-1);
                y1.push(y1.front());
                counter1.push(counter1.front()+1);
            }
        }
        if(x1.front()>=0&&x1.front()<r&&y1.front()+1>=0&&y1.front()+1<c&&m[x1.front()][y1.front()+1]!=1){
            if(visited2[x1.front()][y1.front()+1]==false){
                visited2[x1.front()][y1.front()+1]=true;
                if(m[x1.front()][y1.front()+1]==3){
                    ans=min(ans,counter1.front()+1);
                    break;
                }
                x1.push(x1.front());
                y1.push(y1.front()+1);
                counter1.push(counter1.front()+1);
            }
        }
        if(x1.front()>=0&&x1.front()<r&&y1.front()-1>=0&&y1.front()-1<c&&m[x1.front()][y1.front()-1]!=1){
            if(visited2[x1.front()][y1.front()-1]==false){
                visited2[x1.front()][y1.front()-1]=true;
                if(m[x1.front()][y1.front()-1]==3){
                    ans=min(ans,counter1.front()+1);
                    break;
                }
                x1.push(x1.front());
                y1.push(y1.front()-1);
                counter1.push(counter1.front()+1);
            }
        }
        x1.pop();
        y1.pop();
        counter1.pop();
    }
    while(!x1.empty()){
        x1.pop();
        y1.pop();
        counter1.pop();
    }
    return;
}
int main(){
    cin >> c >> r;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> m[i][j];
            if(m[i][j]==2){
                x.push(i);
                y.push(j);
                counter.push(0);
                visited[i][j]=true;
            }
        }
    }
    while(!x.empty()){
        if(x.front()+1>=0&&x.front()+1<r&&y.front()>=0&&y.front()<c&&m[x.front()+1][y.front()]!=1&&m[x.front()+1][y.front()]!=3){
            if(visited[x.front()+1][y.front()]==false){
                visited[x.front()+1][y.front()]=true;
                if(m[x.front()+1][y.front()]==4){
                    x1.push(x.front()+1);
                    y1.push(y.front());
                    counter1.push(counter.front()+1);
                    for(int i=0;i<r;i++){
                        for(int j=0;j<c;j++){
                            visited2[i][j]=false;
                        }
                    }
                    visited2[x1.front()][y1.front()]=true;
                    bfs();
                }
                else{
                    x.push(x.front()+1);
                    y.push(y.front());
                    counter.push(counter.front()+1);
                }
            }
        }
        if(x.front()-1>=0&&x.front()-1<r&&y.front()>=0&&y.front()<c&&m[x.front()-1][y.front()]!=1&&m[x.front()-1][y.front()]!=3){
            if(visited[x.front()-1][y.front()]==false){
                visited[x.front()-1][y.front()]=true;
                if(m[x.front()-1][y.front()]==4){
                    x1.push(x.front()-1);
                    y1.push(y.front());
                    counter1.push(counter.front()+1);
                    for(int i=0;i<r;i++){
                        for(int j=0;j<c;j++){
                            visited2[i][j]=false;
                        }
                    }
                    visited2[x1.front()][y1.front()]=true;
                    bfs();
                }
                else{
                    x.push(x.front()-1);
                    y.push(y.front());
                    counter.push(counter.front()+1);
                }
            }
        }
        if(x.front()>=0&&x.front()<r&&y.front()+1>=0&&y.front()+1<c&&m[x.front()][y.front()+1]!=1&&m[x.front()][y.front()+1]!=3){
            if(visited[x.front()][y.front()+1]==false){
                visited[x.front()][y.front()+1]=true;
                if(m[x.front()][y.front()+1]==4){
                    x1.push(x.front());
                    y1.push(y.front()+1);
                    counter1.push(counter.front()+1);
                    for(int i=0;i<r;i++){
                        for(int j=0;j<c;j++){
                            visited2[i][j]=false;
                        }
                    }
                    visited2[x1.front()][y1.front()]=true;
                    bfs();
                }
                else{
                    x.push(x.front());
                    y.push(y.front()+1);
                    counter.push(counter.front()+1);
                }
            }
        }
        if(x.front()>=0&&x.front()<r&&y.front()-1>=0&&y.front()-1<c&&m[x.front()][y.front()-1]!=1&&m[x.front()][y.front()-1]!=3){
            if(visited[x.front()][y.front()-1]==false){
                visited[x.front()][y.front()-1]=true;
                if(m[x.front()][y.front()-1]==4){
                    x1.push(x.front());
                    y1.push(y.front()-1);
                    counter1.push(counter.front()+1);
                    for(int i=0;i<r;i++){
                        for(int j=0;j<c;j++){
                            visited2[i][j]=false;
                        }
                    }
                    visited2[x1.front()][y1.front()]=true;
                    bfs();
                }
                else{
                    x.push(x.front());
                    y.push(y.front()-1);
                    counter.push(counter.front()+1);
                }
            }
        }
        x.pop();
        y.pop();
        counter.pop();
    }
    cout << ans;
}
/*
Problem Statement:
Knights of Ni
=============

Bessie is in Camelot and has encountered a sticky situation: she
needs to pass through the forest that is guarded by the Knights of
Ni. In order to pass through safely, the Knights have demanded that
she bring them a single shrubbery. Time is of the essence, and
Bessie must find and bring them a shrubbery as quickly as possible.

Bessie has a map of of the forest, which is partitioned into a
square grid arrayed in the usual manner, with axes parallel to the
X and Y axes. The map is W x H units in size (1 <= W <= 1000; 1 <=
H <= 1000).

The map shows where Bessie starts her quest, the single square where
the Knights of Ni are, and the locations of all the shrubberies of
the land. It also shows which areas of the map can be traverse (some
grid blocks are impassable because of swamps, cliffs, and killer
rabbits). Bessie can not pass through the Knights of Ni square
without a shrubbery.

In order to make sure that she follows the map correctly, Bessie
can only move in four directions: North, East, South, or West (i.e.,
NOT diagonally). She requires one day to complete a traversal from
one grid block to a neighboring grid block.

It is guaranteed that Bessie will be able to obtain a shrubbery and then
deliver it to the Knights of Ni. Determine the quickest way for her to do so.

PROBLEM NAME: ni

INPUT FORMAT:

* Line 1: Two space-separated integers: W and H.

* Lines 2..?: These lines describe the map, row by row. The first line
        describes the most northwest part of the map; the last line
        describes the most southeast part of the map. Successive
        integers in the input describe columns of the map from west to
        east. Each new row of a map's description starts on a new
        input line, and each input line contains no more than 40
        space-separated integers. If W <= 40, then each input line
        describes a complete row of the map. If W > 40, then more than
        one line is used to describe a single row, 40 integers on each
        line except potentially the last one. No input line ever
        describes elements of more than one row.

The integers that describe the map come from this set:
0: Square through which Bessie can travel
1: Impassable square that Bessie cannot traverse
2: Bessie's starting location
3: Location of the Knights of Ni
4: Location of a shrubbery

SAMPLE INPUT:

8 4
4 1 0 0 0 0 1 0
0 0 0 1 0 1 0 0
0 2 1 1 3 0 4 0
0 0 0 4 1 1 1 0

INPUT DETAILS:

Width=8, height=4. Bessie starts on the third row, only a few squares away
from the Knights.

OUTPUT FORMAT:

* Line 1: D, the minimum number of days it will take Bessie to reach a
        shrubbery and bring it to the Knights of Ni.

SAMPLE OUTPUT:

11

OUTPUT DETAILS:

Bessie can move in this pattern to get a shrubbery for the Knights:
N, W, N, S, E, E, N, E, E, S, S. She gets the shrubbery in the northwest
corner and then makes her away around the barriers to the east and then
south to the Knights.
*/
