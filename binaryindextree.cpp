#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,query,input[1000001],fenwick[1000001];//BIT needs to be 1-index;
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
    cin >> n >> q >> a;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    for(int i=1;i<=n;i++){
        update(i,input[i-1]);
    }
    for(int i=0;i<q;i++){
        cin >> b >> c;
        cout << query[c]-query[b] << endl;
    }
    for(int i=0;i<a;i++){
        cin >> b >> c;//update index b to c;
        update(b,c);
    }
}
