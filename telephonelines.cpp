#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n,p,k,adjmatrix[1000][1000],a,b,c,dist[1000],ans=1000000000;
bool visited[1000];
int main(){
    cin >> n >> p >> k;
    for(int i=1;i<=n;i++){
        dist[i]=1000000000;
        for(int j=1;j<=n;j++){
            adjmatrix[i][j]=1000000000;
        }
    }
    for(int i=0;i<p;i++){
        cin >> a >> b >> c;
        adjmatrix[a][b]=c;
        adjmatrix[b][a]=c;
    }
    dist[1]=0;
    for(int i=1;i<=n;i++){
        int minindex=-1,mind=1000000000;
        for(int j=1;j<=n;j++){
            if(dist[j]<mind&&visited[j]==false){
                mind=dist[j];
                minindex=j;
            }
        }
        visited[minindex]=true;
        for(int j=1;j<=n;j++){
            if(visited[j]==false&&minindex!=-1){
                dist[j]=min(dist[j],adjmatrix[minindex][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]>1000000000){
            dist[i]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    sort(dist,dist+n);
    cout << dist[n-k-1];
}

