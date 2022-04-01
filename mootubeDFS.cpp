#include <iostream>
#include <algorithm>
using namespace std;
int a,b,counter;
struct point{
    int x,y,r;
};
point p[10000];
bool used[5001];
int start[5002];
bool comp(point a,point b){
    return a.x<b.x;
}
void recurse(int current,int minimum){
    if(used[current]==1){
        return;
    }
    used[current]=1;
    counter++;
    for(int i=start[current];i<start[current+1];i++){
        if(p[i].r>=minimum){
            recurse(p[i].y,minimum);
        }
    }
}
int main(){
    cin >> a >> b;
    int m,s;
    for(int i=1;i<a*2-2;i+=2){
        cin >> p[i-1].x >> p[i-1].y >> p[i-1].r;
        p[i].x=p[i-1].y;
        p[i].y=p[i-1].x;
        p[i].r=p[i-1].r;
    }
    sort(p,p+a*2-2,comp);
    for(int i=1;i<=a;i++){
        for(int j=0;j<a*2-2;j++){
            if(p[j].x==i){
                start[i]=j;
                break;
            }

        }
    }
    start[a+1] = a*2-2;
    for(int i=0;i<b;i++){
        for(int j=1;j<=a;j++){
            used[j]=0;
        }
        cin >> m >> s;
        counter=0;
        recurse(s,m);
        cout << counter-1 << endl;
    }
}
