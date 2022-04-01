#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
ifstream fin ("convention2.in");
ofstream fout ("convention2.out");
int n,ans;
bool visited[100000];
vector< pair<int,int> > v;
struct cow{
    int number,arrival,time;
};
cow a[100000];
bool comp (cow a,cow b){
    return a.arrival < b.arrival;
}
bool comp2 (const pair<int,int> &a,const pair<int,int> &b){
    return a.second<b.second;
}
int lowerbound(int query,int lower,int upper){
    int newbound = (upper + lower + 1) / 2;
    while(lower!=upper){
        if(lower==upper-1){
            if(a[lower].arrival>=query){
                return lower;
            }
            else{
                return upper;
            }
        }
        if(a[newbound].arrival>=query){
            return lowerbound(query,lower,newbound);
        }
        else{
            return lowerbound(query,newbound,upper);
        }
    }
}
int main(){
    fin >> n;
    for(int i=0;i<n;i++){
        fin >> a[i].arrival >> a[i].time;
        a[i].number = i;
    }
    sort(a,a+n,comp);
    int currenttime=a[0].arrival;
    int currentindex=0;
    visited[0]=true;
    while(true){
        for(int i=lowerbound(currenttime,0,n);;i++){
            if(a[i].arrival>=currenttime&&a[i].arrival<=(currenttime+a[currentindex].time)){
                if(visited[i]==false){
                    visited[i]=true;
                    v.push_back(make_pair(i,a[i].number));
                }
            }
            else{
                break;
            }
        }
        if(v.size()>0){
            sort(v.begin(),v.end(),comp2);
        }
        currenttime+=a[currentindex].time;
        ans=max(ans,abs(currenttime-a[v[0].first].arrival));
        currentindex=v[0].first;
        if(currentindex==n-1){
            break;
        }
        if(v.size()>0){
            v.erase(v.begin()+0);
        }
        if(v.size()==0){
            for(int i=0;i<n;i++){
                if(visited[i]==false){
                    currentindex=i;
                    currenttime=a[i].arrival;
                    visited[i]=true;
                    break;
                }
            }
        }
    }
    fout << ans;
    fout.close();
}
