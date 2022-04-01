#include <iostream>
#include <queue>
using namespace std;
int n,wellcost[301],a,b,c,connectcost[301][301],dist[301],ans;
bool visited[301];
typedef pair<int,int> p;
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> wellcost[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> connectcost[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        connectcost[0][i]=wellcost[i];
        connectcost[i][0]=wellcost[i];
    }
    priority_queue<p,vector<p>,greater<p> > pq;
    for(int i=0;i<=n;i++){
        dist[i]=1000000000;
    }
    dist[0]=0;
    pq.push(make_pair(1,0));
    while(!pq.empty()){
        int idx=pq.top().second;
        pq.pop();
        if(visited[idx]==false){
            visited[idx]=true;
            for(int i=0;i<=n;i++){
                int length=connectcost[idx][i];
                if(visited[i]==false&&(dist[i]>length)){
                    dist[i]=length;
                    pq.push(make_pair(dist[i],i));
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        ans+=dist[i];
    }
    cout << ans;
}
