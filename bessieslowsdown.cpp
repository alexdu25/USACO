#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
double n,currentt=0,position,tpointer,denom=1;
vector<double> t;
bool d[1001];
int main(){
    cin >> n;
    char c;
    int a;
    for(int i=0;i<n;i++){
        cin >> c >> a;
        if(c=='T'){
            t.push_back(a);
        }
        else{
            d[a]=true;
        }
    }
    sort(t.begin(),t.end());
    while(position<=1000){
        if(position<40){
            cout << "position: " << position << " currentt: " << currentt << endl;
        }
        if(d[(int)position]==true){
            denom++;
        }
        if(tpointer<t.size()){
            if(currentt+denom<t[tpointer]){
                currentt+=denom;
                position++;
            }
            else if(currentt+denom==t[tpointer]){
                int temp=t[tpointer]-currentt;
                currentt=t[tpointer];
                position+=denom*temp;
                denom++;
                tpointer++;
            }
            else if(currentt+denom<t[tpointer]){
                int temp=t[tpointer]-currentt;
                tpointer++;
                denom++;
                currentt=t[tpointer];
                position+=denom*temp;
            }
        }
        else{
            position++;
            currentt+=denom;
        }
    }
    cout << (int) round(currentt) << endl;
}
