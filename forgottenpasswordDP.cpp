#include <bits/stdc++.h>
using namespace std;
int l,n;
string s,dictionary[1001],dp[1001],ans;
int main(){
    cin >> l >> n;
    cin >> s;
    for(int i=0;i<n;i++){
        cin >> dictionary[i];
    }
    sort(dictionary,dictionary+n);
    for(int i=l-1;i>=0;i--){
        for(int j=0;j<n;j++){
            string temp=dictionary[j];
            int length=temp.length();
            if(i+length<=l){
                if(dp[i+length]!="-1"){
                    bool works=true;
                    for(int k=0;k<length;k++){
                        if(s.substr(k+i,1)=="?"||s.substr(k+i,1)==temp.substr(k,1)) works=true;
                        else{
                            works=false;
                            break;
                        }
                    }
                    if(works==true){
                        dp[i]=temp;
                        break;
                    }
                }
            }
            if(j==n-1){
                dp[i]="-1";
            }
        }
    }
    for(int i=0;i<l;i++) cout << dp[i] << " ";
    int current=0;
    while(current<l){
        ans+=dp[current];
        current+=dp[current].length();
    }
    cout << ans;
}
