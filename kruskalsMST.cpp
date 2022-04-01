#include <bits/stdc++.h>
using namespace std;
int n,parent[1001],treesize[1001];
multiset< pair <int, pair<int,int> > > ms;
multiset< pair <int, pair<int,int> > > :: iterator itr;
int findleader(int node){//finds leader of node's group
    if(parent[node]==node)  return node;
    return parent[node]=findleader(parent[node]);//path compression;
}
void combine(int node1,int node2){
    int leader1=findleader(node1);
    int leader2=findleader(node2);
    if(leader1==leader2) return;
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
        }
    }
}
int main(){
    kruskals();
}
