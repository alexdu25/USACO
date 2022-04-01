#include <iostream>
#include <set>
using namespace std;
int n,s,e;
set< pair<int,int> > activelist;//first is cost, second is index
struct cow{
    int starttime,endtime,cost;
};
cow a[10000];
vector< pair< int,bool > > v[86399];//at time t, 2 variables - first is index, second is start/end bool
bool comp(cow a1,cow a2){
    return a1.starttime<a2.starttime;
}
int sweepline(int start,int last){
    for(int i=start+1;i<=last;i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j].second==false){
                activelist.erase(activelist.find(v[i][j].first));
            }
            else{
                activelist.insert(make_pair(activelist))
            }
        }
    }
}
int main(){
    cin >> n >> s >> e;
    for(int i=0;i<n;i++){
        cin >> a[i].starttime >> a[i].endtime >> a[i].cost;
    }
    sort(a,a+n,comp);
    for(int i=0;i<n;i++){
        int temps=a[i].starttime;
        int tempe=a[i].endtime;
        v[temps].push_back(make_pair(i,true));
        v[tempe].push_back(make_pair(i,false));
    }
    for(int i=0;i<n;i++){
        if(a[i].starttime<s){
            activelist.insert(make_pair(a[i].cost,i);
        }
    }
    cout << sweepline(s,e);
}
