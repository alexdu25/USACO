#include <iostream>
using namespace std;
int n,bales[20],temp,ans=1000000000;
bool visited[20];
void recurse3(int current,int sum2,int sum1){
    int counter=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            counter+=bales[i];
        }
    }
    int temp=max(counter,max(sum1,sum2));
    ans=min(ans,temp);
    temp=0;
    return;
}
void recurse2(int current,int sum2,int sum1){
    if(visited[current]==true){
        return;
    }
    for(int i=1;i<n-current;i++){
        visited[current]=true;
        recurse2(current+i,sum2+bales[current],sum1);//keep selecting
        visited[current]=false;
        recurse2(current+i,sum2,sum1);
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false&&i!=current){

            recurse3(i,sum2+bales[current],sum1);//select group 2
        }
    }
}
void recurse1(int current,int sum1){
    if(visited[current]==true){
        return;
    }
    for(int i=1;i<n-current;i++){
        visited[current]=true;
        recurse1(current+i,sum1+bales[current]);//keep selecting
        visited[current]=false;
        recurse1(current+i,sum1);
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false&&i!=current){
            for(int j=0;j<n;j++){
                if(visited[j]==true){
                    cout << bales[j] << ", ";
                }
            }
            recurse2(i,0,sum1+bales[current]);//select group 2
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> bales[i];
    }
    recurse1(0,0);
    cout << ans;
}
