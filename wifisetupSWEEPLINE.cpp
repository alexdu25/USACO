#include <bits/stdc++.h>
using namespace std;
int n,a,b,input[2001];
int main(){
    cin >> n >> a >> b;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    sort(input,input+n);
    int newbase=2,length=0;

    for(int i=1;i<n;i++){
        int dist=input[i]-input[i-1];
        if(dist*b<2*a){
            length+=dist;
        }
        else{
            newbase+=2;
        }
    }
    int ans=newbase*a+length*b;
    cout << ans/2;
    if(ans%2==1){
        cout << ".5";
    }
}
