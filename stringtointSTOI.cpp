#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b,c,d,e;
    cin >> a >> b;
    int x,y,z,array2[a.length()],array3[b.length()*2];
    for(int i=0;i<a.length();i++){
        c=a;
        if(c[i]=='0'){
            c[i]='1';
        }
        else{
            c[i]='0';
        }
        x=stoi(c,nullptr,2);
        array2[i]=x;
    }
    for(int i=0;i<b.length();i++){
        d=b;
        e=b;
        if(d[i]=='0'){
            d[i]='1';
            e[i]='2';
        }
        else if(d[i]=='1'){
            d[i]='0';
            e[i]='2';
        }
        else if(d[i]=='2'){
            d[i]='0';
            e[i]='1';
        }
        y=stoi(d,nullptr,3);
        z=stoi(e,nullptr,3);
        array3[i]=y;
        array3[i+b.length()]=z;
    }
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length()*2;j++){
            if(array2[i]==array3[j]){
                cout << array2[i];
                return 0;
            }
        }
    }
}
