#include <iostream>
using namespace std;
int main(){
    int n,x,ans=0;
    cin >> n;
    pair <int,int> bales[n];
    for(int i=0;i<n;i++){
        cin >> bales[i].first >> bales[i].second;
    }
    sort(bales,bales+n);
    for(int i=0;i< (1<<n);i++){
        x=i;
        int temp2=1000000;
        bool good = true;
        for(int j=n-1;j>=0;j--){
            if(x%2>0){
                if(bales[j].second>temp2){
                    good=false;
                }
                temp2=bales[j].second;
            }
            x /= 2;
        }
        if(good){
            ans=max(ans,__builtin_popcount(i));
        }
    }
    cout << ans;
    /*
    int n,x,counter,ans=0;
    cin >> n;
    int temp2;
    pair <int,int> bales[n];
    for(int i=0;i<n;i++){
        cin >> bales[i].first >> bales[i].second;
    }
    sort(bales,bales+n);
    for(int i=(1<<n)-1;i>=0;i--){
        x=i;
        counter=0;
        temp2=1000000;
        for(int j=n-1;j>=0;j--){
            if(x%2>0){
                if(bales[j].second<temp2){
                    temp2=bales[j].second;
                    counter++;
                }
            }
            x=x/2;
        }
        ans=max(ans,counter);
    }
    cout << ans;
    */
}
