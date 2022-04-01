#include <iostream>
using namespace std;
int a[10000],n,m,prev,dist[101][101];
void fw(int z){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);
            }
        }
    }
}
int main(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dist[i][j]=1000000010;
        }
    }
    int ans=0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> dist[i][j];
        }
    }
    fw(0);
    prev=a[0];
    for(int i=1;i<m;i++){
        ans+=dist[prev][a[i]];
        prev=a[i];
    }
    cout << ans;
}
