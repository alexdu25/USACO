#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("art.in");
ofstream fout ("art.out");
int n,input[11][11],m[11][11],maxx,maxy,minx,miny;
bool ans[10],first[10];
void dfs(int x,int y,int color){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]==color){
                m[i][j]=-1;
                maxx=max(maxx,i);
                minx=min(minx,i);
                maxy=max(maxy,j);
                miny=min(miny,j);
            }
        }
    }
}
int main(){
    int s;
    fin >> n;
    for(int i=0;i<n;i++){
        fin >> s;
        for(int j=0;j<n;j++){
            int temp=s%10;
            s/=10;
            m[i][n-1-j]=temp;
            input[i][n-1-j]=temp;
            first[m[i][n-1-j]]=true;
        }
    }
    for(int i=0;i<10;i++){
        if(first[i]==false){
            ans[i]=true;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[i][j]!=0&&m[i][j]!=-1){
                maxx=-1;
                maxy=-1;
                minx=100;
                miny=100;
                dfs(i,j,m[i][j]);
                for(int k=minx;k<=maxx;k++){
                    for(int l=miny;l<=maxy;l++){
                        if(input[k][l]!=input[i][j]){
                            ans[input[k][l]]=true;
                        }
                    }
                }
            }
        }
    }
    int counter=0;
    for(int i=1;i<10;i++){
        if(ans[i]==false){
            counter++;
        }
    }
    fout << counter;
}
