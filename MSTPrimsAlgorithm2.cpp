#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> p;
int main(){
    int v,e,a,b,c,ans=0;
    cin >> v >> e;
    vector <pair<int,int> >adjlist[v+1];
    for(int i=0;i<e;i++){
        cin >> a >> b >> c;
        a--;
        b--;
        adjlist[a].push_back(make_pair(b,c));
        adjlist[b].push_back(make_pair(a,c));
    }
    priority_queue<p,vector<p>,greater<p> > pq;
    int dist[v];
    bool visited[v];
    for(int i=0;i<v;i++){
        dist[i]=1000000000;
        visited[i]=false;
    }
    dist[0]=0;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        int idx=pq.top().second;
        pq.pop();
        if(visited[idx]==false){
            visited[idx]=true;
            for(int i=0;i<adjlist[idx].size();i++){
                int x=adjlist[idx][i].first;
                int length=adjlist[idx][i].second;
                if(visited[x]==false&&(dist[x]>length)){
                    dist[x]=length;
                    pq.push(make_pair(dist[x],x));
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        ans+=dist[i];
    }
    cout << ans;
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
