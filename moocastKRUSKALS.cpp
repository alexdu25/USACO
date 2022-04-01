#include <bits/stdc++.h>
using namespace std;
int n,parent[1001],treesize[1001],input[1001][2],ans;
multiset< pair <int, pair<int,int> > > ms;
multiset< pair <int, pair<int,int> > > :: iterator itr;
int dist(int x1,int y1,int x2,int y2){
    int dx=x2-x1,dy=y2-y1;
    dx*=dx; dy*=dy;
    return dx+dy;
}
int findleader(int node){//finds leader of node's group
    if(parent[node]==node){
        return node;
    }
    parent[node]=findleader(parent[node]);//path compression;
    return parent[node];
}
void combine(int node1,int node2){
    int leader1=findleader(node1);
    int leader2=findleader(node2);
    if(leader1==leader2){
        return;
    }
    if(treesize[leader1]<=treesize[leader2]){//don't need to consider equal condition
        parent[leader1]=leader2;
        treesize[leader2]+=treesize[leader1];
    }
    else{
        parent[leader2]=leader1;
        treesize[leader1]+=treesize[leader2];
    }
}
void kruskals(){
    int totalsize=1;//when totalsize hits n, got everything
    for(int i=0;i<n;i++){
        parent[i]=i;
        treesize[i]=i;
    }
    while(totalsize<n){
        itr=ms.begin();
        int d=(*itr).first;
        int n1=(*itr).second.first;
        int n2=(*itr).second.second;
        pair<int,pair<int,int> > p;
        p.first=d;
        p.second.first=n1;
        p.second.second=n2;
        ms.erase(p);
        if(findleader(n1)!=findleader(n2)){
            combine(n1,n2);
            totalsize++;
            ans=max(ans,d);
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> input[i][0] >> input[i][1];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x=dist(input[i][0],input[i][1],input[j][0],input[j][1]);
            ms.insert(make_pair(x,make_pair(i,j)));
        }
    }
    kruskals();
    cout << ans;
}
/*
Problem Statement:
Moocast
=======
[Memory: 64 MB]

Farmer John's N cows (1 <= N <= 1000) want to organize an emergency
"moo-cast" system for broadcasting important messages among
themselves.

Instead of mooing at each-other over long distances, the cows decide
to equip themselves with walkie-talkies, one for each cow. These
walkie-talkies each have a limited transmission radius, but cows can
relay messages to one-another along a path consisting of several
hops, so it is not necessary for every cow to be able to transmit
directly to every other cow.

The cows need to decide how much money to spend on their
walkie-talkies. If they spend $X, they will each get a walkie-talkie
capable of transmitting up to a distance of sqrt(X). That is, the
squared distance between two cows must be at most X for them to be
able to communicate.

Please help the cows determine the minimum integer value of X such
that a broadcast from any cow will ultimately be able to reach every
other cow.

PROBLEM NAME: moocast

INPUT FORMAT:

The first line of input contains N.

The next N lines each contain the x and y coordinates of a single
cow. These are both integers in the range 0...25,000.

OUTPUT FORMAT:

Write a single line of output containing the integer X giving the
minimum amount the cows must spend on walkie-talkies.

SAMPLE INPUT:

4
1 3
5 4
7 2
6 1

SAMPLE OUTPUT:

17
*/
