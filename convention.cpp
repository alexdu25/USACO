#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin ("convention.in");
ofstream fout ("convention.out");
int a[100000],n,m,k;
bool possible(int maxwait){
    int original=0,last=0,bus=0;
    while(true){
        original=last;
        for(int j=original;j<original+k;j++){
            if(j<n){
                last=j+1;
                if(a[j]-a[original]>maxwait){
                    last=j;
                    break;
                }
            }
        }
        bus++;
        if(bus>m){
            return false;
        }
        if(last>=n){
            break;
        }
    }
    return true;
}
int binarysearch(int lower,int upper){
    while(lower!=upper){
        if(lower==upper-1){
            if(possible(lower)==true){
                return lower;
            }
            else{
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
    fin >> n >> m >> k;
    for(int i=0;i<n;i++){
        fin >> a[i];
    }
    fin.close();
    sort(a,a+n);
    fout << binarysearch(0,1000000000);
    fout.close();
}
