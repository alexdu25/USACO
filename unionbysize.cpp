#include <iostream>
using namespace std;
int parent[n],treesize[n];
int findleader(int node){//finds leader of node's group
    if(parent[node]==node) return node;
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
int main(){
    int n;
    cin >> n;

}

