#include <iostream>
#include <queue>
using namespace std;
int dist[100000],n,c,a,b;
int adj[100000][2];
bool visited[100000];
int main(){
    cin >> n >> c;
    for(int i=0;i<=100000;i++){
        adj[i][0]=1000000000;
        adj[i][1]=1000000000;
    }
    for(int i=0;i<c;i++){
        cin >> a;
        cin >> adj[a][0] >> adj[a][1];
    }
    queue<int> x;
    queue<int> counter;
    x.push(1);
    counter.push(1);
    while(!x.empty()){
        dist[x.front()]=counter.front();
        if(x.front()!=-1){
            if(adj[x.front()][0]!=1000000000&&x.front()<=n){
                if(visited[adj[x.front()][0]]==false){
                    visited[adj[x.front()][0]]=true;
                    x.push(adj[x.front()][0]);
                    counter.push(counter.front()+1);
                }
            }
            if(adj[x.front()][1]!=1000000000&&x.front()<=n){
                if(visited[adj[x.front()][1]]==false){
                    visited[adj[x.front()][1]]=true;
                    x.push(adj[x.front()][1]);
                    counter.push(counter.front()+1);
                }
            }
        }
        x.pop();
        counter.pop();
    }
    for(int i=1;i<=n;i++){
            cout << dist[i] << endl;
        }
}
/*
Problem Statement:
Clear Cold Water
================

The steamy, sweltering summers of Wisconsin's dairy district stimulate
the cows to slake their thirst. Farmer John pipes clear cold water
into a set of N (3 <= N <= 99999; N odd) branching pipes conveniently
numbered 1..N from a pump located at the barn. As the water flows
through the pipes, the summer heat warms it.  Bessie wants to find
the coldest water so she can enjoy the weather more than any other
cow.

She has mapped the entire set of branching pipes and noted that
they form a tree with its root at the farm and furthermore that
every branch point has exactly two pipes exiting from it. Surprisingly,
every pipe is exactly one unit in length; of course, all N pipes
connect up in one way or another to the pipe-tree.

Given the map of all the pipe connections, make a list of the
distance from the barn for every branching point and endpoint.
Bessie will use the list to find the very coldest water.

The endpoint of a pipe, which might enter a branching point or might
be a spigot, is named by the pipe's number. The map contains C (1
<= C <= N) connections, each of which specifies three integers: the
endpoint E_i (1 <= E_i <= N) of a pipe and two branching pipes B1_i
and B2_i (2 <= B1_i <= N; 2 <= B2_i <= N). Pipe number 1 connects
to the barn; the distance from its endpoint to the barn is 1.

PROBLEM NAME: coldwat

INPUT FORMAT:

* Line 1: Two space-separated integers: N and C

* Lines 2..C+1: Line i+1 describes branching point i with three
        space-separated integers: E_i, B1_i, and B2_i

SAMPLE INPUT:

5 2
3 5 4
1 2 3

INPUT DETAILS:
The input above describes this pipe map:
                    +------+
                    | Barn |
                    +------+
                       | 1
                       *
                    2 / \ 3
                         *
                      4 / \ 5

OUTPUT FORMAT:

* Lines 1..N: Line i of the output contains a single integer that is
        the distance from the barn to the endpoint of pipe i

SAMPLE OUTPUT:

1
2
2
3
3

OUTPUT DETAILS:

Pipe 1 is always distance 1 from the barn. Pipes 2 and 3 connect directly
to pipe 1 and thus are distance 2 from the barn. Pipes 4 and 5, which
connect to pipe 3, are distance 3 from the barn.
*/
