#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct vec{
    vector <int> y;
};
bool visited[20000];
int main(){
    queue<int> x;
    queue<int> counter;
    x.push(0);
    counter.push(0);
    int n,m,a,b,finalans,dist=0,howmany=0;
    cin >> n >> m;
    vec adjlist[n];
    int ans[n];
    for(int i=0;i<n;i++){
        ans[n]=0;
    }
    for(int i=0;i<m;i++){
        cin >> a >> b;
        adjlist[a-1].y.push_back(b-1);
        adjlist[b-1].y.push_back(a-1);
    }
    while(!x.empty()){
        for(int i=0;i<adjlist[x.front()].y.size();i++){
            if(visited[adjlist[x.front()].y[i]]==false){
                visited[adjlist[x.front()].y[i]]=true;
                x.push(adjlist[x.front()].y[i]);
                counter.push(counter.front()+1);
            }
        }
        ans[x.front()]=counter.front();
        x.pop();
        counter.pop();
    }
    for(int i=1;i<n;i++){
        if(ans[i]>dist){
            finalans=i+1;
            howmany=1;
            dist=ans[i];
        }
        else if(ans[i]==dist){
            howmany++;
        }
    }
    cout << finalans << " " << dist << " " << howmany;
}
/*
Problem Statement:
Bessie is playing hide and seek (a game in which a number of players
hide and a single player (the seeker) attempts to find them after
which various penalties and rewards are assessed; much fun usually
ensues).

She is trying to figure out in which of N (2 <= N <= 20,000) barns
conveniently numbered 1..N she should hide. She knows that FJ (the
seeker) starts out in barn 1. All the barns are connected by M (1
<= M <= 50,000) bidirectional paths with endpoints A_i and B_i (1
<= A_i <= N; 1 <= B_i <= N; A_i != B_i); it is possible to reach
any barn from any other through the paths.

Bessie decides that it will be safest to hide in the barn that has
the greatest distance from barn 1 (the distance between two barns
is the smallest number of paths that one must traverse to get from
one to the other). Help Bessie figure out the best barn in which
to hide.

PROBLEM NAME: hideseek

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..M+1: Line i+1 contains the endpoints for path i: A_i and
        B_i

SAMPLE INPUT:

6 7
3 6
4 3
3 2
1 3
1 2
2 4
5 2

INPUT DETAILS:

The farm layout is as follows:

                   1--2--5
                   | /|
                   |/ |
                   3--4
                   |
                   6

OUTPUT FORMAT:

* Line 1: On a single line, print three space-separated integers: the
        index of the barn farthest from barn 1 (if there are multiple
        such barns, print the smallest such index), the smallest
        number of paths needed to reach this barn from barn 1, and the
        number of barns with this number of paths.

SAMPLE OUTPUT:

4 2 3

OUTPUT DETAILS:

Barns 1, 5, and 6 are all a distance of 2 from barn 1. We choose barn 4
because it has the smallest index.
*/
