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
void combine(int node1,int node2){
    int leader1=findleader(node1);
    int leader2=findleader(node2);
    if(leader1==leader2){
        return;
    }
    if(ranking[leader1]<ranking[leader2]){
        parent[leader1]=leader2;
    }
    else if(ranking[leader1]==ranking[leader2]){
        parent[leader1]=leader2;
        ranking[leader2]+=1;//extra layer, leader2 becomes the new top node, leader1 has a node drop down extra 1
    }
    else{
        parent[leader2]=leader1;
    }
}
int main(){

}
