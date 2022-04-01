#include <bits/stdc++.h>
using namespace std;
int n,dp[4][21][21][21][21],dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};//direction(0,1,2,3),x1,y1,x2,y2
char mat[21][21];
int bound(int dir,int x1,int y1,int x2,int y2){//0 means both don't work or visited, 1 means only first set doesn't work, 2 means only second set doesn't work, 3 means both work
    if((x1<0||y1<0||x1>=n||y1>=n)&&(x2<0||y2<0||x2>=n||y2>=n)) return 0;
    if(x1<0||y1<0||x1>=n||y1>=n) return 1;
    if(x2<0||y2<0||x2>=n||y2>=n) return 2;
    if(mat[x1][y1]=='H'&&mat[x2][y2]=='H') return 0;
    if(mat[x1][y1]=='H') return 1;
    if(mat[x2][y2]=='H') return 2;
    return 3;
}
void bfs(){
    queue<int> direction1,x1,y1,x2,y2;//direction2=direction1+1;
    direction1.push(0); x1.push(n-1); y1.push(0); x2.push(n-1); y2.push(0);
    dp[0][0][0][0][0]=1;
    while(!x1.empty()){
        int x1top=x1.front(),x2top=x2.front(),y1top=y1.front(),y2top=y2.front(),dir1=direction1.front(),dir2=dir1+1;
        x1.pop(); x2.pop(); y1.pop(); y2.pop(); direction1.pop();
        if(x1top==0&&y1top==n-1&&x2top==0&&y2top==n-1){
            cout << "solved" << endl;
            cout << dp[dir1][x1top][y1top][x2top][y2top]; return;
        }
        int newx1=-1,newy1=-1,newx2=-1,newy2=-1;
        if(x1top==0&&y1top==n-1){
            newx1=x1top,newy1=y1top,newx2=x2top+dx[dir2],newy2=y2top+dy[dir2];
        }
        else if(x2top==0&&y2top==n-1){
            newx1=x1top+dx[dir1],newy1=y1top+dy[dir1],newx2=x2top,newy2=y2top;
        }
        else{
            newx1=x1top+dx[dir1],newy1=y1top+dy[dir1],newx2=x2top+dx[dir2],newy2=y2top+dy[dir2];
        }
        int tempx=bound(dir1,newx1,newy1,newx2,newy2);
        cout << "bound: " << tempx << endl;
        if(tempx==0){
            int donothinghere;
        }
        else if(tempx==1){//only move 2
            if(dp[dir1][x1top][y1top][newx2][newy2]==0){
                direction1.push(dir1); x1.push(x1top); y1.push(y1top); x2.push(newx2); y2.push(newy2);
                dp[dir1][x1top][y1top][newx2][newy2]=dp[dir1][x1top][y1top][x2top][y2top]+1;
                //cout << "push: " << dir1 << " " << x1top << " " <<  y1top << " " << newx2 << " " << newy2 << endl;
                cout << "moves: " << dp[dir1][x1top][y1top][x2top][y2top]+1;
            }
        }
        else if(tempx==2){
            if(dp[dir1][newx1][newy1][x2top][y2top]==0){
                direction1.push(dir1); x1.push(newx1); y1.push(newy1); x2.push(x2top); y2.push(y2top);
                dp[dir1][newx1][newy1][x2top][y2top]=dp[dir1][x1top][y1top][x2top][y2top]+1;
                //cout << "push: " << dir1 << " " << newx1 << " " << newy1 << " " << x2top << " " << y2top << endl;
                cout << "moves: " << dp[dir1][x1top][y1top][x2top][y2top]+1;
            }
        }
        else if(tempx==3){//both work
            if(dp[dir1][newx1][newy1][newx2][newy2]==0){
                direction1.push(dir1); x1.push(newx1); y1.push(newy1); x2.push(newx1); y2.push(newy1);
                dp[dir1][newx1][newy1][newx2][newy2]=dp[dir1][x1top][y1top][x2top][y2top]+1;
                //cout << "push: " << dir1 << " " << newx1 << " " << newy1 << " " << newx2 << " " << newy2 << endl;
                cout << "moves: " << dp[dir1][x1top][y1top][x2top][y2top]+1;
            }
        }

        int tempdir1=(dir1+1)%4;
        if(dp[tempdir1][x1top][y1top][x2top][y2top]==0){
            x1.push(x1top); direction1.push(tempdir1); x2.push(x2top); y1.push(y1top); y2.push(y2top);
            dp[tempdir1][x1top][y1top][x2top][y2top]=dp[dir1][x1top][y1top][x2top][y2top]+1;
            //cout << "push dir: " << tempdir1 << " " << x1top << " " << y1top << " " << x2top << " " << y2top << endl;
            cout << "moves: " << dp[dir1][x1top][y1top][x2top][y2top]+1;
        }
        tempdir1=(dir1+3)%4;
        if(dp[tempdir1][x1top][y1top][x2top][y2top]==0){
            x1.push(x1top); direction1.push(tempdir1); x2.push(x2top); y1.push(y1top); y2.push(y2top);
            dp[tempdir1][x1top][y1top][x2top][y2top]=dp[dir1][x1top][y1top][x2top][y2top]+1;
            //cout << "push dir: " << tempdir1 << " " << x1top << " " << y1top << " " << x2top << " " << y2top << endl;
            cout << "moves: " << dp[dir1][x1top][y1top][x2top][y2top]+1;
        }
    }
    cout << "empty" << endl;
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }
    bfs();
}
