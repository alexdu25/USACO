#include <iostream>
using namespace std;
int matrix[10][10],n,minx,miny,maxx,maxy;
bool ans[11];
bool visited[10][10];
void dfs(int currentx,int currenty,int number){
    if(currentx<0||currenty<0||currentx>=n||currenty>=n||visited[currentx][currenty]==true){
        return;
    }
    if(matrix[currentx][currenty]==number){
        cout << "currentx: " << currentx << " currenty: " << currenty << " number: " << number << endl;
        minx=min(minx,currentx);
        miny=min(miny,currenty);
        maxx=max(maxx,currentx);
        maxy=max(maxy,currenty);
        cout << "minx: " << minx << " miny: " << miny << " maxx: " << maxx << " maxy: " << maxy << endl;
        visited[currentx][currenty]=true;
        dfs(currentx+1,currenty,number);
        dfs(currentx-1,currenty,number);
        dfs(currentx,currenty+1,number);
        dfs(currentx,currenty-1,number);
    }
    else if(matrix[currentx][currenty]!=number&&(currentx>=minx&&currentx<=maxx&&currenty>=miny&&currenty<=maxy)){
        //intercepting
        cout << "3 ";
        ans[matrix[currentx][currenty]]=true;
    }
    else{
        return;
    }
}
int main(){
    int answer=0;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]!=0&&visited[i][j]!=true){
                minx=100;
                maxx=-1;
                miny=100;
                maxy=-1;
                cout << "1 ";
                dfs(i,j,matrix[i][j]);
            }
        }
    }
    for(int i=1;i<11;i++){
        if(ans[i]==true){
            answer++;
            cout << "done" << endl;
        }
    }
    cout << answer;
}
