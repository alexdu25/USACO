//first term in priority queue is distance, second term in priority queue is the vertex
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    int v,e,a,b,c,start;
    cin >> v >> e >> start;

    vector< pair<int,int> > adjlist[v];
    for(int i=0;i<e;i++){
        cin >> a >> b >> c;
        a--;
        b--;
        adjlist[a].push_back(make_pair(b,c));
        adjlist[b].push_back(make_pair(a,c));
    }
    priority_queue< pair<int,int> > q;
    int dist[v];
    bool visited[v];
    for(int i=0;i<v;i++){
        dist[i]=1000000000;
        visited[i]=false;
    }
    dist[start-1]=0;
    q.push(make_pair(0,start-1));
    while(!q.empty()){
        if(visited[q.top().second]==false){
            visited[q.top().second]=true;
            int x=q.top().second;
            for(int i=0;i<adjlist[q.top().second].size();i++){
                int x2=adjlist[x][i].first;
                int length = adjlist[q.top().second][i].second;
                if(visited[x2]==false&&(dist[x2]>dist[x]+length)){
                    dist[x2]=dist[x]+length;
                    q.push(make_pair(-dist[x2],x2));
                }
            }
        }
        q.pop();
    }
    for(int i=0;i<v;i++){
        if(dist[i]==1000000000){
            cout << "-1" << endl;
        }
        else{
            cout << dist[i] << endl;
        }
    }
}
/*
Problem Statement:
Dijkstra's Shortest Path II
===========================

Given a graph with V (1 <= V <= 50,000) vertices and
E (1 <= E <= 100,000) bidirectional edges and a source node
S (1 <= S <= V), output the shortest distance from S to
every node (including itself). Each edge connects two
verticies A_i and B_i (1 <= A_i, B_i <= V) and has a length
of C_i (1 <= C_i <= 10,000). If there is no path from S to
a certain node, output -1.

PROBLEM NAME: dijkstra2

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
