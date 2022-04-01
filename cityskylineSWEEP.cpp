#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int n,input[20001][2],w,ans;
int main(){
    cin >> n >> w;
    for(int i=0;i<n;i++) cin >> input[i][0] >> input[i][1];
    input[n][0]=0; input[n][1]=0;
    for(int i=0;i<n+1;i++){
        if(s.empty()){
            s.push(input[i][1]);
        }
        else{
            if(input[i][1]>s.top()){
                s.push(input[i][1]);
            }
            else if(input[i][1]<s.top()){
                while(!s.empty()){
                    if(s.top()>input[i][1]){
                        s.pop();
                        if(s.empty()==true) s.push(input[i][1]);
                        ans++;
                    }
                    else{
                        if(s.top()<input[i][1]) s.push(input[i][1]);
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
}
