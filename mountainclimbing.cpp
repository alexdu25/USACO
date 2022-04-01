#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
bool visited[25000];
struct t{
    int index,uptime,downtime;
};
bool comp(t a1,t a2){
    return a1.downtime > a2.downtime||(a1.downtime==a2.downtime&&a1.uptime<a2.downtime);
}
bool comp1(t a1,t a2){
    return a1.uptime < a2.uptime||(a1.uptime==a2.uptime&&a1.downtime>a2.downtime);
}
t a[25000];
int main(){
    int ans=0,upsum=0,downsum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].uptime >> a[i].downtime;
        a[i].index=i;
    }
    sort(a,a+n,comp1);
    vector<int> line;
    for(int i=0;i<n;i++){
        if(a[i].downtime>a[i].uptime){
            upsum+=a[i].uptime;
            downsum-=a[i].uptime;
            line.push_back(a[i].downtime);
            visited[a[i].index]=true;
            break;
        }
    }
    if(upsum==0){
        upsum+=a[0].uptime;
        downsum-=a[0].uptime;
        visited[a[0].index]=true;
    }
    sort(a,a+n,comp);
    int total=0;
    for(int i=0;i<n;i++){
        if(visited[a[i].index]==false){
            upsum+=a[i].uptime;
            if(upsum>total){
                total=upsum+a[i].downtime;
            }
            else{
                total+=downsum;
            }
        }
    }
    cout << total << endl;
}
