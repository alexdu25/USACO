#include <iostream>
#include <algorithm>
using namespace std;
int n;
double a,b,input[2000],dp[2000];//a + br
double circle(int first,int last){
    double r=((input[last]-input[first])/2);
    return a+(b*r);
}
int main(){
    cin >> n >> a >> b;
    for(int i=0;i<n;i++){
        cin >> input[i];
        dp[i]=1e9;
    }
    sort(input,input+n);
    dp[0]=a;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            dp[i]=min(dp[i],dp[j]+circle(j+1,i));
        }
    }
    cout << dp[n-1];
}
