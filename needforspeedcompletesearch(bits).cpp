#include <iostream>
using namespace std;
int main(){
    int f,m,n;
    cin >> f >> m >> n;
    int x=0,z=0,f2=f,m2=m;
    double a,matrix[n][2],ans=f/(double)m,parts[n],helper[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=0;i<(1 << n);i++){
        x=i;
        f=f2;
        m=m2;
        for(int j=0;j<n;j++){
            if(x%2>0){
                f+=matrix[j][0];
                m+=matrix[j][1];
                a=f/(double)m;
            }
            x=x/2;
        }
        if(a>ans){
            ans=a;
            z=i;
        }
    }
    if(z==0){
        cout << "NONE";
    }
    for(int i=0;i<n;i++){
        if (z&(1<<i)) {
            cout << i+1 <<endl;
        }
    }
}
