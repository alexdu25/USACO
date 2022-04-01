#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m,x,a1,b,c,d;
double dist[500];
bool visited[500];
struct pipe{
    vector<int> point;
    vector<int> latency;
    vector<int> capacity;
};
pipe a[500];
int main(){
    priority_queue< pair<int,int> > pq;
    cin >> n >> m >> x;
    for(int i=0;i<m;i++){
        cin >> a1 >> b >> c >> d;
        a[a1].point.push_back(b);
        a[a1].latency.push_back(c);
        a[a1].capacity.push_back(d);
        a[b].point.push_back(a1);
        a[b].latency.push_back(c);
        a[b].capacity.push_back(d);
    }
    for(int i=0;i<n;i++){
        dist[i]=1000000000;
    }
    dist[0]=0;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        //(a[j].latency[k]+x)/a[j].capacity[k];
        if(visited[pq.top().second]==false){
            visited[pq.top().second]=true;
            for(int j=0;j<a[pq.top().second].point.size();j++){
                cout << "size: " << a[pq.top().second].point.size() << endl;
                double length=(a[pq.top().second].latency[j]+x)/a[pq.top().second].capacity[j];
                int x2=a[pq.top().second].point[j];
                if(visited[x2]==false&&(dist[x2]>(double) dist[pq.top().second]+length)){
                    pq.push(make_pair(-dist[x2],x2));
                    dist[x2]=dist[pq.top().second]+length;
                }
            }
        }
        pq.pop();
    }
    cout << dist[n-1];
}
