#include <iostream>
#include <algorithm>
using namespace std;
struct event{
    int starttime,duration,endtime;
};
bool comp(event a,event b){
    return a.endtime<b.endtime;
}
int n,t;
event a[10000];
int main(){
    int ans=1,current=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].starttime >> a[i].duration;
        a[i].endtime=a[i].starttime+a[i].duration;
    }
    sort(a,a+n,comp);
    t=a[0].endtime;
    while(t<a[n-1].endtime){
        int z=0;
        for(int i=current+1;i<n;i++){
            if(a[i].starttime>=t){
                current=i;
                z=1;
                break;
            }
        }
        if(z==0){
            break;
        }
        t=a[current].endtime;
        ans++;
    }
    cout << ans;
}
