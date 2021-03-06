#include <iostream>
using namespace std;
int adjmatrix[2501][2501];
bool visited[2500];
int dist[2500];
int main(){
    int v,e,a,b,c,ans=0;
    cin >> v >> e;
    for(int i=0;i<v;i++){
        dist[i]=1000000000;
    }
    dist[0]=0;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            adjmatrix[i][j]=1000000000;
        }
    }
    for(int i=0;i<e;i++){
        cin >> a >> b >> c;
        adjmatrix[a-1][b-1]=c;
        adjmatrix[b-1][a-1]=c;
    }
    for(int i=0;i<v;i++){
        int mind=1000000000,minindex=-1;
        for(int j=0;j<v;j++){
            if(visited[j]==false&&dist[j]<mind){
                mind=dist[j];
                minindex=j;
            }
        }
        visited[minindex]=true;
        ans+=mind;
        for(int j=0;j<v;j++){
            if(visited[j]==false){
                dist[j]=min(dist[j],adjmatrix[minindex][j]);
            }
        }
    }
    cout << ans << endl;
}
/*
Problem Statement:
Given an undirected, connected graph with V (1 <= V <= 2,500)
vertices and E edges, find the minimum spanning tree. An edge
connects vertices A_i and B_i (1 <= A_i, B_i <= V) and costs C_i
(1 <= C_i <= 10,000).

PROBLEM NAME: mst

INPUT FORMAT:

* Line 1: Two space-separated integers: V and E

* Line 2...E+1: Three space-separated integers: A_i, B_i, and C_i

SAMPLE INPUT:

5 8
1 2 3
5 3 5
5 1 7
1 3 1
5 2 9
5 4 4
4 3 6
2 3 4

OUTPUT FORMAT:

* Line 1: The cost of the minimum spanning tree.

SAMPLE OUTPUT:

13
*/
