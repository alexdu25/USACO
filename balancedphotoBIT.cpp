#include <bits/stdc++.h>
using namespace std;
int n,fenwick[1000001];//BIT needs to be 1-index;
pair<int,int> input[1000001];
void update(int index,int value){
    while(index<=n){
        fenwick[index]+=value;
        index+=index&-index;
    }
}
int query(int x){//psum from 1-q
    int ret=0;
    while(x>0){
        ret+=fenwick[x];
        x-=x&-x;
    }
    return ret;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> input[i].first;
        input[i].second=i;
    }
    for(int i=1;i<=n;i++){
        update(i,input[i-1]);
    }

}

