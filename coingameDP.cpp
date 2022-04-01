#include <iostream>
using namespace std;
int n,a[2001],prefixsum[2001],stored[2001];
bool found[2001];
int dp(int position,int previous){
    //cout << "position: " << position << " previous: " << previous << endl;
    if(position==0){
        return 0;
    }
    if(found[position]==true){
        return stored[position];
    }
    int minsum=1000000000;
    for(int i=(n-position)+1;i<=min(previous*2+(n-position),n);i++){
        minsum=min(dp(n-i,i),minsum);
    }
    found[position]=true;
    stored[position]=prefixsum[position]-minsum;
    return prefixsum[position]-minsum;
}
int main(){
    int previous=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        prefixsum[i]=prefixsum[i-1]+a[i];
    }
    cout << dp(n,1);
}
