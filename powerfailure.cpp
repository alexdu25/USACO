#include <iostream>
#include <cmath>
#define INF 1000000000
using namespace std;
int n,w;
double maxlength,dist[1001];
bool visited[1001];
bool adjmatrix[1001][1001];
struct point{
    int x,y;
};
point powergrid[1001];
double distanceformula(point a,point b,int p1,int p2){
    if(adjmatrix[p1][p2]==true){
        return 0;
    }
    int x1=a.x;
    int y1=a.y;
    int x2=b.x;
    int y2=b.y;
    double tempx=pow((x1-x2),2);
    double tempy=pow((y1-y2),2);
    tempx+=tempy;
    return sqrt(tempx);
}
int main(){
    cin >> n >> w >> maxlength;
    for(int i=0;i<=n;i++){
        dist[i]=1000000000;
    }
    dist[1]=0;
    for(int i=1;i<=n;i++){
        cin >> powergrid[i].x >> powergrid[i].y;
    }
    for(int i=0;i<w;i++){
        int a,b;
        cin >> a >> b;
        adjmatrix[a][b]=true; adjmatrix[b][a]=true;
    }
    for(int i=1;i<=n;i++){
        double mind=INF;
        int minindex=-1;
        for(int j=1;j<=n;j++){
            if(visited[j]==false&&dist[j]<mind){
                mind=dist[j];
                minindex=j;
            }
        }
        visited[minindex]=true;
        for(int j=1;j<=n;j++){
            if(visited[j]==false&&minindex!=-1){
                double temp=distanceformula(powergrid[minindex],powergrid[j],minindex,j);
                if(temp<=maxlength){
                    dist[j]=min(dist[j],dist[minindex]+temp);
                }
            }
        }
    }
    if(dist[n]==INF){
        cout << "-1";
        return 0;
    }
    cout << (int) (dist[n]*1000);
}
/*
Problem Statement:
Power Failure
=============

A vicious thunderstorm has destroyed some of the wires of the farm's
electrical power grid! Farmer John has a map of all N (2 <= N <=
1,000) of the powerpoles, which are conveniently numbered 1..N and
located on integer plane coordinates x_i,y_i (-100,000 <= x_i <=
100000; -100,000 <= y_i <= 100,000).

Some W (1 <= W <= 10,000) power wires connect pairs of power poles
Pi and Pj (1 <= Pi <= N; 1 <= Pj <= N).

He needs to get power from pole 1 to pole N (which means that some
series of wires can traverse from pole 1 to pole N, probably through
some intermediate set of poles).

Given the locations of the N poles and the list of remaining power
wires, determine the minimum length of power wire required to restore
the electrical connection so that electricity can flow from pole 1
to pole N.  No wire can be longer than some real number M (0.0 < M
<= 200,000.0).

As an example, below on the left is a map of the 9 poles and 3 wires
after the storm. For this task, M = 2.0. The best set of wires to
add would connect poles 4 and 6 and also poles 6 and 9.

      After the storm              Optimally reconnected

3  . . . 7 9 . . . . .          3  . . . 7 9 . . . . .
                                          /
2  . . 5 6 . . . . . .          2  . . 5 6 . . . . . .
                                        /
1  2-3-4 . 8 . . . . .          1  2-3-4 . 8 . . . . .
   |                               |
0  1 . . . . . . . . .          0  1 . . . . . . . . .

   0 1 2 3 4 5 6 7 8 9             0 1 2 3 4 5 6 7 8 9

The total length is then 1.414213562 + 1.414213562 = 2.828427124 .

PROBLEM NAME: pwrfail

INPUT FORMAT:

* Line 1: Two space-separated integers: N and W

* Line 2: A single real number: M

* Lines 3..N+2: Each line contains two space-separated integers: x_i
        and y_i

* Lines N+3..N+2+W: Two space-separated integers: Pi and Pj

SAMPLE INPUT:

9 3
2.0
0 0
0 1
1 1
2 1
2 2
3 2
2 3
4 1
4 3
1 2
2 3
3 4

INPUT DETAILS:

Just as in the diagram above.

OUTPUT FORMAT:

* Line 1: A single integer on a single line.  If restoring connection
        is impossible, output -1. Otherwise, output a single integer
        that is 1000 times the total minimum cost to restore
        electricity. Do not perform any rounding; truncate the
        resulting product.

SAMPLE OUTPUT:

2828

OUTPUT DETAILS:

As above.
*/
