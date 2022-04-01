#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m,party,a,b,c,ans;
vector<pair<int,int> > adjlist[1001];
typedef pair<int,int> p;
void dijstra(int start){
    int dist[n],dist2[n];
    bool visited[n],visited2[n];
    for(int i=0;i<n;i++){
        dist[i]=1000000000;
        dist2[i]=1000000000;
        visited[i]=false;
        visited2[i]=false;
    }
    dist[start]=0;
    dist2[party]=0;
    priority_queue<p,vector<p>,greater<p> > pq;
    priority_queue<p,vector<p>,greater<p> > pq2;
    pq.push(make_pair(0,start));
    pq.push(make_pair(0,party));
    cout << "start: " << start << endl;
    while(!pq.empty()){
        int idx=pq.top().second;
        pq.pop();
        if(visited[idx]==false){
            visited[idx]=true;
            for(int i=0;i<adjlist[idx].size();i++){
                int x=adjlist[idx][i].first;
                int length=adjlist[idx][i].second;
                cout << "idx: l" << idx << endl;
                if(visited[x]==false&&(dist[x]>dist[idx]+length)){
                    cout << "idx: " << idx << " x: " << x << " length: " << length << endl;
                    dist[x]=dist[idx]+length;
                    pq.push(make_pair(dist[x],x));
                }
            }
        }
    }
    cout << "dist[party]: " << dist[party] << endl;
    while(!pq2.empty()){
        int idx=pq2.top().second;
        pq2.pop();
        if(visited2[idx]==false){
            visited2[idx]=true;
            for(int i=0;i<adjlist[idx].size();i++){
                int x=adjlist[idx][i].first;
                int length=adjlist[idx][i].second;
                if(visited2[x]==false&&(dist2[x]>dist2[idx]+length)){
                    dist2[x]=dist2[idx]+length;
                    pq2.push(make_pair(dist2[x],x));
                }
            }
        }
    }
    int temp=dist[party]+dist2[start];
    if(temp>ans&&temp<1000000000){
        ans=temp;
    }
}
int main(){
    cin >> n >> m >> party;
    party--;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        a--; b--;
        adjlist[a].push_back(make_pair(b,c));
    }
    for(int i=0;i<n;i++){//starting barn/cow
        if(i!=party){
            dijstra(i);
        }
    }
    cout << ans;
}
