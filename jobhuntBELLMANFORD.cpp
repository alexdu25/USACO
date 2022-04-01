#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int maxpay,paths,cities,flights,start,ans,a,b,c,dist[221];
vector<pair<int,int> > adjlist[221];
void bellmanford(void){
    for(int i=0;i<paths;i++) dist[i]=1000000000;
    dist[start]=-maxpay;
    ans=-maxpay;
    for(int i=0;i<=cities+1;i++){
        for(int j=0;j<cities;j++){
            for(int k=0;k<adjlist[j].size();k++){
                if(dist[adjlist[j][k].first]>dist[j]+adjlist[j][k].second){
                    if(i>=cities){
                        cout << "-1" << endl;
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
int main(){
    cin >> maxpay >> paths >> cities >> flights >> start;
    start--;
    for(int i=0;i<paths;i++){
        cin >> a >> b;
        a--;
        b--;
        adjlist[a].push_back(make_pair(b,-maxpay));
    }
    for(int i=0;i<flights;i++){
        cin >> a >> b >> c;
        a--;
        b--;
        adjlist[a].push_back(make_pair(b,c-maxpay));
    }
    bellmanford();
}
