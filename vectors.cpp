#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a,int b){
    return a>b;
}
int main(){
    vector<int> v;
    for(int i=0;i<11;i++){
        v.push_back(i);
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
    int index = 0;
    if(v[10]==0){
        cout << "true" << endl;
    }
    v.erase(v.begin()+index);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
}
