#include <iostream>
using namespace std;
bool visited[2500];
int adjmatrix[2500][2500];
int dist[2500];
int main(){
    int t,c,ts,te,a,b,c1;
    cin >> t >> c >> ts >> te;
    for(int i=0;i<t;i++){
        dist[i]=1000000000;
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            adjmatrix[i][j]=1000000000;
        }
    }
    for(int i=0;i<c;i++){
        cin >> a >> b >> c1;
        adjmatrix[a-1][b-1]=c1;
        adjmatrix[b-1][a-1]=c1;
    }
    dist[ts-1]=0;
    for(int i=0;i<t;i++){
        int mind=100000000,minindex=-1;
        for(int j=0;j<t;j++){
            if(visited[j]==false&&dist[j]<mind){
                mind=dist[j];
                minindex=j;
            }
        }
        visited[minindex]=true;
        for(int j=0;j<t;j++){
            if(visited[j]==false&&minindex!=-1){
                dist[j]=min(dist[j],dist[minindex]+adjmatrix[minindex][j]);
            }
        }
    }
    cout << dist[te-1];
}
/*
Problem Statement:
The good folks in Texas are having a heatwave this summer. Their
Texas Longhorn cows make for good eating but are not so adept at
creating creamy delicious dairy products. Farmer John is leading
the charge to deliver plenty of ice cold nutritious milk to Texas
so the Texans will not suffer the heat too much.

FJ has studied the routes that can be used to move milk from Wisconsin
to Texas. These routes have a total of T (1 <= T <= 2,500) towns
conveniently numbered 1..T along the way (including the starting
and ending towns). Each town (except the source and destination
towns) is connected to at least two other towns by bidirectional
roads that have some cost of traversal (owing to gasoline consumption,
tolls, etc.). Consider this map of seven towns; town 5 is the
source of the milk and town 4 is its destination (bracketed integers
represent costs to traverse the route):

                              [1]----1---[3]-
                             /               \
                      [3]---6---[4]---3--[3]--4
                     /               /       /|
                    5         --[3]--  --[2]- |
                     \       /        /       |
                      [5]---7---[2]--2---[3]---
                            |       /
                           [1]------

Traversing 5-6-3-4 requires spending 3 (5->6) + 4 (6->3) + 3 (3->4)
= 10 total expenses.

Given a map of all the C (1 <= C <= 6,200) connections (described
as two endpoints R1i and R2i (1 <= R1i <= T; 1 <= R2i <= T) and
costs (1 <= Ci <= 1,000), find the smallest total expense to traverse
from the starting town Ts (1 <= Ts <= T) to the destination town
Te (1 <= Te <= T).

PROBLEM NAME: heatwv

INPUT FORMAT:

* Line 1: Four space-separated integers: T, C, Ts, and Te

* Lines 2..C+1: Line i+1 describes road i with three space-separated
        integers: R1i, R2i, and Ci

SAMPLE INPUT:

7 11 5 4
2 4 2
1 4 3
7 2 2
3 4 3
5 7 5
7 3 3
6 1 1
6 3 4
2 4 3
5 6 3
7 2 1

INPUT DETAILS:

As in the sample map.

OUTPUT FORMAT:

* Line 1: A single integer that is the length of the shortest route
        from Ts to Te. It is guaranteed that at least one route exists.

SAMPLE OUTPUT:

7

OUTPUT DETAILS:

5->6->1->4 (3 + 1 + 3)
*/
