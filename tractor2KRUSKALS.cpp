#include <bits/stdc++.h>
using namespace std;
int n,matrix[500][500],dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
struct node{
    int x1,y1,x2,y2,diff;
    bool operator<(node n1){
        return this.diff<n1.diff;
    }
};
multiset<node> ms;
multiset<node> :: iterator itr;
bool bound(int x1,int y1){
    if(x1<0||y1<0||x1>=n||y1>=n) return false;
    return true;
}
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
void kruskals(){
    int totalsize=1;//when totalsize hits n, got everything
    for(int i=0;i<n;i++){
        parent[i]=i;
        treesize[i]=i;
    }
    while(totalsize<(n*n+1)/2){
        itr=ms.begin();
        int d=(*itr).diff;
        int oldx1=(*itr).x1;
        int oldx2=(*itr).x2;
        int oldy1=(*itr).y1;
        int oldy2=(*itr).y2;
        node n1;
        n1.diff=d;
        n1.x1=oldx1;
        n1.x2=oldx2;
        n1.y1=oldy1;
        n1.y2=oldy2;
        ms.erase(n1);
        if(findleader(n1)!=findleader(n2)){
            combine(n1,n2);
            totalsize++;
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<4;k++){
                int newx=i+dx[k],newy=j+dy[k];
                if(bound(newx,newy)){
                    node n;
                    n.x1=i; n.y1=j; n.x2=newx; n.y2=newy; n.diff=abs(matrix[i][j]-matrix[newx][newy]);
                    mset.insert(n);
                }
            }
        }
    }
}
