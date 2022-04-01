#include <iostream>
using namespace std;
bool visited[2500];
int dist[2500];
int adjmatrix[2500][2500];
int main(){
    int v,e,s,a,b,c;
    cin >> v >> e >> s;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            adjmatrix[i][j]=1000000000;
        }
    }
    for(int i=0;i<v;i++){
        dist[i]=1000000000;
    }
    dist[s-1]=0;
    for(int i=0;i<e;i++){
        cin >> a >> b >> c;
        adjmatrix[a-1][b-1]=c;
        adjmatrix[b-1][a-1]=c;
    }
    for(int i=0;i<v;i++){
        int mind=100000000,minindex=-1;
        for(int j=0;j<v;j++){
            if(visited[j]==false&&dist[j]<mind){
                mind=dist[j];
                minindex=j;
            }
        }
        visited[minindex]=true;
        for(int j=0;j<v;j++){
            if(visited[j]==false&&minindex!=-1){
                dist[j]=min(dist[j],dist[minindex]+adjmatrix[minindex][j]);
            }
        }
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            cout << "-1" << endl;
        }
        else{
            cout << dist[i] << endl;
        }
    }
}
/*
Problem Statement:
Given a graph with V (1 <= V <= 2,500) vertices with E bidirectional
edges and a source node S (1 <= S <= V), output the shortest
distance from S to every node (including itself). Each edge
connects two verticies A_i and B_i (1 <= A_i, B_i <= V) and has
a length of C_i (1 <= C_i <= 10,000). If there is no path from S
to a certain node, output -1.

PROBLEM NAME: dijkstra

INPUT FORMAT:

* Line 1: Three space-separated integers: V, E, and S

* Line 2...E+1: Three space-separated integers: A_i, B_i, and C_i

SAMPLE INPUT:

6 5 1
3 4 5
5 6 4
1 2 6
3 2 3
3 1 2

OUTPUT FORMAT:

* Line 1...V: Line i contains the distance from node S to node i.

SAMPLE OUTPUT:

0
5
2
7
-1
-1Given a graph with V (1 <= V <= 2,500) vertices with E bidirectional
edges and a source node S (1 <= S <= V), output the shortest
distance from S to every node (including itself). Each edge
connects two verticies A_i and B_i (1 <= A_i, B_i <= V) and has
a length of C_i (1 <= C_i <= 10,000). If there is no path from S
to a certain node, output -1.

PROBLEM NAME: dijkstra

INPUT FORMAT:

* Line 1: Three space-separated integers: V, E, and S

* Line 2...E+1: Three space-separated integers: A_i, B_i, and C_i

SAMPLE INPUT:

6 5 1
3 4 5
5 6 4
1 2 6
3 2 3
3 1 2

OUTPUT FORMAT:

* Line 1...V: Line i contains the distance from node S to node i.

SAMPLE OUTPUT:

0
5
2
7
-1
-1
*/
