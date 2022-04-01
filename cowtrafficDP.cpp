#include <bits/stdc++.h>
using namespace std;
int n,m,dpback[50001],dpfront[50001],a,b,ans;
bool indegree[50001];
vector<int> adjlist[50001];
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b; a--; b--;
        adjlist[a].push_back(b);
        indegree[b]=true;
    }
    for(int i=0;i<n-1;i++){
        if(indegree[i]==false){
            dpfront[i]=1;
        }
    }
    dpback[n-1]=1;
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<adjlist[i].size();j++){
            dpback[i]+=dpback[adjlist[i][j]];
        }
    }
    dpfront[0]=1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<adjlist[i].size();j++){
            dpfront[adjlist[i][j]]+=dpfront[i];
        }
    }
    for(int i=0;i<=n-2;i++){
        for(int j=0;j<adjlist[i].size();j++){
            ans=max(ans,dpfront[i]*dpback[adjlist[i][j]]);
        }
    }
    cout << ans;
}
/*
Problem Statement:
Cow Traffic
===========

The bovine population boom down on the farm has caused serious congestion
on the cow trails leading to the barn. Farmer John has decided to conduct
a study to find the bottlenecks in order to relieve the 'traffic jams' at
milking time.

The pasture contains a network of M (1 <= M <= 50,000) one-way trails, each
of which connects exactly two different intersections from the set of N
(1 <= N <= 5,000) intersections conveniently numbered 1..N; the barn is at
intersection number N. Each trail connects one intersection point to another
intersection point with a higher number. As a result, there are no cycles
and, as they say on the farm, all trails lead to the barn. A pair of
intersection points might be connected by more than one trail.

During milking time rush hour, the cows start from their respective grazing
locations and head to the barn. The grazing locations are exactly those
intersection points with no trails connecting into them. Each cow traverses
a 'path', which is defined as a sequence of trails from a grazing location
to the barn.

Help FJ finding the busiest trail(s) by computing the largest number of
possible paths that contain any one trail. The answer is guaranteed to fit
in a signed 32-bit integer.

PROBLEM NAME: traffic

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M.

* Lines 2..M+1: Two space-separated intersection points.

SAMPLE INPUT:

7 7
1 3
3 4
3 5
4 6
2 3
5 6
6 7

OUTPUT FORMAT:

* Line 1: The maximum number of paths passing through any one trail.

SAMPLE OUTPUT:

4

OUTPUT DETAILS:

Here are the four possible paths that lead to the barn:

1 3 4 6 7
1 3 5 6 7
2 3 4 6 7
2 3 5 6 7
*/
