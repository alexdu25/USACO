#include <iostream>
using namespace std;
int endpoint[1001],choice[1001],n,m,repeat,input[1001][3],instructions[501],lastseen[1001];
int main(){
    cin >> n >> m >> repeat;
    char c;
    for(int i=1;i<=n;i++){
        cin >> input[i][1] >> input[i][2];
    }
    for(int i=1;i<=m;i++){
        cin >> c;
        if(c=='L'){
            instructions[i]=1;
        }
        else{
            instructions[i]=2;
        }
    }
    int lastindex=-1,currentindex;
    for(int k=1;;k++){
        int trace=1;
        for(int i=1;i<=m;i++){
            if(instructions[i]==1){
                trace=input[trace][1];
            }
            else{
                trace=input[trace][2];
            }
        }
        if(lastseen[trace]!=0){
            lastindex=lastseen[trace];
            currentindex=trace;
            break;
        }
        repeat--;
        endpoint[k]=trace;//check if this endpoint has occurred before
        lastseen[trace]=k;
    }
    int remainder=repeat%(currentindex-lastindex);//if remainder==0, it's the last one after running currentindex-lastindex
    int start=endpoint[lastindex-1];
    if(remainder==0){
        cout << endpoint[currentindex-1];
        return 0;
    }
    for(int i=1;i<=remainder;i++){
        for(int j=1;j<=m;j++){
            if(instructions[j]==1){
                start=input[start][1];
            }
            else{
                start=input[start][2];
            }
        }
    }
    cout << start << endl;
}
