#include <iostream>
using namespace std;
int parent[n],ranking[n];
int findleader(int node){//finds leader of node's group
    if(parent[node]==node){
        return node;
    }
    parent[node]=findleader(parent[node]);//path compression;
    return parent[node];
}
bool findunion(int node1,int node2){//if they are part of same set
    int leader1=findleader(node1);
    int leader2=findleader(node2);
    if(leader1==leader2){
        return true;
    }
    if(ranking[leader1]<ranking[leader2]){
        parent[leader1]=leader2;
    }
    else if(ranking[leader1]==ranking[leader2]){
        parent[leader1]=leader2;
    }
    else{
        parent[leader2]=leader1;
    }
}
int main(){
    int n;
    cin >> n;

}
