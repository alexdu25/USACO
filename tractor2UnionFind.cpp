#include <iostream>
#include <cmath>
using namespace std;
int n,adjmatrix[1001][1001],a,b,treesize[1001],parent[1001],currentsize;
struct point{
    int x,y,index;
};
point input[1001];
int findleader(int node){//finds leader of node's group
    if(parent[node]==node){
        return node;
    }
    return findleader(parent[node]);
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
        currentsize=treesize[leader2];
    }
    else{
        parent[leader2]=leader1;
        treesize[leader1]+=treesize[leader2];
        currentsize=treesize[leader1];
    }
}
bool possible(int query){
    for (int i=1;i<=n;i++) {
        parent[i]=i;
        treesize[i]=1;
    }
    currentsize=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(adjmatrix[i][j]<=query){
                combine(i,j);
            }
            if(currentsize==n){
                return true;
            }
        }
    }
    return false;
}
int binarysearch(int lower,int upper){
    while(lower!=upper){
        if(lower==upper-1){
            if(possible(lower)==true){
                return lower;
            }
            else{
                return upper;
            }
        }
        int newbound=((upper+lower+1)/2);
        if(possible(newbound)==true){
            return binarysearch(lower,newbound);
        }
        if(possible(newbound)==false){
            return binarysearch(newbound,upper);
        }
    }
}
int main(){
    cin >> n;
    n*=n; n++; n/=2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> adjmatrix[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adjmatrix[i][j]=pow((input[i].x-input[j].x),2)+pow((input[i].y-input[j].y),2);
        }
    }
    cout << binarysearch(0,1000000000);
}

