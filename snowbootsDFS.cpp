#include <iostream>
#include <queue>
using namespace std;
int t,b,a,c,ans=1000000000;
int tiledepth[251];
int bootdepth[251];
int bootlength[251];
bool visited[251];
bool visited2[251];
int main(){
    fin >> t >> b;
    for(int i=1;i<=t;i++){
        cin >> tiledepth[i];
    }
    for(int i=1;i<=b;i++){
        cin >> bootdepth[i] >> bootlength[i];
    }
    queue<int> index;//index of current tile
    queue<int> boot;//index of current boot
    queue<int> counter;//boots switched
    boot.push(1);
    index.push(1);
    counter.push(0);
    while(!boot.empty()){
        int temp1=boot.front();
        int temp2=index.front();
        int temp3=counter.front();
        if(index.front()<t){
            for(int j=1;j<=bootlength[temp1];j++){//move all possible spaces
                if( (visited[temp2+j]==false) && ((temp2+j)<=t) && ((tiledepth[temp2+j])<=bootdepth[temp1]) ){
                    visited[temp2+j]=true;
                    boot.push(temp1);
                    index.push(temp2+j);
                    counter.push(temp3);
                }
            }
        }
        if(index.front()<t){//cycle
            for(int i=1;i<=b;i++){
                if(bootdepth[temp1+i]>=tiledepth[temp1]&&visited2[temp1+i]==false){
                    visited2[temp1+i]=true;
                    boot.push(temp1+1);
                    counter.push(temp3+1);
                    index.push(temp2);
                }
            }
        }
        if(index.front()==t){
            ans=min(ans,counter.front());
        }
        boot.pop();
        counter.pop();
        index.pop();
    }
    cout << ans;
}
