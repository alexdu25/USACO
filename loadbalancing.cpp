#include <iostream>
#include <algorithm>
using namespace std;
struct point{
    int x,y;
};
point a[100],a2[100];
bool comp(point a,point b){
    return a.x<b.x;
}
bool comp2(point a,point b){
    return a.y<b.y;
}
int main(){
    int n,b,xline=2,yline=2,tempmax=0,ans=1000000,prev=1,prev2=1,z1=0,z2=0,c1=1,c2=0;
    cin >> n >> b;
    int helper[4];
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y;
        a2[i].x=a[i].x;
        a2[i].y=a[i].y;
    }
    sort(a,a+n,comp);
    sort(a2,a2+n,comp2);
    while(true){
        while(true){
            if(z1==n){
                c1=1;
                z1=0;
                break;
            }
            if(a2[z1].y!=prev){
                yline=(a2[z1].y+prev)/2;
                prev=a2[z1].y;
                z1++;
                break;
            }
            else{
                z1++;
            }
        }
        if(c1==1){
            while(true){
                if(a[z2].x!=prev2){
                    xline=(a[z2].x+prev2)/2;
                    prev2=a[z2].x;
                    z2++;
                    if(z2==n){
                        c2=1;
                        break;
                    }
                    break;
                }
                else{
                    z2++;
                }
                if(z2==n){
                    c2=1;
                    break;
                }
            }
            c1=0;
        }
        if(c2==1){
            break;
        }
        for(int i=0;i<4;i++){
            helper[i]=0;
        }
        for(int i=0;i<n;i++){
            if(a[i].x<xline&&a[i].y<yline){
                helper[0]++;
            }
            else if(a[i].x<xline&&a[i].y>yline){
                helper[1]++;
            }
            else if(a[i].x>xline&&a[i].y<yline){
                helper[2]++;
            }
            else if(a[i].x>xline&&a[i].y>yline){
                helper[3]++;
            }
        }
        for(int i=0;i<4;i++){
            tempmax=max(tempmax,helper[i]);
        }
        ans=min(ans,tempmax);
        tempmax=0;
    }
    cout << ans;
}
