#include <bits/stdc++.h>
using namespace std;
int n,dist[2001],input[2001],ans;
bool visited[2001];
typedef pair<int,int> p;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    priority_queue<p,vector<p>,greater<p> > pq;
    int dist[n];
    bool visited[n];
    for(int i=0;i<n;i++){
        dist[i]=1000000000;
        visited[i]=false;
    }
    dist[0]=0;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        int idx=pq.top().second;
        pq.pop();
        if(visited[idx]==false){
            visited[idx]=true;
            for(int i=0;i<n;i++){//from idx to i
                int length=0-(input[idx] ^ input[i]);
                if(visited[i]==false&&(dist[i]>length)){
                    dist[i]=length;
                    pq.push(make_pair(dist[i],i));
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        ans+=dist[i];
    }
    cout << abs(ans);
}
