#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int, greater<int> > s;
int n,divisor,a[2000],ans,z;
int dp[1000],dp2[1000];
/*dp(a-b)
take it: dp(a-1,b-r);
leave it: dp(a-1,b);
1,2,1,2;f=3;
dp(1,0)=1; first index = 1   dp(2,0)=2; second index = 2    dp(3,0)=3; third index = 1
dp(1,1)=1;                   dp(2,1)=1;                     dp(3,1)=3;
dp(1,2)=0;                   dp(2,2)=1;   (2,1) + (2,2)     dp(3,2)=2;
*/
int main(){
    cin >> n >> divisor;
    for(int i=1;i<=n;i++){
        cin >> z;
        a[i]=z%divisor;
    }
    dp[0]=1;
    for(int i=1;i<divisor;i++){
        if(a[1]==i){
            dp[i]=1;
        }
        else{
            dp[i]=0;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<divisor;j++){
            dp2[j]=dp[j];
        }
        for(int j=0;j<divisor;j++){//possible sums
            int j2=(j-a[i])%divisor;
            if(j2<0){
                j2+=divisor;
            }
            dp[j]=(dp2[j]+dp2[j2])%100000000;//j2 = (j-a[j]+(1000000000*divisor))%divisor
        }
    }
    cout << dp[0]-1;
}
