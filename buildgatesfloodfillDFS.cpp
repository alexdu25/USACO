#include <iostream>
using namespace std;
int minx=1000000,miny=1000000,maxx,maxy;
bool a[4001][4001];
void floodfill(int x,int y){
    if(a[x][y]==1||x<minx-1||y<miny-1||x>maxx+1||y>maxy+1){
        return;
    }
    a[x][y]=1;
    floodfill(x+1,y);
    floodfill(x-1,y);
    floodfill(x,y+1);
    floodfill(x,y-1);
}
int main(){
    string s;
    int length,x=2000,y=2000,ans=0;
    cin >> length >> s;
    for(int i=0;i<length;i++){
        if(s[i]=='N'){
            a[x-1][y]=1;
            a[x-2][y]=1;
            x-=2;
        }
        else if(s[i]=='E'){
            a[x][y+1]=1;
            a[x][y+2]=1;
            y+=2;
        }
        else if(s[i]=='S'){
            a[x+1][y]=1;
            a[x+2][y]=1;
            x+=2;
        }
        else if(s[i]=='W'){
            a[x][y-1]=1;
            a[x][y-2]=1;
            y-=2;
        }
        maxy=max(y,maxy);
        maxx=max(x,maxx);
        miny=min(y,miny);
        minx=min(x,minx);
    }
    for(int i=minx-1;i<maxx+1;i++){
        for(int j=miny-1;j<maxy+1;j++){
            if(a[i][j]==0){
                floodfill(i,j);
                ans++;
            }
        }
    }
    cout << ans-1;
}
