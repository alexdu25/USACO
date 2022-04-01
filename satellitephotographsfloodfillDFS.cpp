#include <iostream>
using namespace std;
char matrix[1000][80];
int r,c,counter;
void floodfill(int x,int y){
    if(x<0||y<0||x>=r||y>=c||matrix[x][y]=='.'){
        return;
    }
    matrix[x][y]='.';
    counter++;
    floodfill(x+1,y);
    floodfill(x-1,y);
    floodfill(x,y+1);
    floodfill(x,y-1);
int main(){
    int x,ans=0;
    cin >> c >> r;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]=='*'){
                counter=0;
                floodfill(i,j);
                ans=max(ans,counter);
            }
        }
    }
    cout << ans;
}
