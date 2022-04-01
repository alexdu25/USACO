#include <iostream>//maximum height of stack is answer
#include <bits/stdc++.h>
#include <stack>
using namespace std;
int lastoccurrence[100001],n,ans,firstoccurrence[100001],input[100001];
stack<int> s;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> input[i];
        if(firstoccurrence[input[i]]==0){
            firstoccurrence[input[i]]=i;
        }
        lastoccurrence[input[i]]=i;
    }
    for(int i=0;i<n;i++){
        int x=input[i];
        int temp=s.size();
        ans=max(ans,temp);
        //cout << "x: " << x << endl;
        if(x==0){
            if(!s.empty()){
                cout << "-1";
                return 0;
            }
            //cout << "done" << endl;
        }
        else{
            //cout << "done1" << endl;
            if(firstoccurrence[x]==i){
                //cout << "first occurrence of " << x << endl;
                s.push(x);
                int temp=s.size();
                ans=max(ans,temp);
                if(lastoccurrence[x]==i){
                    s.pop();
                }
            }
            else if(s.empty()==false){
                if(s.top()!=x){
                    cout << "-1";
                    return 0;
                }
                if(s.top()==x&&lastoccurrence[x]==i){
                    int temp=s.size();
                    ans=max(ans,temp);
                    s.pop();
                    //cout << "last occurrence of " << x << " pop" << endl;
                }
            }
        }
    }
    if(s.empty()){
        cout << ans;
        return 0;
    }
    cout << "-1";
}
