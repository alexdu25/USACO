#include <iostream>
#include <algorithm>
using namespace std;
int adjmatrix[501][501];
bool visited[501];
int dist[501];
int fav[501];
int nodes,favorites,paths,a,b,c,ans,tempavg,avgn;
double t;
bool binarysearch(int b){
    int upper=favorites;
    int lower=-1;
    while(lower!=upper){
        int newbound=((upper+lower+1)/2);
        if(fav[newbound]==b){
            return true;
        }
        if(fav[newbound]<=b){
            lower=newbound;
        }
        else{
            upper=newbound-1;
        }
    }
    return false;
}
int main(){
    double avg=1000000000;
    cin >> nodes >> favorites >> paths;
    for(int i=0;i<favorites;i++){
        cin >> fav[i];
    }
    sort(fav,fav+favorites);
    for(int i=0;i<=nodes;i++){
        for(int j=0;j<=nodes;j++){
            adjmatrix[i][j]=1000000000;
        }
    }
    for(int i=0;i<paths;i++){
        cin >> a >> b >> c;
        adjmatrix[a][b]=c;
        adjmatrix[b][a]=c;
    }
    for(int i=1;i<=nodes;i++){
        for(int j=0;j<=nodes;j++){
            dist[j]=1000000000;
            visited[j]=false;
        }
        dist[i]=0;
        for(int j=1;j<=nodes;j++){
            int mind=1000000000, minindex=-1;
            for(int k=1;k<=nodes;k++){
                if(visited[k]==false&&dist[k]<mind){
                    mind=dist[k];
                    minindex=k;
                }
            }
            visited[minindex]=true;
            for(int k=1;k<=nodes;k++){
                if(visited[k]==false&&minindex!=-1){
                    dist[k]=min(dist[k],dist[minindex]+adjmatrix[minindex][k]);
                }
            }
        }
        tempavg=0;
        for(int k=1;k<=nodes;k++){
            if(binarysearch(k)==true){
                tempavg+=dist[k];
            }
        }
        t= (double) tempavg/favorites;
        if(t<avg){
            avg=t;
            ans=i;
        }
    }
    cout << ans;
}
/*
Problem Statement:
Bessie, always wishing to optimize her life, has realized that she
really enjoys visiting F (1 <= F <= P) favorite pastures F_i of the
P (1 <= P <= 500; 1 <= F_i <= P) total pastures (conveniently
numbered 1..P) that compose Farmer John's holdings.

Bessie knows that she can navigate the C (1 <= C <= 8,000) bidirectional
cowpaths (conveniently numbered 1..C) that connect various pastures
to travel to any pasture on the entire farm. Associated with each
path P_i is a time T_i (1 <= T_i <= 892) to traverse that path (in
either direction) and two path endpoints a_i and b_i (1 <= a_i <=
P; 1 <= b_i <= P; a_i != b_i).

Bessie wants to find the number of the best pasture to sleep in so
that when she awakes, the average time to travel to any of her F
favorite pastures is minimized.

By way of example, consider a farm laid out as the map below shows,
where *'d pasture numbers are favorites. The bracketed numbers are
times to traverse the pastures.

            1*--[4]--2--[2]--3
                     |       |
                    [3]     [4]
                     |       |
                     4--[3]--5--[1]---6---[6]---7--[7]--8*
                     |       |        |         |
                    [3]     [2]      [1]       [3]
                     |       |        |         |
                    13*      9--[3]--10*--[1]--11*--[3]--12*

The following table shows distances for potential 'best place' of
pastures 4, 5, 6, 7, 9, 10, 11, and 12:

                       * * * * * * Favorites * * * * * *
 Potential      Pasture Pasture Pasture Pasture Pasture Pasture     Average
Best Pasture       1       8      10      11      12      13        Distance
------------      --      --      --      --      --      --      -----------
    4              7      16       5       6       9       3      46/6 = 7.67
    5             10      13       2       3       6       6      40/6 = 6.67
    6             11      12       1       2       5       7      38/6 = 6.33
    7             16       7       4       3       6      12      48/6 = 8.00
    9             12      14       3       4       7       8      48/6 = 8.00
   10             12      11       0       1       4       8      36/6 = 6.00 ** BEST
   11             13      10       1       0       3       9      36/6 = 6.00
   12             16      13       4       3       0      12      48/6 = 8.00

Thus, presuming these choices were the best ones (a program would
have to check all of them somehow), the best place to sleep is
pasture 10.

PROBLEM NAME: bestspot

INPUT FORMAT:

* Line 1: Three space-separated integers: P, F, and C

* Lines 2..F+1: Line i+2 contains a single integer: F_i

* Lines F+2..C+F+1: Line i+F+1 describes cowpath i with three
        space-separated integers: a_i, b_i, and T_i

SAMPLE INPUT:

13 6 15
11
13
10
12
8
1
2 4 3
7 11 3
10 11 1
4 13 3
9 10 3
2 3 2
3 5 4
5 9 2
6 7 6
5 6 1
1 2 4
4 5 3
11 12 3
6 10 1
7 8 7

INPUT DETAILS:

As the problem statement

OUTPUT FORMAT:

* Line 1: A single line with a single integer that is the best pasture
        in which to sleep. If more than one pasture is best, choose
        the smallest one.

SAMPLE OUTPUT:

10

OUTPUT DETAILS:

As the problem statement.
*/
