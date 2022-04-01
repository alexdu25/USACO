#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin ("lemonade.in");
ofstream fout ("lemonade.out");
int n,t=0,ans,lb;
vector<int> v;
bool comp(int a,int b){
    return a>b;
}
int main(){
    fin >> n;
    for(int i=0;i<n;i++){
        int x;
        fin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<n;){
        if(v[0]<t){
            break;
        }
        ans++;
        v.erase(v.begin()+0);
        t++;
    }
    fout << ans;
}

