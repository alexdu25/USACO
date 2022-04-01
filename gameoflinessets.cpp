#include <iostream>
#include <set>
using namespace std;
int main(){
    double z1,z2,z3=0;
    set<double> s;
    int n;
    cin >> n;
    struct point{
        int x,y;
    };
    point a[n];
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            z1=a[j].x-a[i].x;
            z2=a[j].y-a[i].y;
            if(z1!=0){
                s.insert(z2/z1);
            }
            else{
                z3=1;
            }
        }
    }
    if(z3==1){
        cout << s.size() + 1;
    }
    else{
        cout << s.size();
    }
}
