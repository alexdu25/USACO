#include <iostream>
using namespace std;
bool dp[1000001];
int n,query;
int maxdigit(int number){
    int maxd=0;
    while(number!=0){
        maxd=max(maxd,number%10);
        number=number/10;
    }
    return maxd;
}
int mindigit(int number){
    int mind=1000000000;
    while(number!=0){
        if(number%10!=0){
            mind=min(mind,number%10);
        }
        number=number/10;
    }
    return mind;
}
int main(){
    for(int i=1;i<10;i++){
        dp[i]=true;
    }
    dp[0]=false;
    dp[10]=false;
    for(int i=11;i<=1000000;i++){
        int minvalue=mindigit(i);
        int maxvalue=maxdigit(i);
        if(dp[i-maxvalue]==false||dp[i-minvalue]==false){
            dp[i]=true;
        }
        else{
            dp[i]=false;
        }
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> query;
        if(dp[query]==true){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
