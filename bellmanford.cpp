#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<pair<int,int> > adjlist[1000001];
int main(){
    cin >> n;
    for(int i=0;i<n;i++) dist[i]=1000000000;
    dist[start]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<adjlist[j].size();k++){
                if(dist[adjlist[j][k].first]>dist[j]+adjlist[j][k].second){
                    if(i>=n){
                        cout << "negative weight cycle" << endl;
                        return;
                    }
                    dist[adjlist[j][k].first]=dist[j]+adjlist[j][k].second;
                    ans=min(ans,dist[adjlist[j][k].first]);
                }
            }
        }
    }
    cout << abs(ans);
}
