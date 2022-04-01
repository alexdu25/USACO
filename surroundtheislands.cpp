#include <iostream>
#include <queue>
using namespace std;
int n,cost[501][501],adjmatrix[501][501],ans=1000000000;
bool visited[501];
int findcost(int from,int to){
    if(adjmatrix[from][to]==1){
        return 0;
    }
    else{
        return cost[from][to];
    }
}
int crossisland(int from,int to){
    queue<int> x;
    int counter=1;
    x.push(to);
    while(!x.empty()){
        for(int i=1;i<=n;i++){
            if(adjmatrix[x.front()][i]!=0&&visited[i]==false){
                visited[i]=true;
                x.push(i);
                counter++;
            }
        }
        x.pop();
    }
    return counter;
}
void recurse(int position,int totalcost,int numbervisited){
    if(numbervisited>n){
        return;
    }
    if(numbervisited==n){
        ans=min(ans,totalcost);
        return;
    }
    cout << "position: " << position << " totalcost: " << totalcost << " numbervisited: " << numbervisited << endl;
    for(int i=position;i<=position;i++){
        int minindex=-1,mincost=1000000000;
        for(int j=1;j<=n;j++){
            cout << "1" << endl;
            int tempcost=findcost(i,j);
            if(tempcost<mincost&&tempcost!=0&&visited[j]==false){
                cout << "2" << endl;
                minindex=j;
                mincost=tempcost;
            }
            else if(tempcost==0&&visited[j]==false){
                cout << "3" << endl;
                visited[j]=true;
                recurse(j,totalcost,numbervisited+1);
            }
        }
        if(minindex!=-1){
            cout << "4" << endl;
            visited[minindex]=true;
            int tempcounter = crossisland(position,minindex);
            cout << "cost from " << position << " to " << minindex << ": " << cost[position][minindex] << endl;
            recurse(position,totalcost+(cost[position][minindex]*2),numbervisited+tempcounter);
        }
    }
}
int main(){
    cin >> n;
    int a,b;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        adjmatrix[a][b]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> cost[i][j];
        }
    }
    visited[1]=true;
    recurse(1,0,1);
    cout << ans;
}
