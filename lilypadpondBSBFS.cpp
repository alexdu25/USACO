#include <bits/stdc++.h>
using namespace std;
int r,c,input[31][31],xmove[8]={1,1,-1,-1,2,2,-2,-2},ymove[8]={2,-2,2,-2,1,-1,1,-1},startx,starty,n;
bool visited[31][31];
bool bound(int x1,int y1){
    if(x1<0||y1<0||x1>=r||y1>=c) return false;
    if(input[x1][y1]==2) return false;
    else return true;
}
bool possible(int maxlily){
    queue<int> x,y,lily;
    int counter=0;
    x.push(startx);
    y.push(starty);
    lily.push(0);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            visited[i][j]=false;
        }
    }
    visited[startx][starty]=true;
    while(!x.empty()){
        int xtop=x.front(),ytop=y.front(),lilytop=lily.front();
        x.pop(); y.pop(); lily.pop();
        for(int i=0;i<8;i++){
            int newx=xtop+xmove[i];
            int newy=ytop+ymove[i];
            if(bound(newx,newy)){
                if(visited[newx][newy]==false){
                    //cout << "newx: " << newx << " newy: " << newy << endl;
                    if(input[newx][newy]==1){
                        x.push(newx);
                        y.push(newy);
                        lily.push(lilytop);
                        visited[newx][newy]=true;
                    }
                    else if(input[newx][newy]==4){
                        if(lilytop<=maxlily){
                            counter++;
                        }
                    }
                    else if(input[newx][newy]==0){
                        lily.push(lilytop+1);
                        x.push(newx);
                        y.push(newy);
                        visited[newx][newy]=true;
                    }
                }
            }
        }
    }
    if(counter>=1){
        n=counter;
        return true;
    }
    return false;
}
int binarysearch(int lower,int upper){
    while(lower!=upper){
        if(lower==upper-1){
            if(possible(lower)==true){
                return lower;
            }
            else{
                if(upper==1000){
                    return -1;
                }
                return upper;
            }
        }
        int newbound=((upper+lower+1)/2);
        if(possible(newbound)==true){
            return binarysearch(lower,newbound);
        }
        if(possible(newbound)==false){
            return binarysearch(newbound,upper);
        }
    }
}
int main(){
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> input[i][j];
            if(input[i][j]==3){
                startx=i; starty=j;
            }
        }
    }
    int x=binarysearch(0,1000);
    if(x==1000){
        cout << "-1" << endl;
    }
    else{
        cout << x << endl;
        cout << n << endl;
    }
}
