#include <bits/stdc++.h>
using namespace std;
int h,n;
struct point{
    int x,y;
};
point input[10000];
vector<int> adjlist[10000];
bool comp(point a,point b){
    return a.x<b.x;
}
bool bfs(){
    queue<int> index;
}
bool dist(int x1,int y1,int x2,int y2){
    int dx=x2-x1,dy=y2-y1;
    dx=pow(dx,2); dy=pow(dy,2);
    if(dx+dy<=1000000) return true;
    return false;
}
void slidingwindow(){
    queue<int> x,y,index;
    x.push(input[0].x); y.push(input[0].y); index.push(0);
    while(!x.empty()){
        for(int i=index.front()+1;i<n;i++){//
            if(input[i].x-x.front()<=1000){
                if(dist(input[i].x,input[i].y,x.front(),y.front())==true){
                    adjlist[i].push_back(index.front());
                    adjlist[index.front()].push_back(i);
                    x.push(input[i].x); y.push(input[i].y); index.push(i);
                }
            }
            else break;
        }
        x.pop();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<adjlist[i].size();j++){
            cout << adjlist[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    cin >> h >> n;
    for(int i=0;i<n;i++){
        cin >> input[i].x >> input[i].y;
    }
    sort(input,input+n,comp);
    slidingwindow();

}
