#include <fstream>
#include <queue>
using namespace std;
ifstream fin ("where.in");
ofstream fout ("where.out");
int n,xmove[4]={1,-1,0,0},ymove[4]={0,0,1,-1},ans;
char input[100][100],temp[100][100];
void dfs(int x,int y,char c){
    if(x<0||y<0||x>=n||y>=n){
        return;
    }
    if(temp[x][y]!=c||temp[x][y]=='0'){
        return;
    }
    temp[x][y]='0';
    for(int i=0;i<4;i++){
        dfs(x+xmove[i],y+ymove[i],c);
    }
}
bool check(int x1,int y1,int x2,int y2){
    int visitedinsert=1,repeat1=0,repeat2=0;
    char c1='0',c2='0';
    bool isC1=false,isC2=false;
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            if(temp[i][j]!='0'){
                if(c1==temp[i][j]){
                    isC1=true;
                }
                if(c2==temp[i][j]){
                    isC2=true;
                }
                if(isC1==true&&isC2==true){
                    return false;
                }
                if(c1!=temp[i][j]&&c2!=temp[i][j]){
                    if(visitedinsert>=3){
                        return false;
                    }
                    if(visitedinsert==1) c1=temp[i][j];
                    if(visitedinsert==2) c2=temp[i][j];
                    visitedinsert++;
                }
                dfs(i,j,temp[i][j]);
            }
        }
    }
    if(isC1==true&&isC2==false&&visitedinsert==3){
        return true;
    }
    if(isC2==true&&isC1==false&&visitedinsert==3){
        return true;
    }
    return false;
}
int main(){
    string s;
    fin >> n;
    for(int i=0;i<n;i++){
        fin >> s;
        for(int j=0;j<n;j++){
            input[i][j]=s[j];
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            for(int k=i+1;k<n;k++){
                for(int l=j+1;l<n;l++){
                    for(int m=0;m<n;m++){
                        for(int o=0;o<n;o++){
                            temp[m][o]=input[m][o];
                        }
                    }
                    if(check(i,j,k,l)==true){//make sure ijkl don't include (i,j,k,l) again
                        ans++;
                        j++;
                        k++;
                        l++;
                    }
                }
            }
        }
    }
    fout << ans;
}
