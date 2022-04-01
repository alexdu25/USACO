#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(const pair<int,int> &a,const pair<int,int> &b){
    return a.second < b.second;
}
int main(){
    vector< pair<int,int> > v;
    int j=10;
    for(int i=0;i<11;i++){
        v.push_back(make_pair(i,j));
        j--;
    }
    vector< pair<int,int> > v2 = v;
    sort(v2.begin(),v2.end());
    cout << endl;
    for(int i=0;i<v2.size();i++){
        cout << v2[i].first << " " << v2[i].second << endl;
    }
    sort(v.begin(),v.end(),comp);
    cout << endl;
    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
}
