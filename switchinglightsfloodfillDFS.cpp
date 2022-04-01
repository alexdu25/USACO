#include <iostream>
using namespace std;
int size,command[20001][5],n;
bool reachable[101][101],visited[101][101],lit[101][101];
void floodfill(int x,int y){
    if(reachable[x][y]==0||lit[x][y]==0||visited[x][y]==1||x<1||y<1||x>size||y>size){
        return;
    }
    visited[x][y]=1;
    reachable[x+1][y]=1;
    reachable[x-1][y]=1;
    reachable[x][y-1]=1;
    reachable[x][y+1]=1;
    floodfill(x, y+1);
    floodfill(x+1, y);
    floodfill(x-1, y);
    floodfill(x, y-1);
    for(int i=1;i<=n;i++){
        if(command[i][1]==x&&command[i][2]==y){
            lit[command[i][3]][command[i][4]]=1;
            floodfill(command[i][3],command[i][4]);
        }
    }

}
int main(){
    int ans=0;
    cin >> size >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++){
            cin >> command[i][j];
        }
    }
    lit[1][1]=1;
    reachable[1][1]=1;
    floodfill(1,1);
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            if(lit[i][j]==1){
                ans++;
            }
        }
    }
    cout << ans;
}
