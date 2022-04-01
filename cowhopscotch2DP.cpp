#include <bits/stdc++.h>
using namespace std;
map<int,int> m[251];
int r,c,maxval,matrix[251][251],psum[251];
int main(){
    cin >> r >> c >> maxval;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=0;i<251;i++){
        for(int j=1;j<=maxval;j++){
            //m[i].insert(make_pair(j,0));
            m[i][j]=0;
        }
    }
    m[0][0]=1;
    psum[0]=1;
    for(int i=1;i<r;i++){
        for(int j=c-1;j>=0;j--){
            int counter=0;
            int x=matrix[i][j];
            for(int k=1;k<j;k++){
                counter+=psum[k];
                counter-=m[k][x];
            }
            psum[j]+=counter;
            m[i][x]++;
        }
    }
    cout << psum[c-1];
}
